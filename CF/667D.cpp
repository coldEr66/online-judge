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

const ll MAXn=3e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const int INF=0x3f3f3f3f;

vector<int> e1[MAXn],e2[MAXn];
int dis1[MAXn][MAXn];
int dis2[MAXn][MAXn];
int tmp1[MAXn][3],tmp2[MAXn][3];
int n,m;
void bfs(int x,vector<int> *e,int *dis,int *tmp){
  queue<int> q;
  dis[x] = 0;
  q.push(x);
  while( SZ(q) ){
    int cur = q.front();
    q.pop();
    for( int it:e[cur] ){
      if( dis[it]==INF ){
        dis[it]=dis[cur]+1;
        q.push(it);
      }
    }
  }
  tmp[0]=tmp[1]=tmp[2]=x;
  REP(i,n)if( dis[i]!=INF ){
    REP(j,3)if( dis[i]>dis[tmp[j]] ){
      for(int k=2;k>j;k--) tmp[k]=tmp[k-1];
      tmp[j]=i;
      break;
    }
  }
}
bool chk(int a,int b,int c,int d){
  if( a==b || a==c || a==d || c==d || b==d ) return true;
  return false;
}
int main(){
  IOS();
  cin>>n>>m;
  RST(dis1,INF);
  RST(dis2,INF);
  REP(i,m){
    int a,b;
    cin>>a>>b;
    a--,b--;
    e1[a].pb(b);
    e2[b].pb(a);
  }
  REP(i,n){
    bfs(i,e1,dis1[i],tmp1[i]);
    bfs(i,e2,dis2[i],tmp2[i]);
  }
  REP(i,n) pary(dis1[i],dis1[i]+n);
  REP(i,n) pary(dis2[i],dis2[i]+n);
  int ma=0;
  vector<int> ans;
  REP(i,n)REP(j,n)if( i!=j && dis1[i][j]!=INF ){
    REP(u,3)REP(v,3){
      int ct=tmp2[i][u];
      int dt=tmp1[j][v];
      if( chk(ct,i,j,dt) ) continue;
      int tp=dis1[ct][i]+dis1[i][j]+dis1[j][dt];
      if(tp>ma){
        ma=tp;
        ans=(vector<int>){ct,i,j,dt};
      }
    }
  }
  REP(i,4){
    if(i!=0) cout<<' ';
    cout<<ans[i]+1;
  }
  cout<<endl;
}
