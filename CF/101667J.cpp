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
template<class T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }

const ll MAXn=5e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

struct Dinic {
    struct edge {
        int cap, rev, to;
    };

    edge gen(int c, int r, int t) {
        edge ret;
        ret.cap = c; ret.rev = r; ret.to = t;
        return ret;
    }

    // Change MAXN
    static const int MAXN = 2e5+5;
    int n, level[MAXN], ptr[MAXN];
    vector<edge> G[MAXN];

    void init(int _n) {
        n = _n;
        for (int i = 0; i <= n; ++i) G[i].clear();
    }

    void addedge(int u, int v, int cap) {
        G[u].push_back(gen(cap, G[v].size(), v));
        G[v].push_back(gen(0, G[u].size()-1, u));
    }

    bool BFS(int s, int t) {
        for (int i = 0; i <= n; ++i) level[i] = -1, ptr[i] = 0;
        int p;
        queue<int> myqu;
        level[s] = 0; myqu.push(s);
        while (!myqu.empty()) {
            p = myqu.front(); myqu.pop();
            for (auto x : G[p]) {
                if (x.cap > 0 && level[x.to] == -1) {
                    level[x.to] = level[p] + 1;
                    myqu.push(x.to);
                }
            }
        }
        return level[t] != -1;
    }

    int dfs(int s, int t, int f) {
        int tmp;
        if (s == t) return f;
        for (;ptr[s] < SZ(G[s]); ptr[s]++) {
            edge &x = G[s][ptr[s]];
            if (x.cap > 0 && level[x.to] > level[s]) {
                tmp = dfs(x.to, t, min(f, x.cap));
                if (tmp > 0) {
                    x.cap -= tmp;
                    G[x.to][x.rev].cap += tmp;
                    return tmp;
                }
            }
        }
        level[s] = -1;
        return -1;
    }

    int maxflow(int s, int t) {
        int ret = 0, tmp;
        while (1) {
            if (!BFS(s, t)) break;
            tmp = 0;
            do {
                ret += tmp;
                tmp = dfs(s, t, 1000000000);
            } while (tmp > 0);
        }
        return ret;
    }
} flow;

vector<pii> edge;
signed main(){
    IOS();
    int n,m;
    cin >> n >> m;
    for (int i=0;i<m;++i) {
        int u,v;
        cin >> u >> v;
        u--, v--;
        edge.eb(u,v);
    }
    bool ans = 0;
    for (int s=0;s<n;++s) {
        for (int t=s+1;t<n;++t) {
            flow.init(2*n);
            for (int i=0;i<m;++i) {
                int u = edge[i].X, v = edge[i].Y;
                flow.addedge(2*u+1,2*v,1000000);
                flow.addedge(2*v+1,2*u,1000000);
            }
            for (int i=0;i<n;++i) {
                if (i == s || i == t) continue;
                flow.addedge(2*i,2*i+1,1);
            }
            if (flow.maxflow(s*2+1,t*2) * 2 < n) {
                ans = 1;
                break;
            }
        }
    }
    if (ans) cout << -1 << endl;
    else cout << 1 << endl;
}
