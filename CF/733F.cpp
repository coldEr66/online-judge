#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
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
const ll INF=0x3f3f3f3f3f3f3f3f;

struct edg{
    ll u,v,w,c,id;
    // bool operator < (const edg &a) const {
    //     return w < a.w;
    // }
};
edg E[MAXn];
vector<ii> e[MAXn];
ll w[MAXn],c[MAXn];
ll dsu[MAXn],sz[MAXn];
ll anc[MAXn][MAXlg],ancw[MAXn][MAXlg];
ll dep[MAXn];
bool ok[MAXn];
ll fd(ll x){
    if (dsu[x] == x) return x;
    return dsu[x] = fd(dsu[x]);
}
void mrg(ll x,ll y){
    x = fd(x), y = fd(y);
    if (sz[x] < sz[y]) swap(x,y);
    dsu[y] = x;
    sz[x] += sz[y];
}
void dfs(ll x,ll p,ll W){
    anc[x][0] = p, ancw[x][0] = W;
    dep[x] = dep[p] + 1;
    for (ll i=1;1<<i < MAXn;i++) {
        anc[x][i] =  anc[anc[x][i-1]][i-1];
        ancw[x][i] = max(ancw[x][i-1],ancw[anc[x][i-1]][i-1]);
    }

    for (auto i:e[x]) {
        ll to = i.X, tmpw = i.Y;
        if (to == p) continue;
        dfs(to,x,tmpw);
    }
}
ll LCA(ll x,ll y){
    ll ret = 0;
    if (dep[x] < dep[y]) swap(x,y);
    for (ll i=MAXlg-1;i>=0;i--) {
        if (((dep[x] - dep[y])>>i)&1) {
            ret = max(ret,ancw[x][i]);
            x = anc[x][i];
        }
    }
    if (x == y) return ret;
    for (ll i=MAXlg-1;i>=0;i--) {
        if (anc[x][i] != anc[y][i]) {
            ret = max(ret,ancw[x][i]);
            ret = max(ret,ancw[y][i]);
            x = anc[x][i];
            y = anc[y][i];
        }
    }
    ret = max(ret,ancw[x][0]);
    ret = max(ret,ancw[y][0]);
    return ret;
}
int main(){
    IOS();
    ll n,m;
    cin >> n >> m;
    REP (i,n) {
        dsu[i] = i, sz[i] = 1;
    }
    REP (i,m) cin >> w[i];
    REP (i,m) cin >> c[i];
    REP (i,m) {
        ll u,v;
        cin >> u >> v;
        u--, v--;
        E[i].u = u;
        E[i].v = v;
        E[i].w = w[i];
        E[i].c = c[i];
        E[i].id = i;
     }
     ll S;
     cin >> S;

     sort(E,E+m,[&](const edg a,const edg b){
         return a.w < b.w;
     });
     ll ans = 0;
     ll C = INF;
     ll bst = -1;
     REP (i,m) {
         ll u = E[i].u, v = E[i].v;
         ll W = E[i].w, id = E[i].id;
         if (fd(u) == fd(v)) continue;
         debug(u,v,W,id);
         ok[i] = true;
         debug(E[i].c);
         if (C > E[i].c) {
             C = E[i].c;
             bst = i;
         }
         ans += W;
         mrg(u,v);
         e[u].eb(v,W);
         e[v].eb(u,W);
     }
     dfs(0,0,0);
     ll tmp = ans;
     ans -= S / C;
     REP (i,m) {
         if (ok[i]) continue;
         ll u = E[i].u, v = E[i].v;
         ll lcaw = LCA(u,v);
         tmp -= lcaw;
         tmp += E[i].w;
         tmp -= S / E[i].c;

         if (tmp < ans) {
             bst = i;
             ans = tmp;
         }
         tmp += lcaw;
         tmp -= E[i].w;
         tmp += S / E[i].c;
     }
     REP (i,n) {
         dsu[i] = i, sz[i] = 1;
     }
     vector<ll> ansv;
     debug(bst);
     ansv.eb(E[bst].id);
     mrg(E[bst].u,E[bst].v);
     w[E[bst].id] -= S / E[bst].c;
     REP (i,m) {
         ll u = E[i].u, v = E[i].v;
         ll id = E[i].id;
         if (fd(u) == fd(v)) continue;
         ok[i] = true;
         mrg(u,v);
         ansv.eb(id);
     }
     cout << ans << endl;
     REP (i,SZ(ansv)) {
         cout << ansv[i] + 1 << ' ' << w[ansv[i]] << endl;
     }
}
