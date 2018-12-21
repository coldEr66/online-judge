#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
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

const ll MAXn=1e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int d[MAXn][MAXn];
int x[MAXn],y[MAXn];
int main(){
  IOS();
  int t;
  cin>>t;
  while( t-- ){
    int n,m,sum=0;
    RST(x,0);
    RST(y,0);
    cin>>n>>m;
    REP(i,n)REP(j,m){
      cin>>d[i][j];
      x[i]+=d[i][j];
      y[j]+=d[i][j];
      sum+=d[i][j];
    }
    debug("QQ");
    sum = (sum+1)/2;
    int an=0,ans=0;
    int tmp=0;
    REP(i,n){
      if( tmp+x[i]<sum ) tmp+=x[i];
      else{
        an=i;
        break;
      }
    }
    debug("QQ");
    tmp=0;
    REP(i,m){
      if( tmp+y[i]<sum ) tmp+=y[i];
      else{
        ans=i;
        break;
      }
    }
    int tot=0;
    REP(i,n)REP(j,m) tot+=(abs(i-an)+abs(j-ans))*d[i][j];
    tot*=100;
    cout<<an+1<<' '<<ans+1<<endl;
    cout<<tot<<endl;
  }
}
