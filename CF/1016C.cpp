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
const ll INF=0x3f3f3f3f;

ll a[MAXn],b[MAXn];
ll suma[MAXn],sumb[MAXn];
ll s[MAXn][2],t[MAXn][2];
int main(){
  IOS();
  ll n;
  cin >> n;
  REP (i,n) cin >> a[i];
  REP (i,n) cin >> b[i];

  for (ll i=n-1;i>=0;i--) {
    suma[i] = suma[i+1] + a[i];
    sumb[i] = sumb[i+1] + b[i];
  }
  ll ans = 0;
  ll x = 0,y = 2*n-1;
  REP (i,n) {
    s[i][1] = x * a[i];
    t[i][1] = y * b[i];
    x++, y--;
  }
  x = 2*n-1,y = 2;
  REP1 (i,n-1) {
    s[i][0] = a[i] * x;
    t[i][0] = b[i] * y;
    x--, y++;
  }
  for (ll i=n-1;i>=0;i--) {
    REP (j,2) {
      s[i][j] += s[i+1][j];
      t[i][j] += t[i+1][j];
    }
  }
  // REP (i,n) debug(s[i][0],s[i][1]);
  // REP (i,n) debug(t[i][0],t[i][1]);
  ans = max(s[0][1] + t[0][1],b[0] + s[0][0] + t[0][0]);
  // debug(s[0][1] + t[0][1],b[0] + s[0][0] + t[0][0]);
  // debug(ans);
  ll cur = b[0];
  x = 2;
  REP1 (i,n-1) {
    if (i&1) cur += x * b[i] + (x+1) * a[i];
    else cur += x * a[i] + (x+1) * b[i];
    // debug(cur);
    x += 2;
    ll tmp = i+1;
    ans = max(ans,cur + (tmp/2)*2 * (suma[tmp] + sumb[tmp]) + s[tmp][i&1] + t[tmp][i&1]);
    // debug(cur + (tmp/2)*2 * (suma[tmp] + sumb[tmp]) + s[tmp][i&1] + t[tmp][i&1]);
    // debug(s[tmp][i&1] + t[tmp][i&1]);
  }
  cout << ans << endl;
}
