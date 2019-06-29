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
const ll INF=0x3f3f3f3f;

struct node{
  ll l,r;
  ll sum,tg;
} seg[MAXn*4];
ll d[MAXn],k[MAXn],pre[MAXn];
ll gt(ll id){
  if (seg[id].tg == -INF) return seg[id].sum;
  return (seg[id].r-seg[id].l) * seg[id].tg + pre[seg[id].r] - pre[seg[id].l];
}
void pull(ll id){
  ll lc = gt(id*2+1);
  ll rc = gt(id*2+2);
  seg[id].sum = lc + rc;
}
void push(ll id){
  if (seg[id].tg == -INF) return;
  seg[id].sum = (seg[id].r-seg[id].l) * seg[id].tg + pre[seg[id].r] - pre[seg[id].l];
  seg[id*2+1].tg = seg[id].tg;
  seg[id*2+2].tg = seg[id].tg;
  seg[id].tg = -INF;
}
void build(ll id,ll l,ll r){
  seg[id].l = l, seg[id].r = r;
  seg[id].tg = -INF;
  if (l == r-1) {
    seg[id].sum = d[l];
    return;
  }
  ll mid = (l+r)>>1;
  build(id*2+1,l,mid);
  build(id*2+2,mid,r);
  pull(id);
}
void ins(ll id,ll l,ll r,ll v){
  if (seg[id].l == l && seg[id].r == r) {
    seg[id].tg = v;
    return;
  }
  push(id);
  ll mid = (seg[id].l + seg[id].r)>>1;
  if (r <= mid) ins(id*2+1,l,r,v);
  else if (l >= mid) ins(id*2+2,l,r,v);
  else {
    ins(id*2+1,l,mid,v);
    ins(id*2+2,mid,r,v);
  }
  pull(id);
}
ll qr(ll id,ll l,ll r){
  push(id);
  if (seg[id].l == l && seg[id].r == r) {
    return seg[id].sum;
  }
  ll mid = (seg[id].l + seg[id].r)>>1;
  if (r <= mid) return qr(id*2+1,l,r);
  else if (l >= mid) return qr(id*2+2,l,r);
  return qr(id*2+1,l,mid) + qr(id*2+2,mid,r);
}
int main(){
  IOS();
  ll n;
  cin >> n;
  REP (i,n) cin >> d[i];
  REP1 (i,n-1) {
    cin >> k[i];
    k[i] += k[i-1];
  }
  REP1 (i,n) pre[i] = pre[i-1] + k[i-1];

  build(0,0,n);
  debug("BUILD_OK");
  ll q;
  cin >> q;
  while (q--) {
    char cmd;
    cin >> cmd;
    if (cmd == '+') {
      ll x,v;
      cin >> x >> v;
      x--;
      ll tmp = qr(0,x,x+1);
      ll l=x, r=n;
      while (l != r-1) {
        debug(l,r);
        ll mid = (l+r)>>1;
        if (tmp + v + k[mid] - k[x] > qr(0,mid,mid+1)) l = mid;
        else r = mid;
      }
      ins(0,x,r,tmp+v-k[x]);
      debug("INS_OK");
    }
    else {
      ll l,r;
      cin >> l >> r;
      cout << qr(0,l-1,r) << endl;
    }
  }
}
