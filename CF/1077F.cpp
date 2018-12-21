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

const ll MAXn=5e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll d[MAXn];
ll dp[MAXn][MAXn];
int main(){
  IOS();
  ll n,k,x;
  cin>>n>>k>>x;
  REP1(i,n) cin>>d[i];
  RST(dp,-1);
  deque<ii> dq;
  ll ans = -1;
  dp[0][0] = 0;
  REP1(T,x){
    dq.clear();
    for(ll i=0;i<k-1 && n-i-1>=0;i++){
      while(SZ(dq) && dq.back().X < dp[n-i-1][T-1]) dq.pob();
      dq.eb(dp[n-i-1][T-1],n-i-1);
    }
    ll it = max(n-k,0LL);
    for(ll i=n;i>0;i--){
      while(SZ(dq) && dq.front().Y >= i) dq.pop_front();
      while(SZ(dq) && dq.back().X < dp[it][T-1]) dq.pob();
      dq.eb(dp[it][T-1],it);
      if(it > 0) it--;
      while(SZ(dq) && dq.front().X == -1) dq.pop_front();
      if(SZ(dq) && dq.front().X != -1) dp[i][T] = dq.front().X + d[i];
    }
  }
  REP1(i,n) pary(dp[i],dp[i]+x+1);
  for(ll i=n-k+1;i<=n;i++) chkmax(ans,dp[i][x]);
  cout<<ans<<endl;
}
