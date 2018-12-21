#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
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

const ll MAXn=1e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int dis[MAXn][MAXn];
vector<int> e[MAXn];
int fa[MAXn],sz[MAXn];
int fd(int x){return fa[x] = (fa[x]==x ?x:fd(fa[x]));}
void uni(int u,int v){
  u=fd(u),v=fd(v);
  if( sz[u]<sz[v] ) swap(u,v);
  fa[v] = u;
  sz[u]+=sz[v];
  sz[v]=0;
}
struct ed{
  int u,v,w;
  bool operator < (const ed &tmp)const{
    return w<tmp.w;
  }
};
vector<ed> q;
vector<ed> ans;
int main(){
  IOS();
  int n,m;
  cin>>n>>m;
  RST(dis,INF);
  REP(i,n) sz[i]=1,fa[i]=i;
  REP(i,m){
    int u,v,w;
    cin>>u>>v>>w;
    if( u>v ) swap(u,v);
    q.eb((ed){u,v,w});
  }
  sort(ALL(q));
  REP(i,m){
    int u=q[i].u,v=q[i].v,w=q[i].w;
    if( dis[u][v]<w || dis[v][u]<w) return cout<<-1<<endl,0;
    else if( dis[u][v]>w ){
      ans.eb((ed){u,v,w});
      uni(u,v);
      e[u].eb(v);
      e[v].eb(u);
      dis[u][v]=dis[v][u]=w;
      for( auto j:e[u] ){
        if( j==v ) continue;
        if( dis[j][v]>dis[j][u]+w ) dis[v][j]=dis[j][v]=dis[j][u]+w;
      }
      for( auto j:e[v] ){
        if( j==u ) continue;
        if( dis[j][u]>dis[j][v]+w ) dis[u][j]=dis[j][u]=dis[j][v]+w;
      }
    }
  }
  REP1(i,n){
    if( i==1 ) continue;
    if( fd(i)!=fd(1) ){
      ans.eb((ed){1,i,1000005});
      uni(1,i);
    }
  }
  cout<<SZ(ans)<<endl;
  for( auto i:ans ) cout<<i.u<<' '<<i.v<<' '<<i.w<<endl;
}
