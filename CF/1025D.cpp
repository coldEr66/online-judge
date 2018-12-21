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

const ll MAXn=7e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll d[MAXn];
bool dp[MAXn][MAXn][2];
ll pre[MAXn][MAXn];
int main(){
  IOS();
  ll n;
  cin >> n;
  REP (i,n) cin >> d[i];

  REP (i,n) dp[i][i][0] = dp[i][i][1] = true;
  REP (i,n) REP (j,n) pre[i][j] = __gcd(d[i],d[j])!=1;

  REP1 (dis,n) for (int l=0;l+dis<n;l++) {
    ll r = l+dis;
    if (pre[l][l+1] && dp[l+1][r][0]) dp[l][r][0] = true;
    if (pre[l][r] && dp[l+1][r][1]) dp[l][r][0] = true;
    else {
      for (ll k=l+2;k<r;k++) {
        if (pre[l][k] && dp[l+1][k][1] && dp[k][r][0]) {
          dp[l][r][0] = true;
          break;
        }
      }
    }

    if (pre[r-1][r] && dp[l][r-1][1]) dp[l][r][1] = true;
    else if (pre[l][r] && dp[l][r-1][0]) dp[l][r][1] = true;
    else {
      for (ll k=r-2;k>l;k--) {
        if (pre[k][r] && dp[l][k][1] && dp[k][r-1][0]) {
          dp[l][r][1] = true;
          break;
        }
      }
    }
  }

  if (dp[0][n-1][0] || dp[0][n-1][1]) return cout << "Yes" << endl,0;
  REP (i,n) if(dp[0][i][1] && dp[i][n-1][0]) return cout << "Yes" << endl,0;
  cout << "No" << endl;
}
