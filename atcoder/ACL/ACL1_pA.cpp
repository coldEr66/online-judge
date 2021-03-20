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
    fprintf(stderr,"LINE %d: (%s) = ",__LINE__,#__VA_ARGS__);\
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

int n;
ii d[MAXn];
int id[MAXn];
int ans[MAXn];
int seg[MAXn*2];
void build(){
    for (int i=n-1;i>0;i--) {
        seg[i] = max(seg[i<<1],seg[i<<1|1]);
    }
}
int qr(int l,int r){
    int ret = -1;
    for (l+=n,r+=n;l<r;l>>=1,r>>=1) {
        if (l&1) ret = max(ret,seg[l++]);
        if (r&1) ret = max(ret,seg[--r]);
    }
    return ret;
}
int main(){
    IOS();
    cin >> n;
    for (int i=0;i<n;++i) {
        cin >> d[i].X >> d[i].Y;
        d[i].X--, d[i].Y--;
        id[i] = i;
        seg[d[i].Y+n] = d[i].X;
    }
    build();
    sort(id,id+n,[&](const int a,const int b){
        return d[a].X < d[b].X;
    });
    for (int i=0;i<n;++i) {
        int idx = i;
        int cur = d[id[i]].Y;
        while (1) {
            int tmp = qr(cur,n);
            if (tmp < idx) break;
            for (int j=idx;j<=tmp;++j) {
                cur = min(cur,d[id[j]].Y);
            }
            idx = tmp+1;
        }
        debug(idx);
        for (int j=i;j<idx;++j) ans[id[j]] = idx-i;
        i = idx-1;
    }
    for (int i=0;i<n;++i) cout << ans[i] << endl;
}
