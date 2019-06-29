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

const ll MAXn=3e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll n;
bool is_pr[MAXn];
vector<ll> prime;
void linear_sieve(){
  for (ll i=2;i<MAXn;i++) {
    if (!is_pr[i]) prime.eb(i);
    for (ll j=0;i*prime[j]<MAXn;j++) {
      is_pr[i*prime[j]] = true;
      if (i%prime[j] == 0) break;
    }
  }
}
void mul(ll &a,ll b){
  a = (a * b)%MOD;
}
ll fpow(ll a,ll b){
  ll ret = 1;
  while (b) {
    if (b&1) mul(ret,a);
    mul(a,a);
    b>>=1;
  }
  return ret;
}
ll fpow1(ll a,ll b){
  ll ret = 1;
  while (b) {
    if (b&1) {
      ret = ret * a;
      if (ret > n) return n+1;
    }
    a = a*a;
    b >>= 1;
  }
  if (ret > n) return n+1;
  return ret;
}
int main(){
  IOS();
  linear_sieve();
  ll t;
  cin >> t;
  while (t--) {
    cin >> n;
    ll ans = 1;
    ll lg = __lg(n);
    debug(SZ(prime));
    REP (i,SZ(prime)) {
      ll p = prime[i];
      if (p > n) break;
      REP (a,lg+1) {
        ll ta = fpow1(p,a);
        if (ta > n) break;
        REP (b,lg+1) {
          ll tb = fpow1(p,b);
          if (tb > n) break;
          REP (c,lg+1) {
            ll tc = fpow1(p,c);
            if (tc > n) break;
            // debug(a,b,c);
            ll lcd = max(min(a,b),c);
            ll gcm = min(max(a,b),c);
            ll aa = n/fpow(p,a);
            ll bb = n/fpow(p,b);
            ll cc = n/fpow(p,c);
            aa -= aa/p;
            bb -= bb/p;
            cc -= cc/p;
            ll tt = ((((lcd + gcm) * aa * bb)%(MOD-1)) * cc)%(MOD-1);
            mul(ans,fpow(p,tt));
          }
        }
      }
    }
    cout << ans << endl;
  }
}
