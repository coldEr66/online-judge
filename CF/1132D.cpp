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

typedef pair<ii,ll> iii;
ll n,k;
ll a[MAXn],b[MAXn],cur[MAXn];
vector<ll> times[MAXn];
bool chk(ll x){
  REP (i,k) {
    times[i].clear();
    times[i].shrink_to_fit();
  }
  REP (i,n) {
    ll t = a[i]/b[i] + 1;
    cur[i] = a[i]%b[i];
    if (t < k) times[t].eb(i);
  }

  ll lst = 0;
  REP (t,k) {
    while (lst < k && !SZ(times[lst])) lst++;
    if (lst <= t) return false;
    if (lst == k) return true;
    ll tmp = times[lst].back();
    if (cur[tmp] + x < b[tmp]) {
      cur[tmp] += x;
      continue;
    }
    times[lst].pob();
    ll nxt = (cur[tmp]+x) / b[tmp];
    cur[tmp] = (cur[tmp]+x) % b[tmp];
    if (lst + nxt < k) times[lst+nxt].eb(tmp);
  }
  return true;
}
int main(){
  IOS();
  cin >> n >> k;
  REP (i,n) cin >> a[i];
  REP (i,n) cin >> b[i];
  ll MAX = 3e12;
  ll l = 0, r = MAX;
  while (l != r) {
    ll mid = (l+r)>>1;
    if (chk(mid)) r = mid;
    else l = mid+1;
  }
  if (l == MAX) cout << -1 << endl;
  else cout << l << endl;
}
