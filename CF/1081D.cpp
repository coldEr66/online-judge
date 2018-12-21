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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

struct edge{
  ll u,v,w;
  bool operator < (const edge &tmp) const {
    return w < tmp.w;
  }
};
vector<edge> E;
ll n,m,k,root;
bool d[MAXn];
vector<ii> e[MAXn];
ll fa[MAXn],sz[MAXn];
ll ans;
ll fd(ll x){return (fa[x] == x ?x:fd(fa[x]));}
void uni(ll x,ll y){
  if (sz[x] < sz[y]) swap(x,y);
  fa[y] = x;
  sz[x] += sz[y];
}
void init(){
  root = -1;
  REP (i,n) fa[i] = i,sz[i] = 1;
}
bool dfs(ll x,ll p){
  bool ret = false;
  for (auto i:e[x]) {
    if (i.X == p) continue;
    bool tmp = dfs(i.X,x);
    ret |= tmp;
    if (tmp) chkmax(ans,i.Y);
  }
  ret |= d[x];
  return ret;
}
int main(){
  IOS();
  cin >> n >> m >> k;
  init();
  REP (i,k) {
    ll x;
    cin >> x;
    x--;
    if (root == -1) root = x;
    d[x] = true;
  }
  REP (i,m) {
    ll u,v,w;
    cin >> u >> v >> w;
    u--,v--;
    E.eb(edge{u,v,w});
  }
  sort(ALL(E));

  REP (i,SZ(E)) {
    ll u = E[i].u, v = E[i].v, w = E[i].w;
    debug(u,v,w);
    ll tu = fd(u), tv = fd(v);
    debug(tu,tv);
    if (tu == tv) continue;
    e[u].eb(v,w);
    e[v].eb(u,w);
    uni(tu,tv);
  }
  REP (i,n) debug(e[i]);
  dfs(root,root);

  REP (i,k) cout << ans << " \n"[i==k-1];
}
