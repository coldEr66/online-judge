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

char dt[MAXn][MAXn];
int u[MAXn][MAXn];
int d[MAXn][MAXn];
int l[MAXn][MAXn];
int r[MAXn][MAXn];
int rs[MAXn][MAXn];
int cs[MAXn][MAXn];
vector<pair<ii,ll> > v;
int chk(int i,int j){
  int ret=min({u[i][j],d[i][j],l[i][j],r[i][j]})-1;
  return ret;
}
int main(){
  IOS();
  int n,m;
  cin>>n>>m;
  REP(i,n)REP(j,m) cin>>dt[i][j];
  REP(i,n)REP(j,m){
    if( dt[i][j]=='.' ) u[i][j]=l[i][j]=0;
    else{
      u[i][j]=u[i-1][j]+1;
      l[i][j]=l[i][j-1]+1;
    }
  }
  for(int i=n-1;i>=0;i--)for(int j=m-1;j>=0;j--){
    if( dt[i][j]=='.' ) d[i][j]=r[i][j]=0;
    else{
      d[i][j]=d[i+1][j]+1;
      r[i][j]=r[i][j+1]+1;
    }
  }
  REP(i,n)REP(j,m){
    if( dt[i][j]=='.' ) continue;
    int tmp=chk(i,j);
    if(!tmp) continue;
    v.pb(mkp(mkp(i+1,j+1),tmp));
    rs[i][j-tmp]++,rs[i][j+tmp+1]--;
    cs[i-tmp][j]++,cs[i+tmp+1][j]--;
  }
  REP(i,n)REP(j,m){
    if( j!=0 ) rs[i][j]+=rs[i][j-1];
    if( i!=0 ) cs[i][j]+=cs[i-1][j];
  }
  REP(i,n)REP(j,m){
    if( dt[i][j]=='.' ) continue;
    if( !rs[i][j] && !cs[i][j] ) return cout<<-1<<endl,0;
  }
  cout<<SZ(v)<<endl;
  for( auto i:v ) cout<<i.X.X<<' '<<i.X.Y<<' '<<i.Y<<endl;
}
