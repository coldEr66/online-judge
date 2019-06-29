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

const ll MAXn=5e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

struct lines{
  ll a,b,pos;
  lines(){}
  lines(ll _a,ll _b,ll _pos):a(_a),b(_b),pos(_pos){}
};
ll n,k;
ll dp[MAXn];
ll sum[MAXn];
ll dq[MAXn];
lines dpp[MAXn];
bool chk(ll x,ll y,ll pos){
  return dpp[x].a * pos + dpp[x].b <= dpp[y].a * pos + dpp[y].b;
}
bool ok(ll x,ll y,ll z){
  return min(dpp[x].pos + k,(dpp[y].b-dpp[x].b) / (dpp[x].a-dpp[y].a)) >= (dpp[z].b-dpp[y].b) / (dpp[y].a-dpp[z].a);
}
int main(){
  IOS();
  cin >> n >> k;
  for (ll i=n;i>0;i--) cin >> sum[i];
  REP1 (i,n) sum[i] += sum[i-1];

  dpp[0] = lines(0LL,0LL,0LL);
  ll l=0,r=0;
  REP1 (i,n) {
    while (i - dq[l] > k) l++;
    while (r - l > 0 && chk(dq[l],dq[l+1],i)) l++;
    dp[i] = -i*i + dpp[dq[l]].a * i + dpp[dq[l]].b;

    dpp[i] = lines(2*i,dp[i]+sum[i]-i*i,i);
    while (r - l > 0 && ok(dq[r-1],dq[r],i)) r--;
    dq[++r] = i;
  }
  cout << dp[n] << endl;
}
