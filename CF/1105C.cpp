#include <bits/stdc++.h>
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
template<class T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll dp[MAXn][3];
ll mul(ll x,ll y){
  return (x*y)%MOD;
}
ll add(ll x,ll y,ll z){
  ll tmp = x+y+z;
  while (tmp >= MOD) tmp -= MOD;
  return tmp;
}
int main(){
  IOS();
  ll n,l,r;
  cin >> n >> l >> r;

  ll rem[3] = {};
  ll tmp = r/3-ll(ceil(lf(l)/3.0))+1LL;
  debug(tmp);
  rem[0] = rem[1] = rem[2] = tmp;
  if (l%3 == 0) {
    if (r%3 == 0) rem[1]--,rem[2]--;
    else if (r%3 == 1) rem[2]--;
  }
  else if (l%3 == 1) {
    if (r%3 == 1) rem[1]++;
    else if (r%3 == 2) rem[1]++,rem[2]++;
  }
  else {
    if (r%3 == 0) rem[1]--;
    else if (r%3 == 2) rem[2]++;
  }
  pary(rem,rem+3);

  dp[0][0] = 1;
  REP1 (i,n) {
    dp[i][0] = add(mul(dp[i-1][0],rem[0]),mul(dp[i-1][1],rem[2]),mul(dp[i-1][2],rem[1]));
    dp[i][1] = add(mul(dp[i-1][0],rem[1]),mul(dp[i-1][1],rem[0]),mul(dp[i-1][2],rem[2]));
    dp[i][2] = add(mul(dp[i-1][0],rem[2]),mul(dp[i-1][1],rem[1]),mul(dp[i-1][2],rem[0]));
  }

  cout << dp[n][0] << endl;
}
