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
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
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

const ll MAXn=1e4+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll d[105];
ll dp[MAXn],s[MAXn];
ll b[200];
int main(){
  IOS();
  ll n,m;
  cin>>n;
  REP(i,n) cin>>d[i];
  cin>>m;
  s[0]=1;
  REP(i,n)for(ll j=m;j-d[i]>=0;j--){
    if( s[j-d[i]] && dp[j]<dp[j-d[i]]+1 ){
      dp[j] = dp[j-d[i]]+1;
      s[j] = s[j-d[i]];
    }
    else if( s[j-d[i]] && dp[j]==dp[j-d[i]]+1 ) s[j]+=s[j-d[i]];
  }
  debug(dp[m]);
  if( dp[m]==0 ) cout<<0<<' '<<0<<endl;
  else{
    cout<<dp[m]<<' ';
    b[0]=1;
    // assert(dp[m]>=0);
    REP1(i,dp[m]){
      REP(j,180) b[j]*=i;
      REP(j,180)if( b[j]>=10 ) b[j+1]+=b[j]/10,b[j]%=10;
    }
    REP(i,180) b[i]*=s[m];
    REP(i,180)if( b[i]>=10 ) b[i+1]+=b[i]/10,b[i]%=10;
    // assert(s[m]!=0);
    int x;
    for(x=180;b[x]==0;x--);
    for(;x>=0;x--) cout<<b[x];
    cout<<endl;
  }
}
