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
#define F first
#define S second
#define pb push_back
#define pob pop_back
#define MP make_pair
#define VI vector<int>
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

const ll MAXn=2e3+5;
const ll MOD=1000000007;
const ll INF=(ll)1e18;

vector<ii> d[MAXn];
vector<ll> cost;
ll v[MAXn];
ll dfs(ll cur,ll fa,ll rt){
  vector<ll> tmp;
  for(ii x:d[cur]){
    if(x.F==fa) continue;
    tmp.pb(dfs(x.F,cur,rt)+x.S*v[rt]);
  }
  sort(ALL(tmp),greater<ll>());
  REP1(i,SZ(tmp)-1) cost.pb(tmp[i]);
  return SZ(tmp)==0 ?0:tmp[0];
}

int main(){
  IOS();
  ll n,m;
  cin>>n>>m;
  REP(i,n-1){
    ll a,b,t;
    cin>>a>>b>>t;
    a--,b--;
    //debug(i);
    d[a].pb(MP(b,t));
    d[b].pb(MP(a,t));
  }
  //debug("tree complete");
  REP(i,n) cin>>v[i];
  //debug("ok");
  REP(i,n) cost.pb(dfs(i,-1,i));
  ll ans=0;
  sort(ALL(cost),greater<ll>());
  m=min(m,(ll)SZ(cost));
  REP(i,m) ans+=cost[i];
  cout<<ans<<endl;
}
