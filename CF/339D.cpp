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
#define MP make_pair
#define VI vector<int>
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

const ll MAXn=(1<<18),MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=(ll)1e18;

vector<ll> v[20];
ll tmp[20];

void pw(){
  ll rt=1;
  REP(i,19){
    tmp[i]=rt;
    rt*=2;
  }
}

int main(){
  IOS();
  pw();
  ll n,m;
  cin>>n>>m;
  REP(i,tmp[n]){
    ll tp;
    cin>>tp;
    v[0].pb(tp);
  }
  bool fg=true;
  REP1(i,n){
    FOR(j,0,SZ(v[i-1]),2){
      if(fg){ //OR
        ll tp=v[i-1][j]|v[i-1][j+1];
        v[i].pb(tp);
      }
      else{ //XOR
        ll tp=v[i-1][j]^v[i-1][j+1];
        v[i].pb(tp);
      }
    }
    fg=!fg;
  }
  ll ans=v[n].back();
  debug(ans);
  REP(i,n+1) debug(v[i]);
  while(m--){
    fg=true;
    ll a,b,c,x,y,ok=0;
    cin>>a>>b;
    a--;
    debug(a,c);
    v[0][a]=b;
    x=a;
    REP1(i,n){
      debug(x);
      y=(x&1 ?x-1:x+1);
      if(fg){
        ll tp=v[i-1][x]|v[i-1][y];
        debug(tp);
        if(tp!=v[i][x/2]) v[i][x/2]=tp;
        else{
          cout<<ans<<endl;
          ok=1;
          break;
        }
      }
      else{
        ll tp=v[i-1][x]^v[i-1][y];
        debug(tp);
        if(tp!=v[i][x/2]) v[i][x/2]=tp;
        else{
          cout<<ans<<endl;
          ok=1;
          break;
        }
      }
      fg=!fg;
      x/=2;
      if(i==n) ans=v[n].back();
    }
    debug(ans);
    REP(i,n+1) debug(v[i]);
    if(!ok) cout<<ans<<endl;
  }
}
