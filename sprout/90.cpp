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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=(ll)1e18;

ll d[MAXn],u[MAXn];
vector<ll> v;
map<ll,ll> ct;
ll n,m;

bool sol(ll x){ //true->ok,false->not
  map<ll,ll> tmp,tmp1=ct;
  debug("sol");
  REP(i,x) tmp[d[i]]++;
  REP(i,SZ(v)-1){
    debug("hi");
    if(i==SZ(v)-2) return tmp1[v[i]]<tmp[v[i]] ?false:true;
    else if(tmp1[v[i]]<tmp[v[i]]) return false;
    else{
      ll tp=v[i]/v[i+1];
      tmp1[v[i]]-=tmp[v[i]];
      tmp1[v[i+1]]+=tmp1[v[i]]*tp;
    }
  }
  return true;
}

int main(){
  IOS();
  ll t;
  cin>>t;
  while(t--){
    v.clear();
    ct.clear();
    RST(u,0);
    RST(d,0);
    cin>>n>>m;
    REP(i,n) cin>>u[i];
    REP(i,m) cin>>d[i];
    sort(d,d+m);
    sort(u,u+n,greater<ll>());
    v.pb(d[0]);
    v.pb(0);
    ll y=d[0];
    if(y!=1) v.pb(1);
    sort(ALL(v));
    REP(i,m){
      if(d[i]==y) continue;
      v.pb(d[i]);
      y=d[i];
    }
    sort(ALL(v),greater<ll>());
    debug(v);
    REP(i,n){
      ll cur=u[i];
      ll idx=0;
      while(cur>0){
        while(cur<v[idx] && idx<SZ(v)) idx++;
        ct[v[idx]]+=cur/v[idx];
        cur%=v[idx];
      }
    }
    debug("ok");
    ll l=0,r=m+1;
    while(l!=r-1){
      ll mid=(l+r)/2;
      if(sol(mid)) l=mid;
      else r=mid;
    }
    cout<<l<<endl;
  }
}
