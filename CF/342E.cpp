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
const ll INF=0x3f3f3f3f3f3f3f3f;

ll n,q;
vector<ll> e[MAXn],tmp;
ll dis[MAXn][MAXlg];
ll fa[MAXn];
ll dp[MAXn],dep[MAXn];
ll sz[MAXn],ma[MAXn];
void dfs(ll x,ll p){
  sz[x] = 1, ma[x] = 0;
  tmp.eb(x);
  for (auto i:e[x]) {
    if (i == p || fa[i]) continue;
    dfs(i,x);
    sz[x] += sz[i];
    ma[x] = max(ma[x],sz[i]);
  }
}
void gtdis(ll x,ll p,ll d,ll lev){
  debug(x,d,lev);
  dis[x][lev] = d;
  for (auto i:e[x]) {
    if (i == p || fa[i]) continue;
    gtdis(i,x,d+1,lev);
  }
}
void gtctrl(ll x,ll p){
  tmp.clear();
  tmp.shrink_to_fit();
  dfs(x,p);
  debug(tmp);
  ll ret = 0;
  for (auto i:tmp) {
    debug(i,sz[i],ma[i]);
    if (max(SZ(tmp)-sz[i],ma[i]) <= SZ(tmp)/2) {
      ret = i;
    }
  }
  if (p == 0) {
    fa[ret] = ret;
    dep[ret] = 0;
  }
  else {
    fa[ret] = p;
    dep[ret] = dep[p]+1;
  }
  gtdis(ret,fa[ret],0,dep[ret]);
  debug(ret,p);
  if (SZ(tmp) == 1) return;
  for (auto i:e[ret]) {
    if (i == p || fa[i]) continue;
    gtctrl(i,ret);
  }
}
void build(){
  dep[0] = -1;
  gtctrl(1,0);
}
void ins(ll x){
  ll cur = x;
  while (1) {
    dp[cur] = min(dp[cur],dis[x][dep[cur]]);
    debug(cur,dp[cur]);
    if (cur == fa[cur]) break;
    cur = fa[cur];
  }
}
ll qr(ll x){
  ll ret = INF;
  ll cur = x;
  while (1) {
    debug(cur);
    ret = min(ret,dp[cur] + dis[x][dep[cur]]);
    if (cur == fa[cur]) break;
    cur = fa[cur];
  }
  return ret;
}
int main(){
  IOS();
  cin >> n >> q;
  REP (i,n-1) {
    ll u,v;
    cin >> u >> v;
    e[u].eb(v);
    e[v].eb(u);
  }
  REP1 (i,n) dp[i] = INF;
  build();
  pary(fa+1,fa+n+1);
  ins(1);
  while (q--) {
    ll cmd,x;
    cin >> cmd >> x;
    if (cmd == 1) ins(x);
    else cout << qr(x) << endl;
  }
}
