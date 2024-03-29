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
#define pob pop_back
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll mylog(ll x){
  ll ret=0;
  while( x ){
    ret++;
    x/=10;
  }
  debug(ret);
  return ret-1;
}
ll mypow(ll x,ll y){
  ll ret=1;
  while( y ){
    if( y&1 ) ret*=x;
    x*=x;
    y>>=1;
  }
  return ret;
}
ll sol(ll x){
  if( x==0 ) return 0;
  ll ret=0;
  ll len = (ll)floor(mylog(x))+1;
  if( len==1 ) return x;
  ll ex = mypow(10,len-1);
  ll tmp = x/ex;
  debug(len,tmp);
  REP1(i,len-1) ret+=9*mypow(10,max(i-2,0LL));
  debug(ret);
  ret+=(tmp-1)*mypow(10,max(len-2,0LL));
  ll l=x%10;
  debug(ex,x);
  x%=ex;
  x/=10;
  x++;
  debug(x);
  ret+=x;
  // if( !tmp ) tmp+=10;
  debug(l,tmp);
  if( l<tmp ) ret--;
  debug(ret);
  return ret;
}
int main(){
  IOS();
  ll l,r;
  cin>>l>>r;
  cout<<sol(r)-sol(l-1)<<endl;
}
