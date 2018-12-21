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

const ll MAXn=1e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll n,k;
string s[MAXn];
ll ok[MAXn][15];
ll dx[] = {1,0,0,-1};
ll dy[] = {0,1,-1,0};
bool chk(ll x,ll y){
  return x>=n || x<0 || y<0 || y>=10;
}
ll dfs(ll i,ll j,ll c,char cc){
  ok[i][j] = c;
  ll ret = 1;
  REP (u,4) {
    ll tx = i+dx[u];
    ll ty = j+dy[u];
    if (chk(tx,ty)) continue;
    if (s[tx][ty] != cc) continue;
    if (c == 1 && ok[tx][ty] != 0) continue;
    if (c == 2 && ok[tx][ty] == 2) continue;
    ret += dfs(tx,ty,c,cc);
  }
  return ret;
}
bool sol(){
  bool ret = false;
  RST(ok,0);
  REP (i,n) {
    REP (j,10) {
      if (!ok[i][j] && s[i][j] != '0') {
        ll x = dfs(i,j,1,s[i][j]);
        debug(x,i,j);
        if (x >= k) {
          dfs(i,j,2,s[i][j]);
          ret = true;
        }
      }
    }
  }
  return ret;
}
void fall(){
  ll idx = n-1;
  while (idx >= 0) {
    bool fg = false;
    REP (j,10) {
      if (ok[idx][j] == 2) {
        fg = true;
        for (ll u=idx-1;u>=0;u--) {
          s[u+1][j] = s[u][j];
          ok[u+1][j] = ok[u][j];
        }
        s[0][j] = '0';
        ok[0][j] = 0;
      }
    }
    if (!fg) idx--;
  }
  REP (i,n) debug(s[i]);
}
int main(){
  IOS();
  freopen("mooyomooyo.in","r",stdin);
  freopen("mooyomooyo.out","w",stdout);

  cin >> n >> k;
  REP (i,n) cin >> s[i];

  while (sol()) {
    REP(i,n) pary(ok[i],ok[i]+10);
    fall();
  }

  REP (i,n) cout << s[i] << endl;
}
