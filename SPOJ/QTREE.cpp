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
} e[MAXn*2];
int sz[MAXn],seg[MAXn*2],son[MAXn],top[MAXn],head[MAXn];
int dep[MAXn],fa[MAXn],dfn[MAXn];
int cnt,idx;
void add(int u,int v,int w){
  e[cnt].u=u;
  e[cnt].v=v;
  e[cnt].w=w;
  e[cnt].nxt=head[u];
  head[u]=cnt++;
}
void build(){
  for(int i=idx-1;i>0;i--) seg[i] = max(seg[i<<1],seg[i<<1|1]);
}
void ins(int i,int v){
  for(seg[i+=idx]=v;i>1;i>>=1) seg[i>>1] = max(seg[i],seg[i^1]);
}
int qr(int l,int r){
  int ret=-INF;
  for(l+=idx,r+=idx;l<r;l>>=1,r>>=1){
    if( l&1 ) chkmax(ret,seg[l++]);
    if( r&1 ) chkmax(ret,seg[--r]);
  }
  return ret;
}
int QQ(int u,int v){
  int x=top[u],y=top[v];
  int ret=-INF;
  debug(u,v,x,y);
  while( x!=y ){
    if( dep[x]<dep[y] ){
      swap(x,y);
      swap(u,v);
    }
    chkmax(ret,qr(dfn[x],dfn[u]+1));
    debug(ret);
    u=fa[x];
    x=top[u];
  }
  if( u==v ) return ret;
  debug(dep[u],dep[v]);
  if( dep[u]>dep[v] ) swap(u,v);
  chkmax(ret,qr(dfn[son[u]],dfn[v]+1));
  return ret;
}
void dfs1(int x,int par,int d){
  dep[x]=d;
  fa[x]=par;
  sz[x]=1;
  son[x]=0;
  for(int i=head[x];i!=-1;i=e[i].nxt){
    int tmp = e[i].v;
    if( tmp==par ) continue;
    dfs1(tmp,x,d+1);
    sz[x]+=sz[tmp];
    if( sz[son[x]]<sz[tmp] ) son[x] = tmp;
  }
}
void dfs2(int x,int tp){
  top[x]=tp;
  dfn[x]=++idx;
  if( son[x] ) dfs2(son[x],tp);
  for(int i=head[x];i!=-1;i=e[i].nxt){
    int tmp = e[i].v;
    if( tmp==fa[x] || tmp==son[x] ) continue;
    dfs2(tmp,tmp);
  }
}
int main(){
  IOS();
  int t;
  cin>>t;
  while( t-- ){
    RST(head,-1);
    cnt=idx=0;
    int n;
    cin>>n;
    REP(i,n-1){
      int a,b,c;
      cin>>a>>b>>c;
      add(a,b,c);
      add(b,a,c);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    for(int i=0;i<cnt;i+=2){
      if( dep[e[i].u]<dep[e[i].v] ) swap(e[i].u,e[i].v);
      seg[dfn[e[i].u]+idx]=e[i].w;
    }
    build();
    string cmd;
    while( cin>>cmd && cmd[0]!='D' ){
      int a,b;
      cin>>a>>b;
      if( cmd[0]=='C' ) ins(dfn[e[(a-1)*2].u],b);
      else cout<<QQ(a,b)<<endl;
    }
  }
}
