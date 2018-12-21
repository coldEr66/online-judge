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

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int n,q;
int d[MAXn],chk[MAXn];
int seg[MAXn*2];
vector<int> e[MAXn];
int qr(int l,int r){
  int ret = INF;
  for(l+=n,r+=n;l<r;l>>=1,r>>=1){
    if( l&1 ) chkmin(ret,seg[l++]);
    if( r&1 ) chkmin(ret,seg[--r]);
  }
  return ret;
}
int main(){
  IOS();
  cin>>n>>q;
  REP(i,n) cin>>d[i];
  REP(i,n)if( !d[i] ){
    chk[i] = 1;
    if( i == 0 ) d[i] = 1;
    else d[i] = d[i-1];
  }
  REP(i,n) seg[i+n] = d[i];
  for(int i=n-1;i>0;i--) seg[i] = min(seg[i<<1],seg[i<<1|1]);
  REP(i,n) e[d[i]].eb(i);
  REP1(i,q){
    REP(j,SZ(e[i])-1){
      if( qr(e[i][j],e[i][j+1]) < i ) return cout<<"NO"<<endl,0;
    }
  }
  bool fg = false;
  REP(i,n)if( d[i] == q ) fg = true;
  REP(i,n){
    if( chk[i] && !fg ){
      d[i] = q;
      fg = true;
      break;
    }
  }
  if( !fg ) return cout<<"NO"<<endl,0;
  cout<<"YES"<<endl;
  REP(i,n) cout<<d[i]<<(i==n-1 ?'\n':' ');
}
