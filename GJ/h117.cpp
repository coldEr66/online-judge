#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <bitset>
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
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
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

const ll MAXn=1e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=(ll)1e18;

ii d[MAXn];
vector<ii> e[MAXn];
bitset<MAXn> vis;
ll dis[MAXn];
ll sq(ll x){return x*x;}
ll dist(ll i,ll j){
  return ceil((lf)sqrt(sq(d[i].X-d[j].X)+sq(d[i].Y-d[j].Y)));
}
int main(){
  IOS();
  ll t;
  cin>>t;
  while(t--){
    vis.reset();
    ll n;
    cin>>n;
    REP(i,n) dis[i] = INF;
    REP(i,n) e[i].clear();
    REP(i,n) cin>>d[i].X>>d[i].Y;
    REP(i,n)for(ll j=i+1;j<n;j++){
      ll tmp = dist(i,j);
      e[i].pb(mkp(j,tmp));
      e[j].pb(mkp(i,tmp));
    }
    ll ans=0;
    dis[0]=0;
    REP(i,n){
      ll tp=-1,tmp=INF;
      REP(j,n)if( !vis[j] && dis[j]<tmp ) tp=j,tmp=dis[j];
      debug(tp);
      if( tp==-1 ) break;
      debug(tmp);
      ans = max(ans,tmp);
      vis[tp] = true;
      REP(j,SZ(e[tp]))if( !vis[e[tp][j].X] && e[tp][j].Y<dis[e[tp][j].X] )
        dis[e[tp][j].X] = e[tp][j].Y;
    }
    cout<<(ans+1)/2<<endl;
  }
}
