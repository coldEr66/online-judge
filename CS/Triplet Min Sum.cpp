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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=(ll)1e18;

ll n,q;
vector<ll> g[MAXn];
ii d[MAXn];
bool vis[MAXn];
ll t,in[MAXn],out[MAXn];
ll an[MAXn][MAXlg];
ll dis[MAXn];
bool chk(ll x,ll y){
  return in[x]<=in[y] && out[x]>=out[y];
}
void dfs(ll cur,ll fa){
  in[cur] = t++;
  an[cur][0] = fa;
  if(cur!=fa) dis[cur] = dis[fa] + 1;
  for(int i=1;1<<i < n;i++) an[cur][i] = an[an[cur][i-1]][i-1];
  for(auto it:g[cur]){
    if(it==fa) continue;
    dfs(it,cur);
  }
  out[cur] = t++;
}
ll LCA(ll x,ll y){
  if(chk(x,y)) return x;
  if(chk(y,x)) return y;
  for(int i=__lg((int)n);i>=0;i--){
    if(!chk(an[x][i],y)) x = an[x][i];
  }
  return an[x][0];
}
ii sol(ll a,ll b,ll c){
  ll tmp = LCA(a,b);
  ll ret = INF;
  if(chk(tmp,c)) chkmin(ret,dis[a]+dis[b]+dis[c]-3*dis[tmp]);
  else if(chk(c,tmp)) chkmin(ret,dis[a]+dis[b]-dis[tmp]-dis[c]);
  else{
    ret = dis[a]+dis[b]-2*dis[tmp];
    ll lca = LCA(tmp,c);
    ret+=dis[tmp] + dis[c] -2*dis[lca];
  }
  return {ret,tmp};
}
int main(){
  IOS();
  cin>>n>>q;
  REP(i,n-1){
    ll a,b;
    cin>>a>>b;
    a--,b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  dis[0] = 0;
  dfs(0,0);
  pary(dis,dis+n);
  while(q--){
    ll a,b,c;
    cin>>a>>b>>c;
    a--,b--,c--;
    ii lca;
    ii ta = sol(b,c,a);
    ii tb = sol(a,c,b);
    ii tc = sol(a,b,c);
    debug(ta,tb,tc);
    vector<ii> v;
    v.pb(ta);
    v.pb(tb);
    v.pb(tc);
    sort(ALL(v));
    lca = v[0];
    cout<<lca.S + 1<<' '<<lca.F<<endl;
  }
}
