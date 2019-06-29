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

const ll MAXn=1100,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll mod;
ll C[MAXn][MAXn];
ll ct[257];
ll add(ll a,ll b){
  return (a+b)%mod;
}
ll mul(ll a,ll b){
  return (a*b)%mod;
}
void build(){
  REP (i,MAXn) {
    C[i][0] = 1;
    C[i][i] = 1;
  }
  REP1 (i,MAXn-1) {
    REP1 (j,i-1) {
      C[i][j] = add(C[i-1][j-1],C[i-1][j]);
    }
  }
  // pary(C[1],C[1]+300);
}
int main(){
  IOS();
  cin >> mod;
  string s;
  cin >> s;
  build();
  REP (i,SZ(s)) ct[ll(s[i])]++;

  // pary(ct,ct+256);
  ll ans = 0;
  REP (i,SZ(s)-1) {
    REP (j,s[i]) {
      if (!ct[j]) continue;
      ll tmp = 1;
      ll num = C[SZ(s)-i-tmp][ct[j]-1];
      debug(num);
      tmp += ct[j] - 1;
      REP (k,256) {
        if (k == j) continue;
        if (!ct[k]) continue;
        num = mul(num,C[SZ(s)-i-tmp][ct[k]]);
        tmp += ct[k];
      }
      debug(num,tmp);
      ans = add(ans,num);
    }
    ct[ll(s[i])]--;
  }
  cout << ans << endl;
}
