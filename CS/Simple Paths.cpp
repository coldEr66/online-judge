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

const ll MAXn=1e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

vector<int> e[MAXn];
int dfn[MAXn],t,low[MAXn];
bitset<MAXn> vis;
bool bridge[MAXn][MAXn];
int fa[MAXn],cc[MAXn];
void predfs(int x,int p,int cnt){
  low[x] = dfn[x] = ++t;
  cc[x] = cnt;
  for( auto i:e[x] ){
    if( i==p ) continue;
    if( dfn[i] ) chkmin(low[x],low[i]);
    else{
      predfs(i,x,cnt);
      chkmin(low[x],low[i]);
      if( low[i]>dfn[x] ) bridge[i][x] = bridge[x][i] = true;
    }
  }
}
void dfs(int x,int p){
  debug("hello");
  fa[x] = p;
  vis[x] = true;
  for( auto i:e[x] ){
    if( i==p ) continue;
    if( !vis[i] ) dfs(i,x);
  }
}
bool chk(int u,int v){
  RST(fa,-1);
  vis.reset();
  dfs(u,u);
  debug("QAQ");
  for(int i=v;i!=u;i=fa[i])if( !bridge[i][fa[i]] ) return false;
  return true;
}
int main(){
  IOS();
  int n,m,q;
  cin>>n>>m>>q;
  REP(i,m){
    int u,v;
    cin>>u>>v;
    u--,v--;
    e[u].eb(v);
    e[v].eb(u);
  }
  int cnt=0;
  REP(i,n)if( !dfn[i] ) predfs(i,i,cnt++);
  while(q--){
    int u,v;
    cin>>u>>v;
    u--,v--;
    if( cc[u]!=cc[v] ) cout<<0<<endl;
    else cout<<chk(u,v)<<endl;
  }
}
