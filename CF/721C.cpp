#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
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

vector<ii> e[MAXn];
int dp[MAXn][MAXn];
int s[MAXn][MAXn];
int dfs(int x,int d){
  if (x == 0 && d != 1) return INF;
  if (dp[x][d] != -1) return dp[x][d];
  int ret = INF;
  int id = -1;
  for (auto i:e[x]) {
    int cur = i.X, w = i.Y;
    debug(cur,x);
    int tmp = dfs(cur,d-1) + w;
    if (tmp < ret) ret = tmp, id = cur;
  }
  debug(id);
  s[x][d] = id;
  return dp[x][d] = ret;
}
int main(){
  IOS();
  int n,m,T;
  cin >> n >> m >> T;
  REP (i,m) {
    int u,v,w;
    cin >> u >> v >> w;
    u--, v--;
    e[v].eb(u,w);
  }
  debug(INF);
  RST(dp,-1);
  dp[0][1] = 0;
  RST(s,-1);
  for (int i=n;i>=1;i--) {
    if (dfs(n-1,i) <= T) {
      cout << i << endl;
      int cur = n-1;
      vector<int> ans;
      int dep = i;
      while (dep > 1) {
        debug(cur);
        ans.eb(cur);
        cur = s[cur][dep--];
      }
      ans.eb(0);
      reverse(ALL(ans));
      REP (j,SZ(ans)) cout << ans[j]+1 << " \n"[j==SZ(ans)-1];
      return 0;
    }
  }
}
