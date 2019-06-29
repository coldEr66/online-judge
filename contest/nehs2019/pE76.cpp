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

ll n,k,T;
ll in[MAXn],out[MAXn],dep[MAXn],dp[MAXn];
vector<ii> e[MAXn];
void dfs(ll x,ll d){
  in[x] = ++T;
  dep[x] = d;
  dp[x] = (SZ(e[x]) == 0);
  for (auto i:e[x]) {
    if (dp[i.X] == -1) dfs(i.X,d + i.Y);
    dp[x] += dp[i.X];
  }
  out[x] = ++T;
}
bool chk(ll x,ll y){
  return in[x] < in[y] && out[x] > out[y];
}
ll cal(ll x,ll y){
  if (chk(x,y) || chk(y,x)) {
    if (dep[x] > dep[y]) swap(x,y);
    return dep[x]*(dp[x]-1) + (dp[y]-1)*(dep[y] - dep[x]);
  }
  else {
    return (dp[x]-1) * dep[x] + (dp[y]-1) * dep[y];
  }
}
int main(){
  IOS();
  cin >> n >> k;
  RST(dp,-1);
  REP (i,n) {
    ll m,x;
    cin >> m;
    vector<ll> s,t;
    REP (j,m) {
      cin >> x;
      x--;
      s.eb(x);
    }
    REP (j,m) {
      cin >> x;
      t.eb(x);
    }
    REP (j,m) e[i].eb(s[j],t[j]);
  }

  pary(e,e+n);
  dfs(0,0);
  ll tmp = 0;
  pary(dp,dp+n);
  pary(dep,dep+n);
  REP (i,n) if (!SZ(e[i])) tmp += dep[i];
  ll ans = tmp;
  if (k == 2) {
    REP (i,n) for (ll j=i+1;j<n;j++) ans = min(ans,tmp - cal(i,j));
    cout << ans << endl;
  }
  else if (k == 1){
    REP (i,n) ans = min(ans,tmp - (dp[i]-1)*dep[i]);
    cout << ans << endl;
  }
  else cout << ans << endl;
}
