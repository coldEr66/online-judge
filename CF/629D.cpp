#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
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

const ll MAXn=1e5+50,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;
const lf PI=acos(-1);

ll d[MAXn];
ll dp[MAXn],pos[MAXn];
vector<ll> id;
ll seg[MAXn*2];
ll n;
bool cmp(const ll &a,const ll &b){
  if( d[a]!=d[b] ) return d[a]<d[b];
  else return a<b;
}
void ins(ll i,ll v){
  for( seg[i+=n]=v;i>1;i>>=1 ) seg[i>>1] = max(seg[i],seg[i^1]);
}
ll qr(ll l,ll r){
  ll ret=0;
  for( l+=n,r+=n;l<r;l>>=1,r>>=1 ){
    if( l&1 ) chkmax(ret,seg[l++]);
    if( r&1 ) chkmax(ret,seg[--r]);
  }
  return ret;
}
int main(){
  IOS();
  cin>>n;
  id.eb(0);
  REP1(i,n){
    ll a,b;
    cin>>a>>b;
    d[i] = a*a*b;
    id.eb(d[i]);
  }
  n++;
  sort(ALL(id));
  id.resize(unique(ALL(id))-id.begin());
  debug("HI");
  REP(i,n) pos[i] = (ll)(lower_bound(ALL(id),d[i])-id.begin());
  pary(pos,pos+n);
  ll ans=0;
  REP1(i,n-1){
    ll tmp=qr(0,pos[i]);
    debug(tmp);
    dp[i] = tmp+d[i];
    ins(pos[i],dp[i]);
  }
  REP(i,n) chkmax(ans,dp[i]);
  debug(ans);
  cout<<fixed<<setprecision(15)<<(lf)ans*PI<<endl;
}
