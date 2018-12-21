#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
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

const ll MAXn=3e4+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

struct E{
  int a,b,w;
  bool operator < (const E &x){
    return w<x.w;
  }
} e[50005];
int n,m;
vector<ii> adj[MAXn];
int fa[MAXn],sz[MAXn];
bool vis[MAXn];
int an[MAXn][MAXlg],v[MAXn][MAXlg];
int in[MAXn],out[MAXn],t;
void init(){
  // RST(v,INF);
  // RST(an,INF);
  REP(i,n){
    fa[i]=i;
    sz[i]=1;
  }
}
int fd(int x){return fa[x] = (x==fa[x] ?x:fd(fa[x]));}
void uni(int a,int b){
  a=fd(a),b=fd(b);
  if( sz[a]<sz[b] ) swap(a,b);
  fa[b]=a;
  sz[a]+=sz[b];
  sz[b]=0;
}
bool chk(int a,int b){
  return in[a]<=in[b] && out[a]>=out[b];
}
void dfs(int x,int p,int w){
  vis[x]=1;
  in[x]=++t;
  an[x][0]=p;
  v[x][0]=w;
  for(int i=1;(1<<i)<n;i++){
    an[x][i]=an[an[x][i-1]][i-1];
    v[x][i] = max(v[x][i-1],v[an[x][i-1]][i-1]);
  }
  for( ii i:adj[x] ){
    if( i.X==p ) continue;
    dfs(i.X,x,i.Y);
  }
  out[x]=++t;
}
int LCA(int a,int b){
  int ret=0;
  if( chk(a,b) ) swap(a,b);
  for(int i=__lg(n)+1;i>=0;i--){
    // debug(an[a][i],b,v[a][i]);
    if( !chk(an[a][i],b) ){
      chkmax(ret,v[a][i]);
      a=an[a][i];
    }
  }
  debug(a);
  chkmax(ret,v[a][0]);
  for(int i=__lg(n)+1;i>=0;i--){
    // debug(an[a][i],b,v[a][i]);
    if( !chk(an[b][i],a) ){
      chkmax(ret,v[b][i]);
      b=an[b][i];
    }
  }
  debug(b);
  if( !chk(b,a) ) chkmax(ret,v[b][0]);
  return ret;
}
int main(){
  IOS();
  cin>>n>>m;
  init();
  REP(i,m){
    int a,b,w;
    cin>>a>>b>>w;
    a--,b--;
    e[i]=(E){a,b,w};
  }
  sort(e,e+m);
  REP(i,m){
    int a=e[i].a,b=e[i].b;
    if( fd(a)==fd(b) ) continue;
    adj[a].pb(mkp(b,e[i].w));
    adj[b].pb(mkp(a,e[i].w));
    uni(a,b);
  }
  REP(i,n) debug(adj[i]);
  REP(i,n)if( !vis[i] ) dfs(i,i,0);
  REP(i,n) pary(an[i],an[i]+__lg(n)+1);
  REP(i,n) pary(v[i],v[i]+__lg(n)+1);
  int q;
  cin>>q;
  while(q--){
    int a,b;
    cin>>a>>b;
    a--,b--;
    debug(fd(a),fd(b));
    if( fd(a)!=fd(b) ) cout<<-1<<endl;
    else if( a==b ) cout<<0<<endl;
    else cout<<LCA(a,b)<<endl;
  }
}
