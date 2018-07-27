#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,j,n,m) for(int i=j;i<n;i+=m)
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
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.F<<","<<_p.S<<")";}
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
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // cold66
//}

template<class T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

const ll MAXn=4e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

ll n;
ll dx[] = {1,0,0,-1};
ll dy[] = {0,1,-1,0};
ll d[22][22];
ll dis[MAXn][MAXn];
bool chk(ll x,ll y){
  if(x<0 || x>=n || y<0 || y>=n) return true;
  return false;
}
ll id(ll i,ll j){return i*n+j;}
ii reid(ll x){return mkp(x/n,x%n);}
void build(){
  REP(k,n*n)REP(i,n*n)REP(j,n*n){
    // debug(reid(k).X,reid(k).Y);
    dis[i][j] = dis[j][i] = min({dis[i][j],dis[j][i],dis[i][k]+dis[k][j]-d[reid(k).X][reid(k).Y]});
  }
}
int main(){
  IOS();
  cin>>n;
  REP(i,n*n)REP(j,n*n) dis[i][j] = INF;
  REP(i,n)REP(j,n){
    cin>>d[i][j];
    dis[id(i,j)][id(i,j)] = d[i][j];
  }
  REP(i,n)REP(j,n){
    REP(k,4){
      ll x = i+dx[k] , y = j+dy[k];
      if(chk(x,y)) continue;
      ll tmp = id(x,y);
      // debug(tmp);
      dis[id(i,j)][tmp] = dis[tmp][id(i,j)] = d[i][j] + d[x][y];
      // debug(dis[id(i,j)][tmp],x,y,d[x][y],i,j);
    }
  }
  debug("hi");
  build();
  debug("hi");
  ll q; cin>>q;
  REP(i,n*n) pary(dis[i],dis[i]+n*n);
  while(q--){
    ll a,b,u,v;
    cin>>a>>b>>u>>v;
    a--,b--,u--,v--;
    ll st = id(a,b);
    ll dst = id(u,v);
    debug(st,dst);
    ll ans = INF;
    REP(k,n*n){
      ii x = reid(k);
      ll tmp = dis[st][k] + dis[k][dst] - 2*d[x.X][x.Y];
      // debug(dis[st][k],dis[k][dst]);
      ans = min(ans,tmp);
    }
    cout<<ans<<'\n';
  }
}
