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
#define eb emplace_back
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

struct E{
  int u,v,w,nxt;
};
int n;
E e[MAXn*2];
int cnt;
int dis[MAXn][MAXlg];
int an[MAXn][MAXlg];
int in[MAXn],out[MAXn],o;
int dep[MAXn],head[MAXn];
void add(int u,int v,int w){
  e[cnt].u=u;
  e[cnt].v=v;
  e[cnt].w=w;
  e[cnt].nxt=head[u];
  head[u]=cnt++;
}
void dfs(int x,int p,int d,int w){
  in[x]=++o;
  an[x][0] = p;
  dis[x][0] = w;
  dep[x]=d;
  for(int i=1;1<<i <= n;i++){
    an[x][i] = an[an[x][i-1]][i-1];
    dis[x][i] = dis[x][i-1]+dis[an[x][i-1]][i-1];
  }
  for( int i=head[x];i!=-1;i=e[i].nxt ){
    int tmp = e[i].v;
    if( tmp==p ) continue;
    dfs(tmp,x,d+1,e[i].w);
  }
  out[x]=++o;
}
bool chk(int a,int b){
  return in[a]<=in[b] && out[a]>=out[b];
}
int sol(int u,int v){
  if( u==v ) return 0;
  int ret=0;
  if( chk(u,v) ) swap(u,v);
  debug(u,v);
  for(int i=__lg(n);i>=0;i--){
    if( !chk(an[u][i],v) ){
      debug(u,i);
      ret+=dis[u][i];
      u=an[u][i];
    }
    debug(ret,u);
  }
  debug(u);
  ret+=dis[u][0];
  if( an[u][0]==v ) return ret;
  for(int i=__lg(n);i>=0;i--){
    if( !chk(an[v][i],u) ){
      ret+=dis[v][i];
      v=an[v][i];
    }
    debug(ret,u);
  }
  debug(v);
  return ret+dis[v][0];
}
int kth(int u,int v,int k){
  int ret=u;
  // debug(u,v);
  if( k==0 ) return ret;
  if( chk(u,v) ) return kth(v,u,dep[v]-dep[u]-k);
  for(int i=__lg(n);i>=0;i--){
    if( !chk(an[u][i],v) && k-(1<<i)>=0 ){
      k-=(1<<i);
      u=an[u][i];
      ret = u;
      debug(ret);
    }
    if( k==0 ) return ret;
  }
  // assert(dep[v]-dep[an[u][0]]<=k);
  if( k==1 ) return an[u][0];
  debug(ret,k);
  k--;
  u=an[u][0];
  return kth(v,u,dep[v]-dep[u]-k);
}
int main(){
  IOS();
  int t;
  cin>>t;
  while( t-- ){
    RST(head,-1);
    RST(dis,0);
    RST(an,0);
    cnt=o=0;
    cin>>n;
    REP(i,n-1){
      int u,v,w;
      cin>>u>>v>>w;
      add(u,v,w);
      add(v,u,w);
    }
    dfs(1,1,1,-1);
    pary(dep+1,dep+n+1);
    REP1(i,n) pary(an[i],an[i]+__lg(n));
    REP1(i,n) pary(dis[i],dis[i]+__lg(n));
    string cmd;
    while( cin>>cmd && cmd!="DONE" ){
      if( cmd=="DIST" ){
        int a,b;
        cin>>a>>b;
        cout<<sol(a,b)<<endl;
      }
      else{
        int a,b,k;
        cin>>a>>b>>k;
        cout<<kth(a,b,k-1)<<endl;
      }
    }
  }
}
