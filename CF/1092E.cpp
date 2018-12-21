#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (int)a.size()
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

const ll MAXn=1e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

vector<ll> e[MAXn],root,graph;
vector<ii> ans;
bitset<MAXn> vis;
ll dia,go,gogo;
void dfs1 (ll x,ll p,ll dep) {
  if (dia <= dep) go = x, dia = dep;
  for (auto i:e[x]) {
    if (i == p) continue;
    dfs1(i,x,dep+1);
  }
}
bool dfs2 (ll x,ll p) {
  root.eb(x);
  if (x == gogo) return true;
  for (auto i:e[x]) {
    if (i == p) continue;
    if (dfs2(i,x)) return true;
  }
  root.pob();
  return false;
}
void dfs3 (ll x,ll p) {
  vis[x] = true;
  for (auto i:e[x]) {
    if (i == p) continue;
    dfs3(i,x);
  }
}
int main(){
  IOS();
  ll n,m;
  cin >> n >> m;
  REP (i,m) {
    ll u,v;
    cin >> u >> v;
    u--,v--;
    e[u].eb(v);
    e[v].eb(u);
  }

  if (m == n-1) {
    dfs1(0,0,0);
    dia = 0;
    dfs1(go,go,0);
    cout << dia << endl;
    return 0;
  }
  REP (i,n) if (!vis[i]) {
    graph.eb(i);
    dfs3(i,i);
  }
  debug(graph);
  REP (i,SZ(graph)) {
    ll cur = graph[i];
    dia = 0;
    root.clear();
    dfs1(cur,cur,0);
    dia = 0;
    gogo = go;
    dfs1(go,go,0);
    dfs2(go,go);
    debug(root);
    ans.eb(SZ(root)/2,root[SZ(root)/2]);
  }
  sort(ALL(ans));
  debug(ans);
  REP (i,SZ(ans)-1) {
    e[ans[i].Y].eb(ans.back().Y);
    e[ans.back().Y].eb(ans[i].Y);
  }
  dia = 0;
  dfs1(0,0,0);
  debug(go);
  dia = 0;
  dfs1(go,go,0);
  cout << dia << endl;
  REP (i,SZ(ans)-1) cout << ans[i].Y+1 << ' ' << ans.back().Y+1 << endl;
}
