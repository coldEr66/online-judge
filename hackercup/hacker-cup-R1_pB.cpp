#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
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

const ll MAXn=2e3+20,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

int ans[MAXn];
bool vis[MAXn];
int adj[MAXn];
vector<int> pre,post;
vector<int> tree[MAXn];
int r;
void dfs1(int cur){
  vis[cur] = true;
  pre.pb(cur);
  for(auto it:tree[cur]){
    if(it==0) continue;
    if(!vis[it]) dfs1(it);
  }
  post.pb(cur);
}
void dfs2(int cur,int x){
  vis[cur] = true;
  ans[cur] = x;
  if(!vis[adj[cur]]) dfs2(adj[cur],x);
}
int main(){
  IOS();
  freopen("ethan_traverses_a_tree.txt","r",stdin);
  freopen("EthanTraversesATree","w",stdout);
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    RST(ans,0);
    RST(vis,0);
    RST(adj,0);
    pre.clear();
    post.clear();
    REP1(i,n+5) tree[i].clear();
    REP1(i,n){
      int a,b;
      cin>>a>>b;
      tree[i].pb(a);
      tree[i].pb(b);
    }
    dfs1(1);
    debug(pre);
    debug(post);
    REP(i,n) adj[pre[i]] = post[i];
    int cnt = 0;
    RST(vis,0);
    REP1(i,n)if(!vis[i]){
      if(cnt<k) cnt++;
      dfs2(i,cnt);
    }
    cout<<"Case #"<<++r<<": ";
    if(cnt!=k) cout<<"Impossible";
    else{
      REP1(i,n){
        if(i!=1) cout<<' ';
        cout<<ans[i];
      }
    }
    cout<<endl;
  }
}
