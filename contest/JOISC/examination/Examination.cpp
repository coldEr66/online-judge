#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define X first
#define Y second
#define eb emplace_back
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"LIND %d: (%s) = ",__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<", ";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
template<typename It> ostream& _OUTC(ostream &_s,It _ita,It _itb)
{
    _s<<"{";
    for(It _it=_ita;_it!=_itb;_it++)
    {
        _s<<(_it==_ita?"":",")<<*_it;
    }
    _s<<"}";
    return _s;
}
template<typename _a> ostream &operator << (ostream &_s,vector<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#define IOS()
#else
#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // cold66
//}
template<class T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

struct query{
    int x,y,z,id;
} tmpdt[MAXn];
bool cmp(const query &a,const query &b){
    if (a.x != b.x) return a.x > b.x;
    if (a.y != b.y) return a.y > b.y;
    if (a.z != b.z) return a.z > b.z;
    return a.id < b.id;
}
vector<query> dt;
int ans[MAXn],bit[MAXn];
vector<int> rk;
int lowbit(int x){return x&(-x);}
void ins(int x,int v){
    for (;x>0;x-=lowbit(x)) bit[x] += v;
}
int qr(int x){
    int ret = 0;
    for (;x<MAXn;x+=lowbit(x)) ret += bit[x];
    return ret;
}
int GTPOS(int x){
    return int(lower_bound(ALL(rk),x) - rk.begin() + 1);
}
void CDQ(int l,int r){
    // debug(l,r);
    if (l == r-1) return;
    int mid = (l+r)>>1;
    CDQ(l,mid), CDQ(mid,r);
    int tl = l, tr = mid;
    int idx = 0;
    vector<int> op;
    while (tl < mid && tr < r) {
        if (dt[tl].y >= dt[tr].y) {
            if (dt[tl].id == -1) {
                ins(dt[tl].z,1);
                op.eb(dt[tl].z);
            }
            tmpdt[idx++] = dt[tl++];
        }
        else {
            if (dt[tr].id != -1) {
                ans[dt[tr].id] += qr(dt[tr].z);
            }
            tmpdt[idx++] = dt[tr++];
        }
    }
    while (tl < mid) {
        tmpdt[idx++] = dt[tl++];
    }
    while (tr < r) {
        if (dt[tr].id != -1){
            ans[dt[tr].id] += qr(dt[tr].z);
        }
        tmpdt[idx++] = dt[tr++];
    }
    for (int i=l;i<r;i++) {
        dt[i] = tmpdt[i-l];
    }
    for (auto i:op) ins(i,-1);
}
int main(){
    IOS();
    int n,q;
    cin >> n >> q;
    REP (i,n) {
        int s,t;
        cin >> s >> t;
        rk.eb(s+t);
        query tmp = (query){s,t,s+t,-1};
        dt.eb(tmp);
    }
    REP (i,q) {
        int x,y,z;
        cin >> x >> y >> z;
        rk.eb(z);
        query tmp = (query){x,y,z,i};
        dt.eb(tmp);
    }
    sort(ALL(rk));
    rk.resize(unique(ALL(rk))-rk.begin());
    sort(ALL(dt),cmp);
    REP (i,SZ(dt)) {
        dt[i].z = GTPOS(dt[i].z);
    }
    REP (i,SZ(dt)) debug(dt[i].x,dt[i].y,dt[i].z,dt[i].id);
    CDQ(0,SZ(dt));
    REP (i,q) cout << ans[i] << endl;
}
