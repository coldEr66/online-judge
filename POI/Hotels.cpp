#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
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

vector<int> e[MAXn];
short dp[MAXn][MAXn];
int maxd;
void dfs(int x,int p,int root,int dep){
  // debug(root,dep);
  maxd = max(maxd,dep);
  dp[root][dep]++;
  REP (i,SZ(e[x])) {
    if (e[x][i] == p) continue;
    dfs(e[x][i],x,root,dep+1);
  }
}
int main(){
  IOS();
  int n;
  cin >> n;
  REP (i,n-1) {
    int u,v;
    cin >> u >> v;
    u--, v--;
    e[u].eb(v);
    e[v].eb(u);
  }

  ll ans = 0;
  REP (i,n) {
    maxd = 0;
    // debug(i);
    REP (it,SZ(e[i])) {
      REP (d,n+1) dp[e[i][it]][d] = 0;
      dfs(e[i][it],i,e[i][it],0);
    }
    // REP (it,SZ(e[i])) pary(dp[e[i][it]],dp[e[i][it]] + n);
    REP (j,maxd+1) {
      ll tmp = 0, tt = 0, sum = 0;
      REP (it,SZ(e[i])) {
        // debug(dp[e[i][it]][j],e[i][it],j);
        tt += dp[e[i][it]][j] * tmp;
        tmp += dp[e[i][it]][j] * sum;
        sum += dp[e[i][it]][j];
      }
      ans += tt;
    }
  }
  cout << ans << endl;
}
