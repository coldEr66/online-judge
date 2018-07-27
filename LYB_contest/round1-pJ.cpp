#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
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
const ll INF=0x3f3f3f3f3f3f3f3f;

ll n,m,x,y;
ll vis[MAXn];
void dij(ll st,vector<ii> *adj,ll *dis){
  RST(vis,0);
  MinHeap<ii> pq;
  // debug(st);
  REP(i,n) dis[i] = INF;
  dis[st] = 0;
  pq.push(mkp(dis[st],st));
  REP(i,n){
    // debug("hi");
    ll tp = -1;
    while(SZ(pq) && vis[tp = pq.top().Y]) pq.pop();
    if(tp==-1) break;
    // debug(tp);
    vis[tp] = 1;
    for(auto it:adj[tp]){
      // debug(vis[it.X]);
      REP(k,SZ(adj[tp])){
        // debug(adj[tp][k].X,i);
      }
      if(!vis[it.X] && dis[it.X]>dis[tp]+it.Y){
        // debug(dis[it.X]);
        dis[it.X] = dis[tp]+it.Y;
        pq.push(mkp(dis[it.X],it.X));
      }
    }
  }
}
ll d1[MAXn],d2[MAXn];
vector<ii> adj1[MAXn],adj2[MAXn];
int main(){
  IOS();
  while(cin>>n>>m>>x>>y){
    x--,y--;
    REP(i,n){
      adj1[i].clear();
      adj2[i].clear();
    }
    REP(i,m){
      ll a,b,c;
      cin>>a>>b>>c;
      a--,b--;
      adj1[a].eb(mkp(b,c));
      adj2[b].eb(mkp(a,c));
    }
    dij(x,adj1,d1);
    dij(y,adj2,d2);
    pary(d1,d1+n);
    pary(d2,d2+n);
    ll q; cin>>q;
    while(q--){
      ll qr;  cin>>qr;
      qr--;
      if(d1[qr]==INF || d2[qr]==INF) cout<<-1<<'\n';
      else cout<<d1[qr]+d2[qr]<<'\n';
    }
  }
}
