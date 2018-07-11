#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,j,n,m) for(int i=j;i<n;i+=m)
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define X first
#define Y second
#define mkp make_pair
#define pb push_back
#define pob pop_back
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.F<<","<<_p.S<<")";}
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

const ll MAXn=24,MAXlg=__lg(MAXn)+2;
const ll MOD=1e9+7;
const ll INF=(ll)1e18;

ll n;
ll x[MAXn],y[MAXn];
ll lines[MAXn][MAXn];
ll dp[(1<<MAXn)];
ll fpow(ll a,ll b){
  ll ret = 1,t = a;
  while(b){
    if(b&1) ret = (ret*t)%MOD;
    t = (t*t)%MOD;
    b>>=1;
  }
  return ret;
}
ll inv(ll a){
  return fpow(a,MOD-2);
}
bool chk(ll x1,ll y1,ll x2,ll y2){
  if(x1==0) return true;
  if(x1==x2) return true;
  if(y1*x2>x1*y2) return false;
  else return true;
}
void cal(ll mask){
  debug("hi");
  if(dp[mask]!=INF) return;
  REP(i,n){
    if((1<<i)&mask) continue;
    for(int j=i+1;j<n;j++){
      if((1<<j)&mask) continue;
      if(lines[i][j]==0) continue;
      ll nxt = mask|lines[i][j];
      cal(nxt);
      chkmin(dp[mask],dp[nxt]+1);
    }
    cal(mask|(1<<i));
    chkmin(dp[mask],dp[mask|(1<<i)]+1);
    break;
  }
}
int main(){
  IOS();
  ll t;
  cin>>t;
  while(t--){
    cin>>n;
    REP(i,(1<<MAXn)) dp[i] = INF;
    REP(i,n){
      cin>>x[i]>>y[i];
      x[i]%=MOD;
      y[i]%=MOD;
    }
    dp[(1<<n)-1] = 0;
    RST(lines,0);
    REP(i,n){
      for(int j=i+1;j<n;j++){
        ll xf,yf,xs,ys;
        if(x[i]>x[j]){
          xf = x[j] , xs = x[i];
          yf = y[j] , ys = y[i];
        }
        else{
          xf = x[i] , xs = x[j];
          yf = y[i] , ys = y[j];
        }
        if(chk(xf,yf,xs,ys)) continue;
        ll ta = (((yf*inv(xf))%MOD-(ys*inv(xs))%MOD)*inv(xf-xs))%MOD;
        ll tb = ((yf*inv(xf))%MOD-(ta*xf)%MOD)%MOD;
        while(ta<0) ta+=MOD;
        while(tb<0) tb+=MOD;
        ll tmp = (1<<i)|(1<<j);
        for(int k=0;k<n;k++)if(k!=i && k!=j && (((x[k]*x[k])%MOD*ta)%MOD+(x[k]*tb)%MOD)%MOD==y[k]%MOD) tmp|=(1<<k);
        lines[i][j] = lines[j][i] = tmp;
        debug(tmp);
      }
    }
    cal(0);
    cout<<dp[0]<<endl;
  }
}
