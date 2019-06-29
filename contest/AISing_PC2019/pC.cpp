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

const ll MAXn=4e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll h,w;
ll d[MAXn][MAXn];
ll dsu[MAXn*MAXn],sz[MAXn*MAXn],bsz[MAXn*MAXn];
bitset<MAXn*MAXn> chk;
ll dx[] = {-1,0};
ll dy[] = {0,-1};
void init(){
  REP (i,h) REP (j,w) {
    if (d[i][j] == 1) bsz[i*w+j] = 1;
    sz[i*w+j] = 1, dsu[i*w+j] = i*w+j;
  }
}
ll fd(ll x){
  if (x == dsu[x]) return x;
  return dsu[x] = fd(dsu[x]);
}
void mrg(ll x,ll y){
  debug(x,y);
  x = fd(x), y = fd(y);
  if (x == y) return;
  if (sz[x] > sz[y]) swap(x,y);
  dsu[x] = y;
  sz[y] += sz[x];
  bsz[y] += bsz[x];
}
ll ok(ll x,ll y){
  return x<0 || x>=h || y<0 || y>=w;
}
void gogo(ll x,ll y){
  REP (i,2) {
    ll tx = x + dx[i], ty = y + dy[i];
    if (ok(tx,ty)) continue;
    debug(x,y,tx,ty);
    if (d[x][y] != d[tx][ty]) mrg(x*w+y,tx*w+ty);
  }
}
int main(){
  IOS();
  cin >> h >> w;
  REP (i,h) REP (j,w) {
    char x;
    cin >> x;
    if (x == '#') d[i][j] = 1;
    else d[i][j] = 0;
  }
  init();
  REP (i,h) REP (j,w) gogo(i,j);
  ll ans = 0;
  REP (i,h) REP (j,w) debug(dsu[i*w+j]);
  REP (i,h) REP (j,w) {
    ll tmp = fd(i*w+j);
    if (chk[tmp]) continue;
    debug(dsu[tmp],sz[tmp],bsz[tmp]);
    ans += (sz[tmp]-bsz[tmp]) * bsz[tmp];
    chk[tmp] = true;
  }
  cout << ans << endl;
}
