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

const ll MAXn=1e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

struct edge{
  ll a,b,w;
  bool operator < (const edge &tmp){
    return w < tmp.w;
  }
};
edge d[MAXn*MAXn];
ll fa[MAXn],sz[MAXn];
vector<ii> e[MAXn];
ll dis[MAXn][MAXn];
bitset<MAXn> vis;
ll fd(ll x){return fa[x] = (x==fa[x] ?x:fd(fa[x]));}
void uni(ll x,ll y){
  x = fd(x);
  y = fd(y);
  if( x == y ) return;
  if( sz[x]<sz[y] ) swap(x,y);
  sz[x] += sz[y];
  sz[y] = 0;
  fa[y] = x;
}
void dfs(ll x,ll p){
  vis[x] = true;
  for( auto i:e[x] )if( !vis[i.X] ){
    dis[p][i.X] = max(dis[p][x],i.Y);
    dfs(i.X,p);
  }
}
int main(){
  IOS();
  ll n,m;
  cin>>n>>m;
  REP(i,n) fa[i] = i,sz[i] = 1;
  RST(dis,0);
  REP(i,m){
    ll a,b,w;
    cin>>a>>b>>w;
    a--,b--;
    d[i] = (edge){a,b,w};
  }
  sort(d,d+m);
  vector<edge> tmp;
  ll cnt = 0;
  ll sum = 0;
  REP(i,m){
    ll u = d[i].a;
    ll v = d[i].b;
    ll w = d[i].w;
    debug(u,v,w);
    if( fd(u)==fd(v) ){
      tmp.eb(d[i]);
      continue;
    }
    cnt++;
    sum += w;
    e[u].eb(v,w);
    e[v].eb(u,w);
    uni(u,v);
  }
  debug(cnt);
  if( cnt != n-1 ) return cout<<"-1 -1"<<endl,0;
  REP(i,n){
    vis.reset();
    dfs(i,i);
  }
  if( m == n-1 ) return cout<<sum<<' '<<-1<<endl,0;
  ll sec = INF;
  for( auto i:tmp ){
    chkmin(sec,sum+i.w-dis[i.a][i.b]);
  }
  cout<<sum<<' '<<sec<<endl;
}
