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

const ll MAXn=2e4+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll n,k;
ll dp[MAXn][24];
ll d[MAXn];
ll segi[MAXn*2],sega[MAXn*2];
ll bit1[MAXn],bit2[MAXn];
void build() {
  for (int i=n-1;i>0;i--) {
    segi[i] = min(segi[i<<1],segi[i<<1|1]);
    sega[i] = max(sega[i<<1],sega[i<<1|1]);
  }
}
ll qrmax(ll l,ll r){
  ll ret = 0
  for (l+=n,r+=n;l<r;l>>=1,r>>=1) {
    if (l&1) ret = max(ret,sega[l++]);
    if (r&1) ret = max(ret,sega[--r]);
  }
  return ret;
}
ll qrmin(ll l,ll r){
  ll ret = INF;
  for (l+=n,r+=n;l<r;l>>=1,r>>=1) {
    if (l&1) ret = min(ret,segi[l++]);
    if (r&1) ret = min(ret,segi[--r]);
  }
  return ret;
}
ll qr(ll l,ll r){
  return qrmax(l,r)-qrmin(l,r);
}
ll dptree[MAXn*2],tmptree[MAXn*2];
void ins(ll x,ll val,ll *tree){
  for (tree[x+=n] = val;x>1;x>>=1) {
    tree[x>>1] = min(tree[x],tree[x^1]);
  }
}
ll dpqr(ll r,ll *tree){
  ll l = 0;
  ll ret = INF;
  for (l+=n,r+=n;l<r;l>>=1,r>>=1) {
    if (l&1) ret = min(ret,tree[l++]);
    if (r&1) ret = min(ret,tree[--r]);
  }
  return ret;
}
int main(){
  IOS();
  cin >> n >> k;
  REP (i,n) {
    cin >> d[i];
    segi[i+n] = d[i];
    sega[i+n] = d[i];
  }

  build();
  REP (i,n) {
    dp[i][1] = qr(0,i);
    ins(i,dp[i][1],tmptree);
  }
  swap(dptree,tmptree);
  for (int j=2;j<=k;j++) {
    REP (i,n) {
      ins(i,qr(),dptree)
    }
    REP (i,n) {
      if (!i) dp[i][j] = 0;
      else dp[i][j] = dpqr(i-1,dptree);
      ins(i,dp[i][j],tmptree);
    }
    swap(dptree,tmptree);
  }
}
