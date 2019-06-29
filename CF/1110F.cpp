#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
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

const ll MAXn=5e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

struct qry{
  ll l,r,id;
};
vector<qry> Q[MAXn];
vector<ii> e[MAXn];
ll ans[MAXn],dep[MAXn];
ll seg[MAXn],t[MAXn];
ll idx,ct;
ii lr[MAXn];
ll lf1[MAXn],lf2[MAXn],lf[MAXn];
ii dfs(ll x,ll p,ll d){
  dep[x] = d;
  ll l=INF, r=-INF;
  if (SZ(e[x]) == 1) {
    lf[x] = idx;
    seg[idx] = dep[x];
    idx++;
    ct++;
    return lr[x] = {lf[x],lf[x]};
  }
  for (auto i:e[x]) {
    if (i.X == p) continue;
    ii tmp = dfs(i.X,x,d + i.Y);
    l = min(l,tmp.X);
    r = max(r,tmp.Y);
  }

  return lr[x] = {l,r};
}
void build(){
  REP (i,ct) seg[i+ct] = seg[i];
  for (ll i=ct-1;i>0;i--) {
    seg[i] = min(seg[i<<1],seg[i<<1|1]);
  }
}
void app(ll x,ll v){
  seg[x] += v;
  if (x < ct) t[x] += v;
}
void push(ll x){
  ll h = __lg(ct)+1;
  for (ll i=h;i>0;i--) {
    ll cur = x>>i;
    if (t[cur] != 0) {
      app(cur<<1,t[cur]);
      app(cur<<1|1,t[cur]);
      t[cur] = 0;
    }
  }
}
void pull(ll x){
  while (x > 1) {
    x >>= 1;
    seg[x] = min(seg[x<<1],seg[x<<1|1]) + t[x];
  }
}
void ins(ll l,ll r,ll v){
  l += ct, r += ct;
  ll l0 = l, r0 = r;
  for (;l<r;l>>=1,r>>=1) {
    if (l&1) app(l++,v);
    if (r&1) app(--r,v);
  }
  pull(l0), pull(r0-1);
}
ll qr(ll l,ll r){
  ll ret = INF;
  l += ct, r += ct;
  push(l), push(r-1);
  for (;l<r;l>>=1,r>>=1) {
    if (l&1) ret = min(ret,seg[l++]);
    if (r&1) ret = min(ret,seg[--r]);
  }
  return ret;
}
void gogo(ll x,ll p,ll v){
  if (x != 0) {
    debug(x,p,v);
    ins(0,ct,v);
    ins(lr[x].X,lr[x].Y+1,-2*v);
    debug(lr[x]);
    debug("INS_OK");
  }
  REP (i,SZ(Q[x])) {
    qry cur = Q[x][i];
    debug(cur.l,cur.r);
    ll l = lf2[cur.l], r = lf1[cur.r];
    debug(l,r);
    ans[cur.id] = qr(l,r+1);
  }
  for (auto i:e[x]) {
    if (i.X == p) continue;
    gogo(i.X,x,i.Y);
  }
  if (x != 0) {
    ins(0,ct,-v);
    ins(lr[x].X,lr[x].Y+1,2*v);
    debug("INS_OK");
  }
}
int main(){
  IOS();
  ll n,q;
  cin >> n >> q;
  RST(lf,-1);
  REP1 (i,n-1) {
    ll p,v;
    cin >> p >> v;
    p--;
    e[i].eb(p,v);
    e[p].eb(i,v);
  }
  REP (i,n) {
    sort(ALL(e[i]));
    debug(e[i]);
  }
  REP (i,q) {
    ll v,l,r;
    cin >> v >> l >> r;
    l--,r--;
    v--;
    Q[v].pb((qry){l,r,i});
  }
  dfs(0,0,0);
  pary(lf,lf+n);
  pary(dep,dep+n);
  debug(ct);
  ll tmp = 0;
  REP (i,n) {
    lf1[i] = lf[i];
    if (lf[i] == -1) lf1[i] = tmp;
    else tmp = lf1[i];
  }
  for (ll i=n-1;i>=0;i--) {
    lf2[i] = lf[i];
    if (lf[i] == -1) lf2[i] = tmp;
    else tmp = lf2[i];
  }
  pary(lf1,lf1+n);
  pary(lf2,lf2+n);

  build();
  debug(qr(2,4));
  gogo(0,0,0);
  REP (i,q) cout << ans[i] << endl;
}
