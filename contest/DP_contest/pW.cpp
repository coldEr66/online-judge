#include <bits/stdc++.h>
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
const ll INF=0x3f3f3f3f3f3f3f3f;

struct lr{
  ll l,r,v;
  bool operator < (const lr &a) const {
    return r < a.r;
  }
} d[MAXn];
ll n,m;
ll seg[MAXn<<1],t[MAXn<<1];
void app(ll x,ll v){
  seg[x] += v;
  if (x < n) t[x] += v;
}
void push(ll x){
  for (ll h=__lg(n)+1;h>0;h--) {
    ll cur = x>>h;
    if (t[cur]) {
      app(cur<<1,t[cur]);
      app(cur<<1|1,t[cur]);
      t[cur] = 0;
    }
  }
}
void pull(ll x){
  while (x > 1) {
    x >>= 1;
    seg[x] = max(seg[x<<1],seg[x<<1|1]) + t[x];
  }
}
void ins(ll l,ll r,ll v){
  l += n, r += n;
  ll tl = l, tr = r;
  for (;l<r;l>>=1,r>>=1) {
    if (l&1) app(l++,v);
    if (r&1) app(--r,v);
  }
  pull(tl), pull(tr-1);
}
ll qr(ll l,ll r){
  ll ret = -INF;
  l += n, r += n;
  push(l), push(r-1);
  for (;l<r;l>>=1,r>>=1) {
    if (l&1) ret = max(ret,seg[l++]);
    if (r&1) ret = max(ret,seg[--r]);
  }
  return ret;
}
int main(){
  IOS();
  cin >> n >> m;
  REP (i,m) {
    cin >> d[i].l >> d[i].r >> d[i].v;
    d[i].l--, d[i].r--;
  }
  sort(d,d+m);

  ll idx = 0;
  REP (i,n) {
    ll tp = max(0LL,qr(0,i));
    ins(i,i+1,tp);
    while (idx < m && d[idx].r == i) ins(d[idx].l,d[idx].r+1,d[idx].v),idx++;
  }
  cout << max(0LL,qr(0,n)) << endl;
}
