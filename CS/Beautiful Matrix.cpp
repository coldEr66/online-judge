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

const ll MAXn=3e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

vector<ll> re[MAXn],ce[MAXn];
ll rsum[MAXn],csum[MAXn];
int main(){
  IOS();
  ll n,m;
  cin >> n >> m;
  REP (i,n) {
    REP (j,m) {
      ll x;
      cin >> x;
      re[i].eb(x);
      if (j == 0 || j == m-1) rsum[i] += x;
      else rsum[i] += 4*x;
    }
  }
  REP (j,m) REP (i,n) {
    ce[j].eb(re[i][j]);
    if (i == 0 || i == n-1) csum[j] += re[i][j];
    else csum[j] += 4*re[i][j];
  }
  ll it = min_element(rsum+1,rsum+n-1) - rsum;
  ll itt = min_element(csum+1,csum+m-1) - csum;
  ll ans = -INF,tmp = 0;
  REP (i,n-1) REP (j,m-1) {
    tmp += re[i][j] + re[i+1][j] + re[i+1][j+1] + re[i][j+1];
  }
  ans = max(ans,tmp);
  debug(ans);
  tmp = 0;
  REP (i,n-1) REP (j,m-1) {
    tmp += ce[j][i] + ce[j+1][i] + ce[j+1][i+1] + ce[j][i+1];
  }
  ans = max(ans,tmp);
  debug(tmp);
  tmp = 0;
  debug(it,itt);
  swap(re[0],re[it]);
  REP (i,n-1) REP (j,m-1) {
    tmp += re[i][j] + re[i+1][j] + re[i+1][j+1] + re[i][j+1];
  }
  debug(tmp);

  ans = max(ans,tmp);
  swap(re[0],re[it]);
  swap(re[n-1],re[it]);
  tmp = 0;
  REP (i,n-1) REP (j,m-1) {
    tmp += re[i][j] + re[i+1][j] + re[i+1][j+1] + re[i][j+1];
  }
  ans = max(ans,tmp);
  swap(re[n-1],re[it]);

  swap(ce[itt],ce[0]);
  tmp = 0;
  REP (j,m-1) REP (i,n-1) {
    // tmp += ce[i][j] + ce[i+1][j] + ce[i+1][j+1] + ce[i][j+1];
    tmp += ce[j][i] + ce[j][i+1] + ce[j+1][i+1] + ce[j+1][i];
  }
  ans = max(ans,tmp);
  swap(ce[itt],ce[0]);
  swap(ce[itt],ce[m-1]);
  tmp = 0;
  pary(ce,ce+m);
  REP (i,n-1) {
    REP (j,m-1) {
      // tmp += ce[i][j] + ce[i+1][j] + ce[i+1][j+1] + ce[i][j+1];
      debug(ce[j][i]);
      tmp += ce[j][i] + ce[j+1][i] + ce[j+1][i+1] + ce[j][i+1];
    }
    debug(tmp);
  }
  ans = max(ans,tmp);
  // swap(ce[itt],ce[m-1]);
  cout << ans << endl;
}
