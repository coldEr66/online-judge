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

ll d[MAXn];
map<ll,ll> tol;
int main(){
  IOS();
  ll n;
  cin>>n;
  REP(i,n-1) cin>>d[i];
  sort(d,d+n-1);
  if(n==2){
    if(d[0]==1) cout<<2<<endl;
    else cout<<1<<endl;
    return 0;
  }
  if(n==3){
    ll k=d[1]-d[0];
    if(d[0]>k) cout<<d[0]-k<<endl;
    else if(k%2==0) cout<<d[0]+k/2<<endl;
    else cout<<d[1]+k<<endl;
    return 0;
  }
  ll tp=-1;
  REP(i,n-2){
    tol[d[i+1]-d[i]]++;
    if(tol[d[i+1]-d[i]]>=2){
      tp=d[i+1]-d[i];
      break;
    }
  }
  if(tp==-1){
    ll mx=-1;
    REP(i,n-2) chkmax(mx,d[i+1]-d[i]);
    REP(i,n-2)if(d[i+1]-d[i]==mx) return cout<<d[i]+mx/2<<endl,0;
  }
  else{
    REP(i,n-2){
      if(d[i+1]-d[i]!=tp){
        return cout<<d[i]+tp<<endl,0;
      }
    }
  }
  if(d[0]-tp>0) cout<<d[0]-tp<<endl;
  else cout<<d[n-2]+tp<<endl;
}
