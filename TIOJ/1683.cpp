#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#define pob pop_back
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
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

const ll MAXn=1e4+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

vector<int> e[MAXn],re[MAXn],tp,tr[MAXn];
bool vis[MAXn];
int scc[MAXn],sz[MAXn],dp[MAXn];
void dfs1(int x){
  vis[x]=1;
  for( auto i:e[x] )if( !vis[i] ) dfs1(i);
  tp.pb(x);
}
void dfs2(int x,int cnt){
  vis[x]=1;
  scc[x]=cnt;
  sz[cnt]++;
  debug(x,cnt);
  for( auto i:re[x] )if( !vis[i] ) dfs2(i,cnt);
}
void dfsdp(int x){
  dp[x]=sz[x];
  for( auto i:tr[x] ){
    if( dp[i]==-1 ) dfsdp(i);
    chkmax(dp[x],dp[i]+sz[x]);
  }
}
int main(){
  IOS();
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    RST(vis,0);
    RST(scc,0);
    RST(sz,0);
    RST(dp,-1);
    tp.clear();
    REP(i,n){
      e[i].clear();
      re[i].clear();
      tr[i].clear();
    }
    REP(i,m){
      int a,b;
      cin>>a>>b;
      a--,b--;
      e[a].pb(b);
      re[b].pb(a);
    }
    REP(i,n)if( !vis[i] ) dfs1(i);
    RST(vis,0);
    int cnt=0;
    reverse(ALL(tp));
    REP(i,n)if( !vis[tp[i]] ) dfs2(tp[i],cnt++);
    REP(i,n)for( auto j:e[i] ){
      if( scc[i]!=scc[j] ) tr[scc[i]].pb(scc[j]);
    }
    REP(i,cnt) debug(tr[i]);
    REP(i,cnt)if( dp[i]==-1 ) dfsdp(i);
    pary(sz,sz+cnt);
    int ans=1;
    REP(i,cnt) chkmax(ans,dp[i]);
    cout<<ans<<endl;
  }
}
