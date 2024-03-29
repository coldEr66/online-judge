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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ii d[MAXn];
ll fa[MAXn],sz[MAXn],cnt[MAXn];
bool ok[MAXn];
ll fd(ll x){return fa[x] == x ?x:fd(fa[x]);}
void merge(ll x,ll y){
  x = fd(x), y = fd(y);
  if( x == y ) return;
  if( sz[x] < sz[y] ) swap(x,y);
  fa[y] = x;
  sz[x] += sz[y];
  sz[y] = 0;
}
int main(){
  IOS();
  ll n;
  cin>>n;
  ll ct = 0;
  REP(i,n){
    fa[i] = i;
    sz[i] = 1;
    ok[i] = false;
  }
  REP(i,n){
    cin>>d[i].X;
    d[i].Y = i;
  }
  sort(d,d+n);
  ll ans = d[0].X+1, ma = 0;
  REP(i,n){
    if( i != 0 && ct == 1 ){
      if( chkmax(ma,cnt[sz[fd(d[i-1].Y)]]) ) ans = d[i-1].X+1;
    }
    ll idx = d[i].Y;
    ok[idx] = true;
    cnt[1]++;
    if( cnt[1] == 1 ) ct++;
    if( idx+1<n && ok[idx+1] ){
      cnt[sz[fd(idx+1)]]--;
      if( sz[fd(idx+1)]!=0 && cnt[sz[fd(idx+1)]] == 0 ) ct--;
      cnt[sz[fd(idx)]]--;
      if( sz[fd(idx)]!=0 && cnt[sz[fd(idx)]] == 0 ) ct--;
      merge(idx,idx+1);
      cnt[sz[fd(idx)]]++;
      if( cnt[sz[fd(idx)]] == 1 ) ct++;
    }
    if( idx-1>=0 && ok[idx-1] ){
      cnt[sz[fd(idx-1)]]--;
      if( sz[fd(idx-1)]!=0 && cnt[sz[fd(idx-1)]] == 0 ) ct--;
      cnt[sz[fd(idx)]]--;
      if( sz[fd(idx)]!=0 && cnt[sz[fd(idx)]] == 0 ) ct--;
      merge(idx,idx-1);
      cnt[sz[fd(idx)]]++;
      if( cnt[sz[fd(idx)]] == 1 ) ct++;
    }
  }
  cout<<ans<<endl;
}
