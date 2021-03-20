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

const ll MAXN=2505,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

struct MCMF { //0-base;
    struct edge {
        ll from, to, cap, cost, flow, rev;        
    }*past[MAXN];
    vector<edge> G[MAXN];
    bitset<MAXN> inq;
    ll dis[MAXN], up[MAXN], s, t, mx, n;
    int cnt = 0;
    bool SPFA(ll &flow,ll &cost) {
        fill(dis,dis+n,INF);
        queue<ll> q;
        q.emplace(s);
        dis[s] = 0;
        inq.reset();
        inq[s] = 1;
        up[s] = INF, past[s] = 0, dis[s] = 0;
        debug(up[s]);
        while (SZ(q)) {
            ll cur = q.front();
            q.pop();
            inq[cur] = 0;
            if (!up[cur]) continue;
            for (auto &e:G[cur]) {
                if (e.flow != e.cap && dis[e.to] > dis[cur] + e.cost) {
                    dis[e.to] = dis[cur] + e.cost;
                    past[e.to] = &e;
                    up[e.to] = min(up[cur],e.cap-e.flow);
                    debug(e.cap - e.flow);
                    if (!inq[e.to]) {
                        q.emplace(e.to);
                        inq[e.to] = 1;
                    }
                }
            }
        }
        if (dis[t] == INF) return 0;
        debug(up[t],dis[t]);
        flow += up[t], cost += up[t] * dis[t];
        for (ll i=t;past[i];i=past[i]->from) {
            auto &e = *past[i];
            debug(e.to,e.from);
            e.flow += up[t], G[e.to][e.rev].flow -= up[t];
        }
        return 1;
    }
    ll flow(ll _s,ll _t,ll &cost) {
        s = _s, t = _t, cost = 0;
        ll flow = 0;
        while (SPFA(flow,cost));
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
} graph;
int N,M;
char grid[MAXN][MAXN];
int id(int x,int y){
    return x * M + y;
}
int main(){
    IOS();
    cin >> N >> M;
    int k = 0;
    int s = N * M, t = N * M + 1;
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'o') {
                k++;
            }
        }
    }
    graph.init(N*M+2);
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) {
            if (grid[i][j] == '#') continue;
            graph.add_edge(id(i,j), t, 1, 0);
            if (grid[i][j] == 'o') {
                graph.add_edge(s, id(i,j), 1, 0);
            }
            if (i != N-1 && grid[i+1][j] != '#') {
                debug(i,j,'a');
                graph.add_edge(id(i,j), id(i+1,j), N*M, -1);
            }
            if (j != M-1 && grid[i][j+1] != '#') {
                debug(i,j);
                graph.add_edge(id(i,j), id(i,j+1), N*M, -1);
            }
        }
    }
    ll ans = 0;
    ll f = graph.flow(s,t,ans);
    for (int i=0;i<N*M+2;++i) {
        for (auto e:graph.G[i]) {
            debug(i,e.from,e.to,e.cap,e.cost,e.flow);
        }
    }
    debug(f);
    cout << -ans << endl;
}
