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

const ll MAXn=30,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

inline int getint(){
  ll _x=0,_tmp=1; char _tc=getchar();
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
vector<int> e[MAXn],re[MAXn],tp;
bool vis[MAXn];
int scc[MAXn];
void dfs1(int x){
  vis[x]=1;
  for( int i:e[x] )if( !vis[i] ) dfs1(i);
  tp.eb(x);
}
void dfs2(int x,int cnt){
  vis[x]=1;
  scc[x]=cnt;
  for( int i:re[x] )if( !vis[i] ) dfs2(i,cnt);
}
int main(){
  // IOS();
  int t;
  cin>>t;
  while(t--){
    int n,m;
    n=getint();
    m=getint();
    REP(i,2*n){
      e[i].clear();
      re[i].clear();
    }
    tp.clear();
    RST(vis,0);
    RST(scc,0);
    REP(i,m){
      char a,b;
      int c,d;
      scanf("%c",&a);
      c=getint();
      scanf("%c",&b);
      d=getint();
      c--,d--;
      int x=c,y=d;
      if(a=='h') x=n+c;
      if(b=='m') y=n+d;
      e[y].eb(x);
      re[x].eb(y);
      x=c,y=d;
      if(a=='m') x=n+c;
      if(b=='h') y=n+d;
      e[x].eb(y);
      re[y].eb(x);
    }
    REP(i,2*n)if( !vis[i] ) dfs1(i);
    RST(vis,0);
    int cnt=0;
    for(int i=SZ(tp)-1;i>=0;i--)if( !vis[tp[i]] ) dfs2(tp[i],cnt++);
    bool fg=true;
    REP(i,n)if( scc[i]==scc[i+n] ) fg=false;
    printf("%s\n",(fg ?"GOOD":"BAD"));
  }
}