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

int n,m;
vector<int> e[MAXn];
int dfn[MAXn],low[MAXn],t;
ii ans[MAXn];
bool cmp(const ii &a,const ii &b){
  if( a.X!=b.X ) return a.X>b.X;
  else return a.Y<b.Y;
}
void dfs(int x,int p){
  dfn[x] = low[x] = ++t;
  for( auto i:e[x] ){
    if( i==p ) continue;
    if( !dfn[i] ){
      dfs(i,x);
      chkmin(low[x],low[i]);
      if( low[i]>dfn[x] ) ans[x].X++;
    }
    else chkmin(low[x],dfn[i]);
  }
  if( x==p ) ans[x].X--;
}
int main(){
  IOS();
  while( cin>>n>>m && n && m ){
    REP(i,n) e[i].clear();
    int a,b;
    t=0;
    while( cin>>a>>b ){
      if( a==-1 && b==-1 ) break;
      e[a].eb(b);
      e[b].eb(a);
    }
    REP(i,n) debug(e[i]);
    RST(dfn,0);
    RST(low,0);
    int c=0;
    REP(i,n) ans[i]=mkp(0,i);
    REP(i,n)if( !dfn[i] ) dfs(i,i),c++;
    pary(low,low+n);
    debug(c);
    REP(i,n) ans[i].X+=c;
    sort(ans,ans+n,cmp);
    REP(i,m) cout<<ans[i].Y<<' '<<ans[i].X<<endl;
    cout<<endl;
  }
}