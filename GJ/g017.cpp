#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

vector<ii> e[MAXn];
priority_queue<pair<int,ii> > pq;
int fa[MAXn],sz[MAXn];
int dp[MAXn];
int fd(int x){return fa[x] = (x==fa[x] ?x:fd(fa[x]));}
void uni(int x,int y){
  if(sz[x]<sz[y]) swap(x,y);
  fa[y] = x;
  sz[x]+=sz[y];
  sz[y] = 0;
}
void dfs(int x,int an){
  REP(i,SZ(e[x])){
    ii it = e[x][i];
    if(it.X==an) continue;
    dp[it.X] = min(dp[x],it.Y);
    dfs(it.X,x);
  }
}
int main(){
  IOS();
  int n,m;
  while(cin>>n>>m){
    if(n==0 && m==0) break;
    REP(i,n){
      fa[i] = i;
      sz[i] = 1;
      e[i].clear();
    }
    while(SZ(pq)) pq.pop();
    while(m--){
      int a,b,c;
      cin>>a>>b>>c;
      a--,b--;
      pq.push(mkp(c,mkp(a,b)));
    }
    debug(SZ(pq));
    REP(i,n-1){
      debug("QQ");
      debug(fd(pq.top().Y.X),fd(pq.top().Y.Y));
      while(SZ(pq) && fd(pq.top().Y.X)==fd(pq.top().Y.Y)) pq.pop();
      debug("GEE");
      if(!SZ(pq)) break;
      pair<int,ii> cur = pq.top();
      pq.pop();
      uni(fd(cur.Y.X),fd(cur.Y.Y));
      debug(cur.Y.X,cur.Y.Y,cur.X);
      e[cur.Y.X].pb(mkp(cur.Y.Y,cur.X));
      e[cur.Y.Y].pb(mkp(cur.Y.X,cur.X));
    }
    debug("hi");
    int st,dst;
    cin>>st>>dst;
    st--,dst--;
    RST(dp,INF);
    dfs(st,st);
    if(dp[dst]==INF) cout<<0<<endl;
    else cout<<dp[dst]<<endl;
  }
}
