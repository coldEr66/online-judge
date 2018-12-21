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

const ll MAXn=700+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

ll n,m,k,a,b;
vector<ii> e[MAXn];
ll d[MAXn];
ll dis[MAXn][MAXn];
bool vis[MAXn];
void dfs(ll x,ll fa,ll dep,ll root){
  chkmin(dis[x][root],dep);
  if(dep == 2) return;
  for(auto i:e[x])if(i.X != fa) dfs(i.X,x,dep+1,root);
}
int main(){
  IOS();
  cin>>n>>m>>k>>a>>b;
  RST(dis,INF);
  REP(i,m){
    ll u,v;
    cin>>u>>v;
    e[u].eb(v,a);
    e[v].eb(u,a);
  }
  REP1(i,n) dfs(i,i,0,i);
  REP1(i,n)for(ll j=i+1;j<=n;j++)if(dis[i][j] == 2){
    e[i].eb(j,b);
    e[j].eb(i,b);
  }
  REP1(i,n) debug(e[i]);
  RST(d,INF);
  d[k] = 0;
  MinHeap<ii> pq;
  pq.push(mkp(0,k));
  REP(i,n){
    ll tp = -1;
    while(SZ(pq) && vis[tp = pq.top().Y]) pq.pop();
    if(tp == -1) break;
    vis[tp] = true;
    for(auto it:e[tp]){
      if(d[it.X] > d[tp]+it.Y){
        d[it.X] = d[tp]+it.Y;
        pq.push(mkp(d[it.X],it.X));
      }
    }
  }
  REP1(i,n) cout<<d[i]<<endl;
}
