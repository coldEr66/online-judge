#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=0;i<n;i++)
#define RST(i,n) memset(i,n,sizeof i)
#define ALL(a) a.begin(),a.end()
#define SZ(a) (int)a.size()
#define X first
#define Y second
#define eb emplace_back
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T> void _do(T && _x){cerr << _x << endl;}
template<typename T,typename ...S> void _do(T &&_x,S && ..._t){cerr << _x << ", ";_do(_t...);}
#define IOS()
#else
#define debug(...)
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#endif

const ll MAXn=1e5+5;
struct edge{
    ll u,v,w;
    bool operator < (const edge &a) const {
        return w < a.w;
    }
};
vector<edge> E;
ll dsu[MAXn],sz[MAXn];
ll fnd(ll x) {
    if (x == dsu[x]) return x;
    return dsu[x] = fnd(dsu[x]);
}
void mrg(ll x,ll y){
    x = fnd(x), y = fnd(y);
    if (sz[x] < sz[y]) swap(x,y);
    dsu[y] = x;
    sz[x] += sz[y];
}
int main(){
    IOS();
    ll n,m;
    cin >> n >> m;
    REP (i,n) {
        dsu[i] = i;
        sz[i] = 1;
    }
    ll sum = 0;
    REP (i,m) {
        ll u,v;
        cin >> u >> v;
        ll w;
        cin >> w;
        E.eb((edge){u,v,w});
        sum += w;
    }
    sort(ALL(E));
    for (ll i=m-1;i>=0;i--) {
        ll u = E[i].u, v = E[i].v, w = E[i].w;
        debug(u,v,w);
        if (fnd(u) == fnd(v)) continue;
        mrg(u,v);
        sum -= w;
    }
    cout << sum << endl;
}
