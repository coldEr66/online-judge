#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RST(i,n) memset(i,n,sizeof i)
#define ALL(a) a.begin(),a.end()
#define X first
#define Y second
#define mkp make_pair
#define pb push_back
#define eb emplace_back
#define pob pop_back
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
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
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

const ll MAXn=4e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

struct Dinic{
  static const ll MXN = 10000;
  struct Edge{ ll v,f,re; };
  ll n,s,t,level[MXN];
  vector<Edge> E[MXN];
  void init(ll _n, ll _s, ll _t){
    n = _n; s = _s; t = _t;
    for (ll i=0; i<n; i++) E[i].clear();
  }
#define PB push_back
#define SZ(x) ((ll)x.size())
  void add_edge(ll u, ll v, ll f){
    E[u].PB({v,f,SZ(E[v])});
    E[v].PB({u,0,SZ(E[u])-1});
  }
  bool BFS(){
    for (ll i=0; i<n; i++) level[i] = -1;
    queue<ll> que;
    que.push(s);
    level[s] = 0;
    while (!que.empty()){
      ll u = que.front(); que.pop();
      for (auto it : E[u]){
        if (it.f > 0 && level[it.v] == -1){
          level[it.v] = level[u]+1;
          que.push(it.v);
        }
      }
    }
    return level[t] != -1;
  }
  ll DFS(ll u, ll nf){
    if (u == t) return nf;
    ll res = 0;
    for (auto &it : E[u]){
      if (it.f > 0 && level[it.v] == level[u]+1){
        ll tf = DFS(it.v, min(nf,it.f));
        res += tf; nf -= tf; it.f -= tf;
        E[it.v][it.re].f += tf;
        if (nf == 0) return res;
      }
    }
    if (!res) level[u] = -1;
    return res;
  }
  ll flow(ll res=0){
    while ( BFS() )
      res += DFS(s,2147483647);
    return res;
  }
} flow;
ll n,m;
vector<ll> ans;
ll c[MAXn];
bitset<MAXn> vis;
void cut(ll s){
  vis[s] = true;
  for (auto i:flow.E[s]) {
    if (i.f == 0) continue;
    if (vis[i.v]) continue;
    cut(i.v);
  }
}
int main(){
  IOS();
  ll t;
  cin >> t;
  while (t--) {
    vis.reset();
    cin >> n >> m;
    flow.init(n+m+2,0,n+m+1);
    REP1 (i,n) {
      cin >> c[i];
      flow.add_edge(i+m,n+m+1,c[i]);
    }

    ll tt = 0;
    REP1 (i,m) {
      ll nn,p;
      cin >> nn >> p;
      tt += p;
      flow.add_edge(0,i,p);
      while (nn--) {
        ll id;
        cin >> id;
        flow.add_edge(i,id+m,INF);
      }
    }
    ll tmp = flow.flow();
    cout << tt-tmp << endl;
    assert(tt-tmp >= 0);

    ans.clear();
    cut(0);
    REP1 (i,n) if (vis[i+m]) ans.eb(i);
    cout << SZ(ans) << endl;
    REP (i,SZ(ans)) {
      if (!i) cout << ans[i];
      else cout << " " << ans[i];
    }
    cout << endl;
  }
}
