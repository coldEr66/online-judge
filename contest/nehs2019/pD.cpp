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

const ll MAXn=15,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;
const ll MAXk=105;

int n,m,k;
int d[MAXn][MAXn],dd[MAXn][MAXn];
deque<int> Fill,tmp;
int dx[] = {-1,0};
int dy[] = {0,-1};
bool ok[MAXn][MAXn];
bool chk(int x,int y){
  return x<0 || x>=n || y<0 || y>=m;
}
int clr(){
  int ret = 0;
  RST(ok,0);
  REP (i,n) {
    REP (j,m-2) {
      if (dd[i][j] == 0) continue;
      if (dd[i][j] != dd[i][j+1]) continue;
      int idx = j;
      while (idx < m && dd[i][j] == dd[i][idx]) idx++;
      if (idx-j >= 3) {
        for (int u=j;u<idx;u++) ok[i][u] = 1;
        j = idx-1;
      }
    }
  }
  REP (i,m) {
    REP (j,n-2) {
      if (dd[j][i] == 0) continue;
      if (dd[j][i] != dd[j+1][i]) continue;
      int idx = j;
      while (idx < n && dd[j][i] == dd[idx][i]) idx++;
      if (idx-j >= 3) {
        for (int u=j;u<idx;u++) ok[u][i] = 1;
        j = idx-1;
      }
    }
  }
  REP (i,n) REP (j,m) if (ok[i][j]) dd[i][j] = 0,ret++;
  // debug(ret);
  return ret;
}
void fall(){
  REP (j,m) {
    for (int i=n-1;i>=0;i--) {
      if (dd[i][j] != 0) continue;
      int idx = i;
      while (idx >= 0 && dd[idx][j] == 0) idx--;
      if (idx == -1) i = idx+1;
      else swap(dd[idx][j],dd[i][j]);
    }
  }
}
bool FILL(){
  REP (j,m) {
    for (int i=n-1;i>=0;i--) {
      if (dd[i][j] != 0) continue;
      if (!SZ(tmp)) return false;
      debug(SZ(tmp));
      dd[i][j] = tmp.front();
      tmp.pop_front();
    }
  }
  return true;
}
int cal(){
  int ret = 0;
  int tp = 0;
  while ((tp = clr())) {
    // debug(tp);
    fall();
    if (FILL() == false) return -1;
    else ret += tp;
    REP (i,n) pary(dd[i],dd[i]+m);
  }
  return ret;
}
int trr(int x,int y){
  int ret = 0;
  REP (T,2) {
    int tx = x + dx[T], ty = y+dy[T];
    if (chk(tx,ty)) continue;
    swap(d[x][y],d[tx][ty]);
    REP (i,n) REP (j,m) dd[i][j] = d[i][j];
    swap(d[x][y],d[tx][ty]);
    tmp = Fill;
    int tp = cal();
    // debug(tp);
    if (tp == -1) return -1;
    ret = max(ret,tp);
  }
  return ret;
}
int main(){
  IOS();
  int t;
  cin >> t;
  while (t--) {
    Fill.clear();
    tmp.clear();
    cin >> n >> m >> k;
    REP (i,n) REP (j,m) cin >> d[i][j];
    REP (i,k) {
      int x;
      cin >> x;
      Fill.eb(x);
    }
    int ans = 0;
    REP (i,n) {
      REP (j,m) {
        int cnt = trr(i,j);
        debug(cnt);
        if (cnt == -1) {
          ans = -1;
          break;
        }
        else ans = max(ans,cnt);
      }
      if (ans == -1) break;
    }
    cout << ans << endl;
  }
}
