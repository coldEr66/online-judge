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

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

struct edge{
  ll u,v;
};
vector<edge> E;
vector<ll> e[MAXn],f;
ll vis[MAXn],dsu[MAXn],sz[MAXn];
bitset<MAXn> ok;
vector<ii> ans;
ll fd(ll x){
  if (x == dsu[x]) return x;
  return dsu[x] = fd(dsu[x]);
}
bool mrg(ll x,ll y){
  x = fd(x), y = fd(y);
  if (x == y) return false;
  if (sz[x] < sz[y]) swap(x,y);
  dsu[y] = x;
  sz[x] += sz[y];
  return true;
}
void dfs(ll x,ll cnt){
  vis[x] = cnt;
  for (auto i:e[x]) {
    if (vis[i]) continue;
    dfs(i,cnt);
  }
}
int main(){
  IOS();
  ll n,m,d;
  cin >> n >> m >> d;
  REP (i,n) dsu[i] = i,sz[i] = 1;
  REP (i,m) {
    ll u,v;
    cin >> u >> v;
    u--, v--;
    if (u != 0 && v != 0) {
      e[u].eb(v);
      e[v].eb(u);
      E.pb((edge){u,v});
    }
    else {
      if (u == 0) f.eb(v);
      if (v == 0) f.eb(u);
    }
  }

  debug(f);
  ll cnt = 0;
  REP1 (i,n-1) if (!vis[i]) dfs(i,++cnt);
  debug(cnt);
  pary(vis,vis+n);
  if (cnt > d || SZ(f) < d) return cout << "NO" << endl,0;

  REP (i,SZ(f)) {
    if (!d) break;
    if (!ok[vis[f[i]]]) {
      d--;
      mrg(0,f[i]);
      ans.eb(0,f[i]);
      ok[vis[f[i]]] = true;
    }
  }
  debug(d);
  REP (i,SZ(f)) {
    if (!d) break;
    if (mrg(0,f[i])) {
      ans.eb(0,f[i]);
      d--;
    }
  }
  REP (i,SZ(E)) {
    edge tp = E[i];
    if (mrg(tp.u,tp.v)) ans.eb(tp.u,tp.v);
  }
  if (SZ(ans) == n-1) {
    cout << "YES" << endl;
    REP (i,SZ(ans)) {
      cout << ans[i].X+1 << ' ' << ans[i].Y+1 << endl;
    }
  }
  else cout << "NO" << endl;
}
