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

vector<int> g[MAXn];
int adj[MAXn];
vector<ii> ed;
int main(){
  IOS();
  int n,m;
  cin>>n>>m;
  int k=300;
  debug(k);
  REP(i,m){
    int a,b;
    cin>>a>>b;
    if(a>b) swap(a,b);
    ed.pb({a,b});
    g[a].pb(b);
    g[b].pb(a);
  }
  REP(i,n) sort(ALL(g[i]));
  debug(ed);
  int ans=0,tp=0;
  tp++;
  REP(i,n){
    ll TMD=SZ(g[i]);
    if(TMD>k){
      for(auto it:g[i]) adj[it]=tp;
      REP(j,m){
        ii cur=ed[j];
        if(adj[cur.F]==tp && adj[cur.S]==tp) ans++;
      }
      tp++;
    }
    else{
      REP(j,TMD){
        for(int u=j+1;u<TMD;u++){
          int l=0,r=SZ(g[g[i][j]]);
          ll cur=g[i][u];
          while(l!=r-1){
            int mid=(l+r)/2;
            if(g[g[i][j]][mid]<=cur) l=mid;
            else r=mid;
          }
          if(g[g[i][j]][l]==cur) ans++;
        }
      }
    }
  }
  debug(ans);
  ans/=3;
  cout<<ans<<endl;
}
