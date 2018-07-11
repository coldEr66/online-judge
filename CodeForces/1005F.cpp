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

const int MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const int INF=0x3f3f3f3f;

int n,m,k;
int dis[MAXn];
vector<int> adj[MAXn],fa[MAXn];
vector<string> ans;
void build(){
  queue<int> q;
  q.push(0);
  dis[0] = 0;
  while(SZ(q)){
    int cur = q.front();
    q.pop();
    for(auto it:adj[cur]){
      if(dis[it]>=0) continue;
      dis[it] = dis[cur]+1;
      q.push(it);
    }
  }
}
void dfs(int cur,string &s){
  if(SZ(ans)>=k) return;
  if(cur==n){
    ans.eb(s);
    return;
  }
  for(auto it:fa[cur]){
    s[it] = '1';
    dfs(cur+1,s);
    s[it] = '0';
    if(SZ(ans)>=k) return;
  }
}
int main(){
  IOS();
  cin>>n>>m>>k;
  vector<int> u(m),v(m);
  RST(dis,-1);
  REP(i,m){
    cin>>u[i]>>v[i];
    u[i]--,v[i]--;
    adj[u[i]].eb(v[i]);
    adj[v[i]].eb(u[i]);
  }
  build();
  pary(dis,dis+n);
  REP(i,m){
    if(dis[u[i]]==dis[v[i]]) continue;
    if(dis[u[i]]<dis[v[i]]) fa[v[i]].eb(i);
    else fa[u[i]].eb(i);
  }
  string s(m,'0');
  dfs(1,s);
  cout<<SZ(ans)<<'\n';
  REP(i,SZ(ans)) cout<<ans[i]<<'\n';
}
