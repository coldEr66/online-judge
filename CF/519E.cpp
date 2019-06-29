#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define RST(a,i) memset(a,i,sizeof a)
#define SZ(a) ll(a.size())
#define X first
#define Y second
#define eb emplace_back
#define pob pop_back
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T> void _do(T &&_x){cerr << _x << endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr << _x << ", ";_do(_t...);}
#define IOS()
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(...)
#endif

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;

ll anc[MAXn][MAXlg],in[MAXn],out[MAXn],dep[MAXn],sz[MAXn];
ll n,t;
vector<ll> e[MAXn];
map<ll,ll> dp[MAXn];
void dfs(ll x,ll p,ll d){
    sz[x] = 1;
    dep[x] = d;
    anc[x][0] = p;
    in[x] = ++t;
    for (ll i=1;(1<<i) < n;i++) {
        anc[x][i] = anc[anc[x][i-1]][i-1];
    }

    for (auto i:e[x]) {
        if (i == p) continue;
        dfs(i,x,d+1);
        sz[x] += sz[i];
        dp[x][i] = sz[i];
    }
    dp[x][p] = n - sz[x];
    debug(dp[x][p],x);
    out[x] = ++t;
}
bool chk(ll x,ll y){
    return in[x] <= in[y] && out[x] >= out[y];
}
ll LCA(ll x,ll y){
    if (chk(x,y)) return x;
    if (chk(y,x)) return y;

    for (ll i=__lg(n)+1;i>=0;i--) {
        if (!chk(anc[x][i],y)) x = anc[x][i];
    }
    // debug(x);
    return anc[x][0];
}
ll cal(ll x,ll y){
    ll lca = LCA(x,y);
    ll len = dep[x] + dep[y] - 2*dep[lca];
    debug(lca,len);
    if (len&1) return 0;

    ll tmp = len/2;
    if (dep[x] < dep[y]) swap(x,y);
    ll cur = x;
    for (ll i=__lg(n)+1;i>=0;i--) {
        if (dep[cur] - dep[anc[cur][i]] <= tmp) {
            debug(cur,tmp);
            tmp -= (dep[cur] - dep[anc[cur][i]]);
            cur = anc[cur][i];
        }
    }
    debug(tmp);
    ll cur1 = x;
    tmp = len/2;
    for (ll i=__lg(n)+1;i>=0;i--) {
        if (dep[cur1] - dep[anc[cur1][i]] <= tmp-1) {
            debug(cur1,tmp);
            tmp -= (dep[cur1] - dep[anc[cur1][i]]);
            cur1 = anc[cur1][i];
        }
    }
    ll cur2 = y;
    tmp = len/2;
    if (cur != lca) cur2 = anc[cur][0];
    else {
        for (ll i=__lg(n)+1;i>=0;i--) {
            if (dep[cur2] - dep[anc[cur2][i]] <= tmp-1) {
                debug(cur2,tmp);
                tmp -= (dep[cur2] - dep[anc[cur2][i]]);
                cur2 = anc[cur2][i];
            }
        }
    }
    debug(cur,cur1,cur2);
    ll ret = n - dp[cur][cur1] - dp[cur][cur2];
    return ret;
}
int main(){
    IOS();
    cin >> n;
    REP (i,n-1) {
        ll u,v;
        cin >> u >> v;
        u--,v--;
        e[u].eb(v);
        e[v].eb(u);
    }

    dfs(0,0,0);
    // REP (i,n) REP (j,MAXlg) debug(anc[i][j],i);
    // REP (i,n) debug(dep[i]);
    ll q;
    cin >> q;
    while (q--) {
        ll u,v;
        cin >> u >> v;
        u--,v--;
        cout << cal(u,v) << endl;
    }
}
