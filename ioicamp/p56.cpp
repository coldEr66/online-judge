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

const ll MAXn=5e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;
const ll MAXm=1e3+5;

ll n,m;
vector<ii> e[MAXn],be[MAXm];
vector<ll> boy,girl;
ll dep[MAXn],anc[MAXn][MAXlg];
ll in[MAXn],out[MAXn],idx;
ll xp[MAXm],yp[MAXm];
bitset<MAXm> vis;
void dfs(ll x,ll p,ll d){
  in[x] = ++idx;
  dep[x] = d;
  anc[x][0] = p;
  for (ll i=1;(1<<i) < n;i++) {
    anc[x][i] = anc[anc[x][i-1]][i-1];
  }
  for (auto i:e[x]) {
    if (i.X == p) continue;
    dfs(i.X,x,d + i.Y);
  }
  out[x] = ++idx;
}
ll chk(ll x,ll y){
  return in[x] <= in[y] && out[x] >= out[y];
}
ll LCA(ll x,ll y){
  if (chk(x,y)) return x;
  if (chk(y,x)) return y;
  for (ll i=__lg(n);i>=0;i--) {
    if (!chk(anc[x][i],y)) x = anc[x][i];
  }
  return anc[x][0];
}
ll cal(ll x,ll y){
  ll lca = LCA(x,y);
  debug(x,y,lca);
  ll len = dep[x] + dep[y] - 2 * dep[lca];
  ll tmp = len/2;
  if (dep[x] < dep[y]) swap(x,y);
  ll tx = x;
  for (ll i=__lg(n)+1;i>=0;i--) {
    if (dep[x] - dep[anc[tx][i]] < tmp) {
      tx = anc[tx][i];
    }
  }
  debug(tx,x);
  ll d1 = dep[x] - dep[tx], d2 = dep[x] - dep[anc[tx][0]];
  debug(d1,d2,tmp);
  return min(max(d1,len-d1),max(d2,len-d2));
}
ll go(ll x,ll limit){
  for (auto i:be[x]) if (!vis[i.X] && i.Y <= limit) {
    vis[i.X] = true;
    if (yp[i.X] == -1 || go(yp[i.X],limit)) {
      xp[x] = i.X, yp[i.X] = x;
      return 1;
    }
  }
  return 0;
}
ll matching(ll x){
  ll ret = 0;
  RST(xp,-1);
  RST(yp,-1);
  REP (i,m) {
    if (xp[i] != -1) continue;
    for (auto it:be[i]) {
      if (yp[it.X] != -1) continue;
      if (it.Y > x) continue;
      xp[i] = it.X, yp[it.X] = i;
      ret++;
      break;
    }
  }
  debug(ret);
  REP (i,m) {
    vis.reset();
    if (xp[i] == -1) ret += go(i,x);
    // ret += go(i,x);
  }
  return ret;
}
int main(){
  IOS();
  cin >> n >> m;
  REP (i,n-1) {
    ll u,v,w;
    cin >> u >> v >> w;
    u--, v--;
    e[u].eb(v,w);
    e[v].eb(u,w);
  }
  REP (i,2*m) {
    ll x;
    cin >> x;
    x--;
    if (i < m) boy.eb(x);
    else girl.eb(x);
  }
  assert(SZ(boy) == SZ(girl));
  dfs(0,0,0);
  REP (i,m) REP (j,m) {
    ll b = boy[i], g = girl[j];
    ll tmp = cal(b,g);
    be[i].eb(j,tmp);
  }
  pary(be,be+m);
  ll l=0,r=1e16+2;
  while (l != r-1) {
    ll mid = (l+r)>>1;
    ll tmp = matching(mid);
    debug(mid,tmp);
    assert(tmp <= m);
    if (tmp == m) r = mid;
    else l = mid;
  }
  debug(l,r);
  cout << r*2 << endl;
}

/*
1 3 3
1 4 5
1 2 2
3 8 13
8 9 16
9 10 18
9 11 24
2 5 8
5 6 15
5 7 9
*/
