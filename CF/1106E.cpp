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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

struct range{
  ll w,d,cmd;
  bool operator < (const range &a) const {
    if (w != a.w) return w > a.w;
    return d > a.d;
  }
};
range d[MAXn];
vector<range> e[MAXn];
ll dp[MAXn][205];
map<range,ll> cnt;
int main(){
  IOS();
  ll n,m,k;
  cin >> n >> m >> k;
  REP (i,k) {
    ll s,t,D,w;
    cin >> s >> t >> D >> w;
    s--,t--,D--;
    e[s].push_back((range){w,D,1});
    e[t+1].push_back((range){w,D,0});
  }

  REP (i,n) {
    for (auto j:e[i]) {
      if (j.cmd == 1) cnt[j]++;
      else {
        cnt[j]--;
        if (cnt[j] == 0) cnt.erase(j);
      }
    }

    if (SZ(cnt)) d[i] = cnt.begin()->X;
    else d[i] = (range){0,i,0};
    debug(d[i].w,d[i].d,i);
  }

  REP (i,n+1) REP (j,m+1) dp[i][j] = INF;
  dp[0][0] = 0;
  ll ans = INF;
  REP (j,m+1) {
    REP (i,n) {
      dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j]);
      dp[d[i].d+1][j] = min(dp[d[i].d+1][j],dp[i][j] + d[i].w);
    }
    debug(ans);
    ans = min(ans,dp[n][j]);
  }
  cout << ans << endl;
}