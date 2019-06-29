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

ll n,k;
ll seg[MAXn<<1][40];
void build(ll mask){
  for (ll i=n-1;i>0;i--) seg[i][mask] = min(seg[i<<1][mask],seg[i<<1|1][mask]);
}
void pull(ll pos){
  REP (mask,(1<<k)) {
    for (ll i=pos+n;i>1;i>>=1) seg[i>>1][mask] = min(seg[i][mask],seg[i^1][mask]);
  }
}
void ins(ll pos,ll i,ll val){
  REP (mask,(1<<k)) {
    if ((1<<i)&mask) seg[pos+n][mask] += val;
    else seg[pos+n][mask] -= val;
  }
}
ll qr(ll l,ll r,ll mask){
  ll ret = INF;
  for (l+=n,r+=n;l<r;l>>=1,r>>=1) {
    if (l&1) ret = min(ret,seg[l++][mask]);
    if (r&1) ret = min(ret,seg[--r][mask]);
  }
  debug(ret);
  return ret;
}
int main(){
  IOS();
  cin >> n >> k;
  REP (i,n) {
    REP (j,k) {
      ll x;
      cin >> x;
      REP (mask,(1<<k)) {
        if ((1<<j)&mask) seg[i+n][mask] += x;
        else seg[i+n][mask] -= x;
      }
    }
  }

  REP (mask,(1<<k)) build(mask);
  ll q;
  cin >> q;
  while (q--) {
    ll cmd;
    cin >> cmd;
    if (cmd == 1) {
      ll pos;
      cin >> pos;
      pos--;
      REP (mask,(1<<k)) seg[pos+n][mask] = 0;
      REP (i,k) {
        ll v;
        cin >> v;
        ins(pos,i,v);
      }
      pull(pos);
    }
    else {
      ll l,r;
      cin >> l >> r;
      l--;
      ll ans = 0;
      REP (mask,(1<<(k-1))) {
        ll a = qr(l,r,mask);
        ll b = qr(l,r,((1<<k)-1)^mask);
        ans = max(ans,abs(a+b));
      }
      cout << ans << endl;
    }
  }
}
