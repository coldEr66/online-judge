#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
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

const ll MAXn=4e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;
const ll MAXai=3e2+5;

ll n,q;
ll mask[MAXn<<1],seg[MAXn<<1],t[MAXn<<1],len[MAXn<<1],tt[MAXn<<1];
vector<ll> prime,invp;
bitset<MAXn> isp;
ll mul(ll x,ll y){
  return (x * y) % MOD;
}
ll fpow(ll x,ll a){
  ll ret = 1, base = x;
  while (a) {
    if (a&1) ret = mul(ret,base);
    base = mul(base,base);
    a >>= 1;
  }
  return ret;
}
void init(){
  for (ll i=2;i<MAXai;i++) {
    if (!isp[i]) prime.eb(i);
    for (ll j=0;i*prime[j]<MAXai;j++) {
      isp[i*prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
  REP (i,SZ(prime)) {
    ll tmp = fpow(prime[i],MOD-2);
    invp.eb(tmp);
  }
}
void app(ll x,ll v,ll msk){
  seg[x] = mul(seg[x],fpow(v,len[x]));
  mask[x] = mask[x] | msk;
  debug(v);
  if (x < n) {
    t[x] = mul(t[x],v);
    tt[x] = tt[x] | msk;
  }
}
void push(ll x){
  for (ll h=__lg(n)+1;h>0;h--){
    ll cur = x>>h;
    debug(t[cur],cur);
    if (t[cur] > 1 || tt[cur] != 0) {
      app(cur<<1,t[cur],tt[cur]);
      app(cur<<1|1,t[cur],tt[cur]);
      t[cur] = 1;
      tt[cur] = 0;
    }
  }
}
void pull(ll x){
  while (x > 1) {
    x >>= 1;
    seg[x] = mul(mul(seg[x<<1],seg[x<<1|1]),fpow(t[x],len[x]));
    mask[x] = mask[x<<1] | mask[x<<1|1] | tt[x];
  }
}
void build(){
  for (ll i=n-1;i>0;i--) {
    seg[i] = mul(seg[i<<1],seg[i<<1|1]);
    mask[i] = mask[i<<1] | mask[i<<1|1];
    len[i] = len[i<<1] + len[i<<1|1];
    t[i] = 1LL;
    tt[i] = 0;
  }
}
void ins(ll l,ll r,ll v,ll msk){
  l += n, r += n;
  ll tl = l, tr = r;
  for (;l<r;l>>=1,r>>=1) {
    if (l&1) app(l++,v,msk);
    if (r&1) app(--r,v,msk);
  }
  pull(tl), pull(tr-1);
}
ii qr(ll l,ll r){
  l += n, r += n;
  push(l), push(r-1);
  ll v = 1, msk = 0;
  for (;l<r;l>>=1,r>>=1) {
    if (l&1) {
      v = mul(v,seg[l]);
      msk |= mask[l];
      l++;
    }
    if (r&1) {
      r--;
      v = mul(v,seg[r]);
      msk |= mask[r];
    }
  }
  return {v,msk};
}
int main(){
  IOS();
  init();
  debug(prime);
  cin >> n >> q;
  REP (i,n) {
    cin >> seg[i+n];
    ll msk = 0;
    REP (j,SZ(prime)) {
      if (seg[i+n] % prime[j] == 0) {
        msk |= (1LL<<j);
      }
    }
    mask[i+n] = msk;
    len[i+n] = 1LL;
    t[i+n] = 1LL;
  }
  build();
  while (q--) {
    pary(t,t+2*n);
    string cmd;
    cin >> cmd;
    if (cmd[0] == 'M') {
      ll l,r,x;
      cin >> l >> r >> x;
      l--;
      ll msk = 0;
      REP (j,SZ(prime)) {
        if (x % prime[j] == 0) {
          msk |= (1LL<<j);
        }
      }
      ins(l,r,x,msk);
      debug("ins_ok");
    }
    else {
      ll l,r;
      cin >> l >> r;
      l--;
      ii ans = qr(l,r);
      debug(ans);
      REP (i,63) if ((1LL<<i)&ans.Y) {
        ans.X = mul(ans.X,mul(prime[i]-1,invp[i]));
      }
      cout << ans.X << endl;
    }
  }
}
