#include <bits/stdc++.h>
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
} e[MAXn*2];
int head[MAXn];
int sz[MAXn],son[MAXn],fa[MAXn],top[MAXn];
int dep[MAXn],dfn[MAXn],edge[MAXn],bit[MAXn];
int cnt,idx;
void dfs1(int x,int p,int d,int ww){
  dep[x] = d;
  fa[x] = p;
  sz[x] = 1;
  son[x] = 0;
  edge[x] = ww;
  for (int i=head[x];i!=-1;i=e[i].nxt) {
    int tmp = e[i].v;
    if (tmp == p) continue;
    dfs1(tmp,x,d+1,e[i].w);
    sz[x] += sz[tmp];
    if (sz[son[x]] < sz[tmp]) son[x] = tmp;
  }
}
void dfs2(int x,int tp){
  top[x] = tp;
  dfn[x] = ++idx;
  if (son[x]) dfs2(son[x],tp);
  for (int i=head[x];i!=-1;i=e[i].nxt) {
    int tmp = e[i].v;
    if (tmp == fa[x] || tmp == son[x]) continue;
    dfs2(tmp,tmp);
  }
}
void add(int x,int y,int val){
  e[cnt].u = x;
  e[cnt].v = y;
  e[cnt].w = val;
  e[cnt].nxt = head[x];
  head[x] = cnt++;
}
int lowbit(int x){return x&(-x);}
void ins(int x,int val){
  for (;x<=MAXn;x+=lowbit(x)) bit[x] += val;
}
int qr(int x){
  int ret = 0;
  for (;x>0;x-=lowbit(x)) ret += bit[x];
  return ret;
}
int qr(int l,int r){
  return qr(r)-qr(l-1);
}
int LCA(int x,int y){
  int a = top[x], b = top[y];
  while (a != b) {
    if (dep[a] < dep[b]) {
      swap(x,y);
      swap(a,b);
    }
    x = fa[a];
    a = top[x];
  }
  if (x == y) return x;
  if (dep[x] > dep[y]) swap(x,y);
  return x;
}
int QQ(int x,int y){
  int a = top[x], b = top[y];
  int ret = 0;
  while (a != b) {
    if (dep[a] < dep[b]) {
      swap(x,y);
      swap(a,b);
    }
    ret += qr(min(dfn[x],dfn[a]+2),dfn[x]);
    debug(min(dfn[x],dfn[a]+2),dfn[x],qr(dfn[a]+1,dfn[x]));
    x = fa[a];
    a = top[x];
  }
  if (x == y) return x;
  if (dep[x] > dep[y]) swap(x,y);
  ret += qr(dfn[x]+2,dfn[y]);
  return ret;
}
int main(){
  IOS();
  RST(head,-1);
  int n,q;
  cin >> n >> q;
  REP (i,n-1) {
    int u,v,w;
    cin >> u >> v >> w;
    add(u,v,w);
    add(v,u,w);
  }

  dfs1(1,0,1,-1);
  dfs2(1,1);
  pary(son+1,son+n+1);
  pary(edge+1,edge+n+1);
  for (int i=0;i<cnt;i+=2) {
    if (dep[e[i].u] < dep[e[i].v]) swap(e[i].u,e[i].v);
    debug(dfn[e[i].u],e[i].u);
    debug(edge[e[i].u],edge[e[i].v]);
    ins(dfn[e[i].u],(edge[e[i].u] <= edge[e[i].v] ?1:-1));
  }
  REP1 (i,idx) debug(qr(i,i));
  debug(qr(5,5));
  while (q--) {
    int a,b;
    cin >> a >> b;
    int tmp = QQ(a,b);
    int lca = LCA(a,b);
    debug(lca,tmp);
    ll len = dep[a]+dep[b]-2*dep[lca]-1;
    debug(len);
    if (tmp == len) cout << "YES" << endl;
    if (-tmp == len) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
