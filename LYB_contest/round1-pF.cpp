#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
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

const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

struct T{
  ll l,r,mi,ma;
} seg1[MAXn],seg2[MAXn];  //1存x+y,2存x-y
ll s[MAXn],sb[MAXn];
void build(ll id,ll l,ll r){
  seg1[id].l=seg2[id].l=l;
  seg1[id].r=seg2[id].r=r;
  if(l==r-1){
    seg1[id].mi=seg1[id].ma=s[l];
    seg2[id].mi=seg2[id].ma=sb[l];
    return;
  }
  if(l>=r) return;
  ll mid = (l+r)/2;
  build(id*2+1,l,mid);
  build(id*2+2,mid,r);
  seg1[id].mi=min(seg1[id*2+1].mi,seg1[id*2+2].mi);
  seg1[id].ma=max(seg1[id*2+1].ma,seg1[id*2+2].ma);
  seg2[id].mi=min(seg2[id*2+1].mi,seg2[id*2+2].mi);
  seg2[id].ma=max(seg2[id*2+1].ma,seg2[id*2+2].ma);
}
ll qrma(T *seg,ll id,ll l,ll r){
  if(seg[id].l==l && seg[id].r==r) return seg[id].ma;
  // if(seg[id].l<l && seg[id].r>r) return -INF;
  ll mid = (seg[id].l+seg[id].r)/2;
  if(r<=mid) return qrma(seg,id*2+1,l,r);
  else if(l>=mid) return qrma(seg,id*2+2,l,r);
  else return max(qrma(seg,id*2+1,l,mid),qrma(seg,id*2+2,mid,r));
}
ll qrmi(T *seg,ll id,ll l,ll r){
  if(seg[id].l==l && seg[id].r==r) return seg[id].mi;
  // if(seg[id].l>l && seg[id].r<r) return INF;
  ll mid = (seg[id].l+seg[id].r)/2;
  if(r<=mid) return qrmi(seg,id*2+1,l,r);
  else if(l>=mid) return qrmi(seg,id*2+2,l,r);
  else return min(qrmi(seg,id*2+1,l,mid),qrmi(seg,id*2+2,mid,r));
}
int main(){
  IOS();
  ll n; cin>>n;
  REP(i,n){
    ll x,y;
    cin>>x>>y;
    s[i] = x+y;
    sb[i] = x-y;
  }
  pary(s,s+n);
  pary(sb,sb+n);
  build(0,0,n);
  // REP(i,4*n){
  //   debug(seg2[i].ma,seg2[i].mi,i);
  // }
  ll q; cin>>q;
  while(q--){
    ll l,r;
    cin>>l>>r;
    if(l>r) swap(l,r);
    l--;
    if(r>n) r=n;
    if(l<0) l=0;
    ll ans = max(qrma(seg1,0,l,r)-qrmi(seg1,0,l,r),qrma(seg2,0,l,r)-qrmi(seg2,0,l,r));
    cout<<ans<<'\n';
  }
}
