#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

struct E{
  int u,v,w,nxt;
} ed[MAXn*2];
int c[MAXn];
int dep[MAXn];
vector<int> e[MAXn];
vector<ii> edge;
int head[MAXn],son[MAXn],fa[MAXn],top[MAXn],dfn[MAXn],sz[MAXn];
int cnt,idx;
int seg[MAXn<<1];
void addedge(int u,int v,int w){
  ed[cnt].u = u;
  ed[cnt].v = v;
  ed[cnt].w = w;
  ed[cnt].nxt = head[u];
  head[u] = cnt++;
}
void pre(int x,int p,int d){
  dep[x] = d;
  for (auto i:e[x]) {
    if (i == p) continue;
    pre(i,x,d+1);
  }
}
void dfs1(int x,int p){
  sz[x] = 1;
  fa[x] = p;
  son[x] = 0;
  for (int i=head[x];i!=-1;i=ed[i].nxt) {
    int to = ed[i].v;
    if (to == p) continue;
    dfs1(to,x);
    sz[x] += sz[to];
    if (sz[son[x]] < sz[to]) son[x] = to;
  }
}
void dfs2(int x,int tp){
  top[x] = tp;
  dfn[x] = ++idx;
  if (son[x]) dfs2(son[x],tp);
  for (int i=head[x];i!=-1;i=ed[i].nxt) {
    int to = ed[i].v;
    if (to == son[x] || to == fa[x]) continue;
    dfs2(to,to);
  }
}
void build(){
  for (int i=idx-1;i>0;i--) {
    seg[i] = seg[i<<1] ^ seg[i<<1|1];
  }
}
void ins(int x,int v){
  for (seg[x+=idx]=v;x>1;x>>=1) seg[x>>1] = seg[x] ^ seg[x^1];
}
int qr(int l,int r){
  int ret = 0;
  for (l+=idx,r+=idx;l<r;l>>=1,r>>=1) {
    if (l&1) ret ^= seg[l++];
    if (r&1) ret ^= seg[--r];
  }
  return ret;
}
int QQ(int u,int v){
  int x = top[u], y = top[v];
  int ret = 0;
  while (x != y) {
    if (dep[x] < dep[y]) {
      swap(x,y);
      swap(u,v);
    }
    debug(x,y,u,v);
    ret ^= qr(dfn[x],dfn[u]+1);
    u = fa[x];
    x = top[u];
  }
  debug(ret,u,v,x,y);
  if (u == v) return ret^c[u];
  if (dep[u] > dep[v]) swap(u,v);
  ret ^= qr(dfn[son[u]],dfn[v]+1);
  return ret^c[u];
}
int main(){
  freopen("cowland.in","r",stdin);
  freopen("cowland.out","w",stdout);
  IOS();
  RST(head,-1);
  int n,q;
  cin >> n >> q;
  REP1 (i,n) cin >> c[i];
  REP (i,n-1) {
    int u,v;
    cin >> u >> v;
    edge.eb(u,v);
    e[u].eb(v);
    e[v].eb(u);
  }
  pre(1,1,0);
  for (ii i:edge) {
    if (dep[i.X] < dep[i.Y]) swap(i.X,i.Y);
    addedge(i.X,i.Y,c[i.X]);
    addedge(i.Y,i.X,c[i.X]);
  }

  dfs1(1,1);
  dfs2(1,1);
  for (int i=0;i<cnt;i+=2) {
    if (dep[ed[i].u] < dep[ed[i].v]) swap(ed[i].u,ed[i].v);
    seg[dfn[ed[i].u]+idx] = ed[i].w;
  }
  build();
  while (q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int x,w;
      cin >> x >> w;
      ins(dfn[x],w);
      c[x] = w;
    }
    else {
      int u,v;
      cin >> u >> v;
      cout << QQ(u,v) << endl;
    }
  }
}
