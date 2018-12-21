#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <cmath>
#include <bitset>
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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll n,m,s;
struct mat{
  lf m[51][51];
};
mat mul(mat x,mat y){
  mat ret;
  REP(i,m)REP(j,m) ret.m[i][j] = 0.0;
  REP(i,m)REP(j,m)REP(k,m) ret.m[i][j] += x.m[i][k]*y.m[k][j];
  return ret;
}
int main(){
  IOS();
  ll t;
  cin>>t;
  cout<<fixed<<setprecision(1);
  while(t--){
    cin>>n>>m>>s;
    if(s<=n){
      cout<<"100.0"<<'%'<<endl;
      continue;
    }
    if(s>=n+m){
      cout<<"0.0"<<'%'<<endl;
      continue;
    }
    mat a,b;
    REP(i,m)REP(j,m){
      a.m[i][j] = (i==j ?1.0:0.0);
      if(j == 0) b.m[i][j] = 1.0/(lf)m;
      else if(j == i+1) b.m[i][j] = 1.0;
      else b.m[i][j] = 0.0;
    }
    ll tmp = n;
    while(tmp){
      if(tmp&1) a = mul(a,b);
      b = mul(b,b);
      tmp>>=1;
    }
    lf ans = 0.0;
    for(ll j=s-n;j<m;j++){
      ans += a.m[j][0];
      debug(a.m[j][0]);
    }
    cout<<ans*100<<'%'<<endl;
  }
}
