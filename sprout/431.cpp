#include <bits/stdc++.h>
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

template<class T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=(ll)1e18;

ll n,m,q;
vector<ii> g1[MAXn],g2[MAXn];
ll d1[MAXn],d2[MAXn];
ll vis[MAXn];
void Dijkstra(bool c,ll st){
  MinHeap<ii> pq;
  RST(vis,0);
  if(c) pq.push({d1[st],st});
  else pq.push({d2[st],st});
  REP(i,n){
    ll tp = -1;
    while(SZ(pq) && vis[tp = pq.top().S]) pq.pop();
    debug(tp);
    if(tp==-1) break;
    vis[tp] = 1;
    if(c){
      for(ii it:g1[tp])if(!vis[it.F] && d1[it.F] > d1[tp] + it.S){
        debug(it);
        d1[it.F] = d1[tp] + it.S;
        pq.push({d1[it.F],it.F});
      }
    }
    else{
      for(ii it:g2[tp])if(!vis[it.F] && d2[it.F] > d2[tp] + it.S){
        d2[it.F] = d2[tp] + it.S;
        pq.push({d2[it.F],it.F});
      }
    }
  }
}
int main(){
  IOS();
  cin>>n>>m>>q;
  while(m--){
    ll a,b,w;
    cin>>a>>b>>w;
    a--,b--;
    g1[a].pb({b,w});
    g2[b].pb({a,w});
  }
  REP(i,MAXn){
    d1[i] = INF;
    d2[i] = INF;
  }
  d1[0] = 0;
  d2[n-1] = 0;
  Dijkstra(1,0);
  Dijkstra(0,n-1);
  pary(d1,d1+n);
  pary(d2,d2+n);
  ll ans = d1[n-1];
  debug(ans);
  while(q--){
    ll a,b;
    cin>>a>>b;
    a--,b--;
    ll tp = d1[a] + 1 + d2[b];
    cout<<min(ans,tp)<<endl;
  }
}
