#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
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

const ll MAXn=55,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

ll n;
char g[MAXn][MAXn];
ll d1[MAXn][MAXn],d2[MAXn][MAXn];
ll dx[] = {1,0,0,-1};
ll dy[] = {0,-1,1,0};
bool chk(ll x,ll y){
  return x<0 || x>=n || y<0 || y>=n;
}
void BFS(ll x,ll y,ll d[55][55]){
  REP (i,n) REP (j,n) d[i][j] = INF;
  queue<ii> q;
  q.push({x,y});
  d[x][y] = 0;
  while (SZ(q)) {
    ii cur = q.front();
    q.pop();
    REP (i,4) {
      ll tpx = cur.X + dx[i], tpy = cur.Y + dy[i];
      if (chk(tpx,tpy)) continue;
      if (g[tpx][tpy] == '1') continue;
      if (d[tpx][tpy] > d[cur.X][cur.Y] + 1) {
        d[tpx][tpy] = d[cur.X][cur.Y] + 1;
        q.push({tpx,tpy});
      }
    }
  }
}
int main(){
  IOS();
  cin >> n;
  ll sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;
  sx--,sy--;
  tx--,ty--;
  REP (i,n) REP (j,n) cin >> g[i][j];
  debug("HI");

  BFS(sx,sy,d1);
  BFS(tx,ty,d2);
  REP (i,n) pary(d1[i],d1[i]+n);
  REP (i,n) pary(d2[i],d2[i]+n);
  ll ans = INF;
  debug(d1[tx][ty],d2[sx][sy],INF);
  if (d1[tx][ty] != INF || d2[sx][sy] != INF) ans = 0;
  debug(ans);
  REP (i,n) REP (j,n) REP (u,n) REP (v,n) {
    if (d1[i][j] != INF && d2[u][v] != INF) {
      ans = min(ans,(i-u)*(i-u) + (j-v)*(j-v));
      debug(d1[i][j],d2[u][v],i,j,u,v);
    }
  }
  cout << ans << endl;
}
