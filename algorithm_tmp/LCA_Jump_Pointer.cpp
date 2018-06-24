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

const ll MAXn=3e4+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=(ll)1e18;

ll n,q;
vector<ll> g[MAXn];
ll in[MAXn],out[MAXn];
ll d[MAXn];
ll an[MAXn][MAXlg];
ll t=0;
bool chk(ll x,ll y){
  return in[x]<=in[y] && out[x]>=out[y];
}
void dfs(ll cur,ll fa){
  in[cur] = t++;
  if(cur!=fa) d[cur] = d[fa] + 1;
  an[cur][0] = fa;
  for(int i=1;1<<i < n;i++){
    an[cur][i] = an[an[cur][i-1]][i-1];
  }
  for(auto it:g[cur]){
    if(it==fa) continue;
    dfs(it,cur);
  }
  out[cur] = t++;
}
ll LCA(ll a,ll b){
  if(chk(a,b)) return a;
  if(chk(b,a)) return b;
  for(int i=__lg((int)n);i>=0;i--){
    if(!chk(an[a][i],b)) a = an[a][i];
  }
  return an[a][0];
}
int main(){
  IOS();
  cin>>n>>q;
  REP(i,n){
    ll tmp;
    while(cin>>tmp && tmp!=0) g[i].pb(tmp-1);
  }
  REP(i,n) d[i] = INF;
  d[0] = 0;
  dfs(0,0);
  pary(d,d+n);
  while(q--){
    ll a,b;
    cin>>a>>b;
    a--,b--;
    ll ans = LCA(a,b);   // calculate the LCA of a and b
    ll tmp = d[a]+d[b]-2*d[ans];  //calculate the distance from a to b
    cout<<ans + 1<<' '<<tmp<<endl;
  }
}
