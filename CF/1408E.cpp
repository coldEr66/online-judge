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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

struct edg{
    ll u,v,w;
    bool operator < (const edg &a) const {
        return w > a.w;
    }
};
ll a[MAXn],b[MAXn];
vector<int> st[MAXn];
ll sumb[MAXn];
int dsu[MAXn],sz[MAXn];
vector<edg> edge;
bool col[MAXn];
int fnd(int x){
    if (x == dsu[x]) return x;
    return dsu[x] = fnd(dsu[x]);
}
void mrg(int x,int y){
    x = fnd(x), y = fnd(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x,y);
    dsu[y] = x;
    sz[x] += sz[y];
}
int main(){
    IOS();
    ll m,n;
    cin >> m >> n;
    ll A = 0;
    for (int i=0;i<m;++i) {
        cin >> a[i];
        A += a[i];
    }
    for (int i=0;i<n;++i) {
        cin >> b[i];
    }
    ll tt = 0;
    ll ans = INF;
    for (int i=0;i<m;++i) {
        ll Sz;
        cin >> Sz;
        while (Sz--) {
            ll x;
            cin >> x;
            x--;
            st[i].eb(x);
            sumb[i] += b[x];
        }
        sort(ALL(st[i]),[&](const int &x,const int &y){
            return b[x] > b[y];
        });
        tt += a[i] * SZ(st[i]) + sumb[i];
    }
    debug(tt);
    for (int i=0;i<m;++i) {
        ans = min(ans,tt - a[i] * SZ(st[i]) - sumb[i]);
    }
    debug(ans);
    ll cur = 0;
    for (int i=0;i<m;++i) {
        if (SZ(st[i]) > 1) {
            cur += b[st[i][0]] + b[st[i][1]];
            cur += 2 * a[i];
        }
    }
    ans = min(ans,tt - cur);
    cout << ans << endl;
}
