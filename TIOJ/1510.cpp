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

const ll MAXn=1e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

struct color{
  ll R,G,B;
};
map<color,ll> cnt;
bool operator < (const color a,const color b){
  if(a.R != b.R) return a.R<b.R;
  else if(a.G != b.G) return a.G<b.G;
  else return a.B<b.B;
}
ll e[4][MAXn][MAXn];
ll cal(ll x,ll y){
  ll tmp = x/y;
  if(tmp * y == x) return tmp;
  return tmp+1;
}
int main(){
  IOS();
  ll n;
  cin>>n;
  REP(T,n){
    ll x,y,u,v;
    cin>>x>>y>>u>>v;
    if(x > u) swap(x,u);
    if(y > v) swap(y,v);
    ll tmp[4];
    REP(i,3) cin>>tmp[i];
    tmp[3] = 1;
    REP(i,4){
      e[i][x][y] += tmp[i];
      e[i][x][v] -= tmp[i];
      e[i][u][y] -= tmp[i];
      e[i][u][v] += tmp[i];
    }
  }
  REP(T,4){
    REP(i,MAXn)REP1(j,MAXn-1) e[T][i][j] += e[T][i][j-1];
    REP(j,MAXn)REP1(i,MAXn-1) e[T][i][j] += e[T][i-1][j];
  }
  REP(i,MAXn)REP(j,MAXn){
    if(e[3][i][j]){
      ll tmp[3];
      REP(T,3) tmp[T] = cal(e[T][i][j],e[3][i][j]);
      cnt[{tmp[0],tmp[1],tmp[2]}]++;
    }
  }
  ll mx = 0;
  color ans;
  for(auto i:cnt)if(chkmax(mx,i.Y)) ans = i.X;
  debug(mx);
  cout<<ans.R<<' '<<ans.G<<' '<<ans.B<<endl;
}
