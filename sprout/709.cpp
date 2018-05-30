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

vector<ll> g[MAXn];
ll vis[MAXn];
ll ans[MAXn];
ii d[MAXn];   //紀錄子樹總重量 , 紀錄子樹值總和
ll sum,n;
ll tmp[MAXn];
ii dfs1(ll x){
  vis[x]=1;
  for(auto it:g[x]){
    if(vis[it]) continue;
    d[x].F+=dfs1(it).F;
    d[x].S+=dfs1(it).S;
  }
  return {d[x].F+1,d[x].S+x};
}
void dfs2(ll x,ll fa){
  vis[x]=1;
  for(auto it:g[x]){
    if(vis[it]) continue;
    dfs2(it,x);
  }
  if(fa!=0) tmp[fa]=tmp[fa]+(d[x].S+x)*(n-d[x].F-2)+(sum-d[x].S-x-fa)*(d[x].F+1);
  tmp[x]=tmp[x]+(n-d[x].F-1)*d[x].S+d[x].F*(sum-d[x].S-x);
  debug(tmp[fa],fa);
  debug(tmp[x],x);
  //ans[fa]=ans[fa]+(sum-fa-d[fa].S)+d[fa].S*(n-d[fa].F-1);
}
int main(){
  IOS();
  cin>>n;
  sum=n*(n+1)/2;
  debug(sum);
  REP1(i,n) ans[i]=i*(n-2)+sum;
  pary(ans+1,ans+n+1);
  REP(i,n-1){
    ll a,b;
    cin>>a>>b;
    g[a].pb(b);
    g[b].pb(a);
  }
  dfs1(1);
  RST(vis,0);
  dfs2(1,0);
  pary(tmp+1,tmp+n+1);
  pary(d+1,d+n+1);
  REP1(i,n){
    tmp[i]/=2;
    ans[i]+=tmp[i];
  }
  REP1(i,n) cout<<ans[i]<<endl;
}
