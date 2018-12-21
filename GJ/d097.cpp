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

const ll MAXn=25,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll n;
vector<lf> dt;
vector<char> cdt;
char d[MAXn];
lf cal(){
  lf ret = 0.0;
  lf cur = dt[0];
  bool mi = false;
  REP(i,n){
    if(d[i] == '+' || d[i] == '-'){
      ret += cur*(mi ?-1:1);
      mi = (d[i]=='-');
      cur = dt[i+1];
    }
    else if(d[i] == '*') cur *= dt[i+1];
    else{
      if(dt[i+1] == 0) return -10000000000000.0;
      else cur /= dt[i+1];
    }
  }
  ret += cur*(mi ?-1:1);
  return ret;
}
int main(){
  IOS();
  cout<<fixed<<setprecision(2);
  string a,b;
  getline(cin,a);
  getline(cin,b);
  stringstream ss;
  lf tmp;
  ss.clear();
  ss.str(a);
  while(ss>>tmp) dt.pb(tmp);
  ss.clear();
  ss.str(b);
  char c;
  while(ss>>c) cdt.pb(c);
  n = SZ(cdt);
  REP(i,n) d[i] = cdt[i];
  lf ans = -100000000000.0;
  sort(d,d+n);
  do{
    lf tp = cal();
    ans = max(ans,tp);
  }while(next_permutation(d,d+n));
  cout<<ans<<endl;
}
