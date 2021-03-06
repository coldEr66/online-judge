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

const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll n;
vector<ll> e[MAXn];
ll c[MAXn];
ll dsu[MAXn],sz[MAXn];
ll id[MAXn];
bool vis[MAXn];
void init(){
    REP (i,n) {
        dsu[i] = i;
        sz[i] = 1;
        id[i] = i;
    }
}
ll fd(ll x){
    if (dsu[x] == x) return x;
    return dsu[x] = fd(dsu[x]);
}
void mrg(ll x,ll y){
    x = fd(x), y = fd(y);
    if (x == y) return;
    dsu[y] = x;
    sz[x] += sz[y];
}
int main(){
    IOS();
    cin >> n;
    REP (i,n) cin >> c[i];
    REP (i,n-1) {
        ll u,v;
        cin >> u >> v;
        u--, v--;
        e[u].eb(v);
        e[v].eb(u);
    }
    init();
    sort(id,id+n,[&](const ll a,const ll b){
        return c[a] < c[b];
    });
    pary(id,id+n);
    ll ans = 0;
    REP (i,n) {
        ll cur = id[i];
        for (auto it:e[cur]) if (vis[it]) {
            debug(c[cur] * sz[fd(cur)] * sz[fd(it)],c[cur],sz[fd(cur)],sz[fd(it)]);
            ans += c[cur] * sz[fd(cur)] * sz[fd(it)];
            mrg(cur,it);
        }
        vis[cur] = true;
    }
    init();
    sort(id,id+n,[&](const ll a, const ll b){
        return c[a] > c[b];
    });
    RST(vis,0);
    pary(id,id+n);
    REP (i,n) {
        ll cur = id[i];
        for (auto it:e[cur]) if (vis[it]) {
            debug(c[cur] * sz[fd(cur)] * sz[fd(it)],c[cur],sz[fd(cur)],sz[fd(it)]);
            ans -= c[cur] * sz[fd(cur)] * sz[fd(it)];
            mrg(cur,it);
        }
        vis[cur] = true;
    }
    cout << ans << endl;
}
