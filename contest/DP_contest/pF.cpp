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

const ll MAXn=3e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

string s,t;
ll dp[MAXn][MAXn];
ll x[MAXn][MAXn];
void print_ans(ll a,ll b){
  if (a == 0 || b == 0) return;
  if (x[a][b] == 0) {
    print_ans(a-1,b-1);
    cout << s[a];
  }
  else if (x[a][b] == 1) print_ans(a-1,b);
  else print_ans(a,b-1);
}
int main(){
  IOS();
  cin >> s >> t;
  s = ' '+s;
  t = ' '+t;
  REP (i,SZ(s)+1) dp[i][0] = 0;
  REP (i,SZ(t)+1) dp[0][i] = 0;
  REP1 (i,SZ(s)-1) REP1 (j,SZ(t)-1) {
    if (s[i] == t[j]) {
      dp[i][j] = dp[i-1][j-1] + 1;
      x[i][j] = 0;
    }
    else {
      if (dp[i-1][j] > dp[i][j-1]) {
        dp[i][j] = dp[i-1][j];
        x[i][j] = 1;
      }
      else {
        dp[i][j] = dp[i][j-1];
        x[i][j] = 2;
      }
    }
  }
  debug(dp[SZ(s)-1][SZ(t)-1]);
  print_ans(SZ(s)-1,SZ(t)-1);
  cout << endl;
}
