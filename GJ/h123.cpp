#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
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
#define F first
#define S second
#define pb push_back
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
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // cold66
//}

const ll MAXn=1e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=(ll)1e18;

struct E{
  ll to,w,lim,dcnt;
};
ll n,m,s,e,f;
ll a,b,c,d,cc;
vector<E> g[MAXn];
ll dis[MAXn];
bool vis[MAXn];
ll chk_cost(E tmp){
  ll ret=0;
  if(f>tmp.lim){
    ret+=tmp.w*tmp.lim;
    ret+=tmp.dcnt*(f-tmp.lim);
  }
  else ret+=f*tmp.w;
  return ret;
}
int main(){
  IOS();
  ll t;
  cin>>t;
  while(t--){
    REP(i,MAXn){
      vis[i] = false;
      dis[i] = INF;
      g[i].clear();
    }
    cin>>n>>m>>s>>e>>f;
    s--,e--;
    ll root = s;
    ll dst = e;
    while(m--){
      cin>>a>>b>>c>>d>>cc;
      E tmp;
      a--,b--;
      tmp.to = b;
      tmp.w = c;
      tmp.lim = d;
      tmp.dcnt = cc;
      g[a].pb(tmp);
    }
    REP(i,n) debug(SZ(g[i]));
    dis[root] = 0;
    debug(root,dst);
    REP(i,n){
      ll tp = -1,mn = INF;
      REP(j,n){
        if(!vis[j] && dis[j] < mn){
          tp = j;
          mn = dis[j];
        }
      }
      debug(tp);
      if(tp == -1) break;
      vis[tp] = true;
      REP(it,SZ(g[tp])){
        ll to = g[tp][it].to,ct = chk_cost(g[tp][it]);
        debug(ct);
        if(!vis[to] && dis[to] > dis[tp] + ct) dis[to] = dis[tp] + ct;
        debug(dis[to],to);
      }
    }
    cout<<dis[dst]<<endl;
  }
}
