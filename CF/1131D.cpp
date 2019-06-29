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

const ll MAXn=2e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll n,m,tt;
ll dsu[MAXn],sz[MAXn];
char d[MAXn][MAXn];
ll dp[MAXn],in[MAXn];
vector<ll> e[MAXn],tp;
ll ans[MAXn];
ll fd(ll x){
  if (x == dsu[x]) return x;
  return dsu[x] = fd(dsu[x]);
}
void mrg(ll x,ll y){
  x = fd(x), y = fd(y);
  if (x == y) return;
  tt--;
  if (sz[x] < sz[y]) swap(x,y);
  dsu[y] = x;
  sz[x] += sz[y];
}
bool chk(){
  queue<ll> q;
  REP (i,n+m) if (i == fd(i)) {
    if (!in[fd(i)]) q.push(fd(i));
  }
  while (SZ(q)) {
    ll cur = q.front();
    q.pop();
    tp.eb(cur);
    for (auto i:e[cur]) {
      if (--in[i] == 0) q.push(i);
    }
  }
  if (SZ(tp) != tt) return true;
  return false;
}
int main(){
  IOS();
  cin >> n >> m;
  REP (i,n) dsu[i] = i,sz[i] = 1;
  tt = n+m;
  REP (i,m) dsu[i+n] = i+n,sz[i] = 1;
  REP (i,n) REP (j,m) cin >> d[i][j];
  REP (i,n) REP (j,m) if (d[i][j] == '=') mrg(i,j+n);

  REP (i,n) REP (j,m) {
    if (d[i][j] == '=') continue;
    if (d[i][j] == '>') {
      e[fd(i)].eb(fd(j+n));
      in[fd(j+n)]++;
    }
    else {
      e[fd(j+n)].eb(fd(i));
      in[fd(i)]++;
    }
  }

  REP (i,n+m) debug(e[i]);
  if (chk()) return cout << "No" << endl,0;
  for (ll i=SZ(tp)-1;i>=0;i--) {
    dp[tp[i]] = 1;
    for (auto j:e[tp[i]]) {
      dp[tp[i]] = max(dp[tp[i]],dp[j]+1);
    }
  }

  cout << "Yes" << endl;
  REP (i,n) cout << dp[fd(i)] << " \n"[i==n-1];
  REP (i,m) cout << dp[fd(i+n)] << " \n"[i==m-1];
}
