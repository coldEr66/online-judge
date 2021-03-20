#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
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

const ll MAXN=5e5+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

ll dp[MAXN];
struct MCMF { //0-base;
    struct edge {
        ll from, to, cap, cost, flow, rev;        
    }*past[MAXN];
    vector<edge> G[MAXN];
    bitset<MAXN> inq;
    ll dis[MAXN], up[MAXN], s, t, n;
    bool dij(ll &flow,ll &cost) {
        fill(dis,dis+n,INF);
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.emplace(0,s);
        dis[s] = 0;
        up[s] = INF, past[s] = 0, dis[s] = 0;
        while (SZ(pq)) {
            ll cur = pq.top().Y, w = pq.top().X;
            pq.pop();
            if (dis[cur] != w) continue;
            if (!up[cur]) continue;
            for (auto &e:G[cur]) {
                ll nxt = e.cost + dp[cur] - dp[e.to];
                if (e.flow != e.cap && dis[e.to] > w + nxt) {
                    dis[e.to] = w + nxt;
                    past[e.to] = &e;
                    up[e.to] = min(up[cur],e.cap - e.flow);
                    pq.emplace(dis[e.to],e.to);
                }
            }
        }
        if (dis[t] == INF) return 0;
        for (int i=0;i<MAXN;++i) {
            dp[i] = min(dp[i] + dis[i],INF);
        }
        flow += up[t];
        for (ll i=t;past[i];i=past[i]->from) {
            auto &e = *past[i];
            e.flow += up[t], G[e.to][e.rev].flow -= up[t];
            cost += up[t] * e.cost;
        }
        return 1;
    }
    ll flow(ll _s,ll _t,ll &cost) {
        s = _s, t = _t, cost = 0;
        ll flow = 0;
        while (dij(flow,cost));
        return flow;
    }
    void init(ll _n) {
        n = _n;
        for (int i=0;i<n;++i) {
            G[i].clear();
        }
    }
    void add_edge(ll a,ll b,ll cap,ll cost) {
        G[a].push_back(edge{a,b,cap,cost,0,SZ(G[b])});
        G[b].push_back(edge{b,a,0,-cost,0,SZ(G[a])-1});
    }
} mcmf;

vector<pll> e[MAXN];
signed main(){
    IOS();
    int n;
    cin >> n;
    fill(dp,dp+MAXN,INF);
    for (int i=0;i<n;++i) {
        ll u,v,w;
        cin >> u >> v >> w;
        e[v].eb(u-1,-w);
    }
    dp[0] = 0;
    for (int i=1;i<MAXN;++i) {
        dp[i] = dp[i-1];
        for (auto it:e[i]) {
            ll to = it.X, w = it.Y;
            dp[i] = min(dp[i],dp[to] + w);
        }
    }
    mcmf.init(MAXN);
    for (int i=0;i<MAXN;++i) {
        for (auto it:e[i]) {
            ll from = it.X, w = it.Y;
            mcmf.add_edge(from,i,1,w);
        }
    }
    for (int i=1;i<MAXN;++i) {
        mcmf.add_edge(i-1,i,2,0);
    }
    ll cost;
    mcmf.flow(0,MAXN-1,cost);
    cout << -cost << endl;
}
