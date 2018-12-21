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

template<class T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

const ll MAXn=2e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

ll n,m,k;
vector<ii> e[MAXn];
ll ans;
bool fg=true;
void dij(){
  ll dis[MAXn];
  REP(i,n) dis[i] = INF;
  bool vis[MAXn] = {};
  ii fa[MAXn];
  REP(i,n) fa[i]=mkp(0,0);
  MinHeap<ii> pq;
  dis[0]=0;
  pq.push(mkp(dis[0],0));
  REP(i,n){
    ll tp=-1;
    while( SZ(pq) && vis[tp = pq.top().Y] ) pq.pop();
    // debug(tp);
    if( tp==-1 ) break;
    vis[tp]=true;
    for( ii it:e[tp] ){
      if( !vis[it.Y] && dis[it.Y]>dis[tp]+it.X ){
        dis[it.Y] = dis[tp]+it.X;
        fa[it.Y] = mkp(it.X,tp);
        pq.push(mkp(dis[it.Y],it.Y));
      }
    }
  }
  debug(dis[n-1]);
  if(dis[n-1]==INF) fg=false;
  else{
    // REP(i,n) debug(fa[i]);
    ll tmp=n-1;
    while(tmp){
      // debug(tmp);
      auto it=lower_bound(ALL(e[fa[tmp].Y]),mkp(fa[tmp].X,tmp));
      e[fa[tmp].Y].erase(it);
      ans+=fa[tmp].X;
      tmp=fa[tmp].Y;
      debug(tmp);
    }
  }
}
int main(){
  IOS();
  cin>>n>>m>>k;
  REP(i,m){
    ll a,b,c;
    cin>>a>>b>>c;
    a--,b--;
    e[a].pb(mkp(c,b));
  }
  REP(i,n) sort(ALL(e[i]));
  REP(i,k){
    dij();
    if( !fg ) return cout<<-1<<endl,0;
  }
  // REP(i,n) debug(e[i]);
  cout<<ans<<endl;
}
