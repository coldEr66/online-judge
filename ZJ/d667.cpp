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

const ll MAXn=1e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

struct edge{
  ll to,cap,rev;
};
vector<edge> E[MAXn];
ll s,t,m;
ll lev[MAXn],it[MAXn];
ll T;
void addedge(ll from,ll to,ll cap){
  E[from].eb((edge){to,cap,SZ(E[to])});
  E[to].eb((edge){from,0,SZ(E[from])-1});
}
void BFS(){
  RST(lev,-1);
  queue<ll> q;
  lev[s] = 0;
  q.push(s);
  while(SZ(q)){
    ll cur = q.front();
    q.pop();
    for(auto i:E[cur]){
      if(i.cap > 0 && lev[i.to] < 0){
        lev[i.to] = lev[cur] + 1;
        q.push(i.to);
      }
    }
  }
}
ll dfs(ll v,ll f){
  if(v == t) return f;
  for(ll &i=it[v];i<SZ(E[v]);i++){
    edge &tmp = E[v][i];
    if(tmp.cap > 0 && lev[tmp.to] > lev[v]){
      ll d = dfs(tmp.to,min(f,tmp.cap));
      if(d){
        tmp.cap -= d;
        E[tmp.to][tmp.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}
ll Dinic(){
  ll flow = 0;
  for(;;){
    BFS();
    if(lev[t] < 0) return flow;
    RST(it,0);
    ll tmp;
    while((tmp = dfs(s,INF)) > 0) flow += tmp;
  }
}
int main(){
  IOS();
  ll n;
  while(cin >> n && n){
    REP(i,MAXn) E[i].clear();
    T++;
    cin >> s >> t >> m;
    s--,t--;
    REP(i,m){
      ll u,v,c;
      cin >> u >> v >> c;
      u--,v--;
      addedge(u,v,c);
      addedge(v,u,c);
    }
    ll ans = Dinic();
    cout << "Network " << T << endl;
    cout << "The bandwidth is " << ans << '.' << endl;
  }
}
