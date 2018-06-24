#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,j,n,m) for(int i=j;i<n;i+=m)
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define pob pop_back
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.F<<","<<_p.S<<")";}
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
const ll INF=(ll)1e18;

ll n,m;
ll f[MAXn];
ll sz[MAXn];
vector<ll> g[MAXn];
ll fd(ll x){return f[x] = (x==f[x] ?x:fd(f[x]));}
ll id(ll i,ll j){return i*m + j;}
void mer(ll x,ll y){
  if(sz[x = fd(x)] < sz[y = fd(y)]) swap(x,y);
  f[y] = x;
  sz[x]+=sz[y];
}
ll dp[MAXn];
void dfs(ll cur){
  dp[cur] = 1;
  for(auto it:g[cur]){
    if(dp[it]==-1) dfs(it);
    chkmax(dp[cur],dp[it] + 1);
  }
}
int main(){
  IOS();
  //debug(123);
  cin>>n>>m;
  ll d[n+5][m+5];
  RST(dp,-1);
  REP(i,n)REP(j,m) cin>>d[i][j];
  REP(i,n)REP(j,m) sz[id(i,j)]=1,f[id(i,j)]=id(i,j);
  //debug(456);
  REP(i,n){
    //debug(i);
    vector<ii> v;
    REP(j,m) v.pb({d[i][j],j});
    sort(ALL(v));
    REP(j,m-1)if(v[j].F==v[j+1].F) mer(fd(id(i,v[j].S)),fd(id(i,v[j+1].S)));
  }
  REP(i,m){
    //debug(i);
    vector<ii> v;
    REP(j,n) v.pb({d[j][i],j});
    sort(ALL(v));
    //debug("alive");
    REP(j,n-1)if(v[j].F==v[j+1].F) mer(fd(id(v[j].S,i)),fd(id(v[j+1].S,i)));
  }
  //debug("hello");
  REP(i,n){
    vector<ii> v;
    REP(j,m) v.pb({d[i][j],j});
    sort(ALL(v));
    REP(j,m-1)if(v[j].F < v[j+1].F) g[fd(id(i,v[j+1].S))].pb(fd(id(i,v[j].S)));
  }
  REP(i,m){
    vector<ii> v;
    REP(j,n) v.pb({d[j][i],j});
    sort(ALL(v));
    REP(j,n-1)if(v[j].F < v[j+1].F) g[fd(id(v[j+1].S,i))].pb(fd(id(v[j].S,i)));
  }
  ll ans = 0;
  //debug("hi");
  REP(i,n*m){
    if(dp[i]==-1) dfs(i);
    chkmax(ans,dp[i]);
  }
  cout<<ans<<endl;
}
