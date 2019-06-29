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

const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;
typedef pair<ii,ll> iii;

vector<ll> rk;
vector<iii> v;
ll sum[MAXn];
ll suf[MAXn];
int main(){
  IOS();
  ll n;
  cin >> n;
  ll W = 0;
  REP (i,n) {
    ll l,r,w;
    cin >> l >> r >> w;
    W += w;
    v.eb(ii(l,r),w);
    rk.eb(l);
    rk.eb(l+1);
    rk.eb(r);
    rk.eb(r+1);
  }
  sort(ALL(rk));
  rk.resize(unique(ALL(rk))-rk.begin());

  REP (i,n) {
    v[i].X.X = lower_bound(ALL(rk),v[i].X.X) - rk.begin() + 1;
    v[i].X.Y = lower_bound(ALL(rk),v[i].X.Y) - rk.begin() + 1;
  }
  sort(ALL(v),[&](const iii a,const iii b){
    return a.X.X > b.X.X;
  });
  debug(v);
  // REP (i,n) {
  //   ll now = v[i].X.X-1;
  //   while (lst >= now) suf[lst] = min(suf[lst],suf[lst+1]),lst--;
  //   cur += v[i].Y;
  //   suf[now] = min(suf[now],cur);
  // }
  ll idx = 0, cur = 0;
  for (ll i=MAXn-1;i>=0;i--) {
    suf[i] = min(suf[i],suf[i+1]);
    if (i == v[idx].X.X-1) {
      while (idx < n && i == v[idx].X.X-1) cur += v[idx].Y,idx++;
      suf[i] = min(suf[i],cur);
    }
  }
  // REP1 (i,100) debug(suf[i]);
  sort(ALL(v),[&](const iii a,const iii b){
    return a.X.Y < b.X.Y;
  });
  debug(v);
  cur = 0;
  idx = 0;
  ll ans = 0;
  REP1 (i,MAXn-1) {
    // debug(cur,suf[i]);
    if (i) ans = max(ans,W - cur - suf[i]);
    while (idx < n && i == v[idx].X.Y) cur += v[idx].Y,idx++;
  }
  cout << ans << endl;
}
