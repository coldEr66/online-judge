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
const ll INF=0x3f3f3f3f3f3f3f3f;

ll x[MAXn],y[MAXn],t[MAXn];
ll qx[MAXn],qy[MAXn];
ll qid[MAXn],nid[MAXn];
ll tx[MAXn],ty[MAXn];
ll qtx[MAXn],qty[MAXn];
vector<ll> xx,yy;
ll ans[MAXn][2];
bool cmp (const ll &a,const ll &b) {
  return x[a] < x[b];
}
bool qcmp (const ll &a,const ll &b) {
  return qx[a] < qx[b];
}
ll seg1[MAXn*2],seg2[MAXn*2];
void ins(ll *seg,ll p,ll val){
  for (chkmin(seg[p+=SZ(yy)],val);p>1;p>>=1) seg[p>>1] = min(seg[p],seg[p^1]);
}
ll qr(ll *seg,ll l,ll r){
  ll ret = INF;
  for (l+=SZ(yy),r+=SZ(yy);l<r;l>>=1,r>>=1) {
    if (l&1) chkmin(ret,seg[l++]);
    if (r&1) chkmin(ret,seg[--r]);
  }
  return ret;
}
int main(){
  IOS();
  freopen("slingshot.in","r",stdin);
  freopen("slingshot.out","w",stdout);
  ll n,m;
  cin >> n >> m;
  REP (i,n) {
    cin >> x[i] >> y[i] >> t[i];
    xx.eb(x[i]);
    yy.eb(y[i]);
    nid[i] = i;
  }
  sort(nid,nid+n,cmp);
  pary(nid,nid+n);
  REP (i,m) {
    cin >> qx[i] >> qy[i];
    xx.eb(qx[i]);
    yy.eb(qy[i]);
    qid[i] = i;
  }
  sort(qid,qid+m,qcmp);
  pary(qid,qid+m);
  sort(ALL(xx));
  sort(ALL(yy));
  xx.resize(unique(ALL(xx))-xx.begin());
  yy.resize(unique(ALL(yy))-yy.begin());
  debug(yy);
  REP (i,n) {
    tx[i] = ll(lower_bound(ALL(xx),x[i])-xx.begin());
    ty[i] = ll(lower_bound(ALL(yy),y[i])-yy.begin());
  }
  REP (i,m) {
    qtx[i] = ll(lower_bound(ALL(xx),qx[i])-xx.begin());
    qty[i] = ll(lower_bound(ALL(yy),qy[i])-yy.begin());
  }
  REP (i,2*MAXn) seg1[i] = seg2[i] = INF;
  ll idx = 0;
  REP (i,m) {
    ll it = qid[i];
    while (idx < n && x[nid[idx]] <= qx[it]) {
      ins(seg1,ty[nid[idx]],t[nid[idx]]-x[nid[idx]]-y[nid[idx]]);
      ins(seg2,ty[nid[idx]],t[nid[idx]]-x[nid[idx]]+y[nid[idx]]);
      idx++;
    }
    ll ta = qr(seg1,0,qty[it]+1);
    ll tb = qr(seg2,qty[it]+1,SZ(yy));
    ans[it][0] = min(qx[it]+qy[it]+ta,qx[it]-qy[it]+tb);
  }

  REP (i,2*MAXn) seg1[i] = seg2[i] = INF;
  idx = n-1;
  for (ll i=m-1;i>=0;i--) {
    ll it = qid[i];
    while (idx >= 0 && x[nid[idx]] >= qx[it]) {
      ins(seg1,ty[nid[idx]],t[nid[idx]]+x[nid[idx]]-y[nid[idx]]);
      ins(seg2,ty[nid[idx]],t[nid[idx]]+x[nid[idx]]+y[nid[idx]]);
      idx--;
    }
    ll ta = qr(seg1,0,qty[it]+1);
    ll tb = qr(seg2,qty[it]+1,SZ(yy));
    ans[it][1] = min(-qx[it]+qy[it]+ta,-qx[it]-qy[it]+tb);
  }

  REP (i,m) {
    cout << min({ans[i][0],ans[i][1],abs(qx[i]-qy[i])}) << endl;
  }
}
