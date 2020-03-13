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

const ll MAXn=5205,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int n;
bitset<MAXn> g[MAXn];
int dp[MAXn][MAXn];
vector<int> fac;
void FILL(int x,int now,int &cur){
  string s="";
  while (x) {
    if (x&1) s += '1';
    else s += '0';
    x>>=1;
  }
  while (SZ(s) < 4) s += '0';
  for (int i=3;i>=0;i--) {
    g[now][n-cur-1] = (s[i] == '1');
    cur++;
  }
}
void factor(int x){
  for (int i=1;i<=sqrt(x);i++) {
    if (x%i == 0) {
      fac.eb(i);
      if (x/i != i) fac.eb(x/i);
    }
  }
}
bool chk(int m){
  m = fac[m];
  for (int i=m-1;i<n;i+=m) {
    for (int j=m-1;j<n;j+=m) {
      if (dp[i][j] < m) return false;
    }
  }
  return true;
}
int main(){
  IOS();
  cin >> n;
  REP (i,n) {
    string s;
    cin >> s;
    int idx = 0;
    REP (j,n/4) {
      if (isdigit(s[j])) FILL(s[j]-'0',i,idx);
      else FILL(s[j]-'A'+10,i,idx);
    }
  }

  REP (i,n) dp[i][0] = 1;
  REP (i,n) dp[0][i] = 1;
  REP1 (i,n-1) REP1 (j,n-1) {
    int ta,tb,tc;
    ta = (g[i][j] == g[i][j-1])*dp[i][j-1];
    tb = (g[i][j] == g[i-1][j])*dp[i-1][j];
    tc = (g[i][j] == g[i-1][j-1])*dp[i-1][j-1];
    dp[i][j] = min({ta,tb,tc})+1;
  }

  factor(n);
  sort(ALL(fac));
  for (int i=SZ(fac)-1;i>=0;i--) {
    if (chk(i)) return cout << fac[i] << endl,0;
  }
}