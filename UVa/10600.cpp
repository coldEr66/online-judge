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

const ll MAXn=1e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

struct E{
  int l,r,w;
  bool operator < (const E &a){
    return w<a.w;
  }
};
int fa[MAXn],sz[MAXn];
E d[MAXn*MAXn];
vector<ii> e[MAXn];
int dis[MAXn][MAXn];
bool vis[MAXn];
vector<E> v;
int fd(int x){return fa[x] = (fa[x]==x ?x:fd(fa[x]));}
void uni(int a,int b){
  a=fd(a),b=fd(b);
  if( sz[a]<sz[b] ) swap(a,b);
  fa[b]=a;
  sz[a]+=sz[b];
  sz[b]=0;
}
void dfs(int x,int r){
  vis[x]=1;
  for( auto i:e[x] )if( !vis[i.X] ){
    dis[r][i.X]=max((ll)dis[r][x],i.Y);
    dfs(i.X,r);
  }
}
int main(){
  IOS();
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    REP(i,n) e[i].clear();
    v.clear();
    RST(dis,0);
    REP(i,n) fa[i]=i,sz[i]=1;
    REP(i,m){
      int a,b,w;
      cin>>a>>b>>w;
      a--,b--;
      d[i]=(E){a,b,w};
    }
    sort(d,d+m);
    int mi=0;
    int cnt=0;
    REP(i,m){
      E cur=d[i];
      int a=cur.l,b=cur.r,w=cur.w;
      // debug(fd(a),fd(b),w);
      if( fd(a)==fd(b) ){
        v.pb(cur);
        continue;
      }
      // debug(w);
      mi+=w;
      cnt++;
      e[a].pb(mkp(b,w));
      e[b].pb(mkp(a,w));
      uni(a,b);
      if( cnt==n ) break;
    }
    cout<<mi<<' ';
    REP(i,n){
      RST(vis,0);
      dfs(i,i);
    }
    // REP(i,n) pary(dis[i],dis[i]+n);
    int ans=INF;
    for( E i:v ){
      int a=i.l,b=i.r,w=i.w;
      // debug(w,dis[a][b]);
      chkmin(ans,mi+w-dis[a][b]);
    }
    cout<<ans<<endl;
  }
}
