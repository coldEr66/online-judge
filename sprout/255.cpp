#include <bits/stdc++.h>
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
#define F first
#define S second
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
const ll MOD=1000000007;
const ll INF=(ll)1e18;

pair<lf,lf> x[MAXn];
ll l[MAXn][MAXn];
ll dp[(1<<MAXn)];
ll n;
bool chk(lf a,lf b){
  if(abs(a-b)<1e-6) return true;
  else return false;
}
/*
void cal(ll tmp){
  //debug("hi");
  //debug(tmp);
  if(dp[tmp]!=INF) return;
  debug(dp[tmp],tmp);
  REP(i,n){
    //debug("for");
    if((1<<i)&tmp) continue;
    for(int j=i+1;j<n;j++){
      if((1<<j)&tmp) continue;
      if(l[i][j]==0) continue;
      ll nxt=tmp|l[i][j];
      cal(nxt);
      chkmin(dp[tmp],dp[nxt]+1);
    }
    debug("tmp",i);
    cal(tmp|(1<<i));
    chkmin(dp[tmp],dp[tmp|(1<<i)]+1);
    break;
  }
}
*/
int main(){
  IOS();
  ll t;
  cin>>t;
  while(t--){
    cin>>n;
    RST(dp,0);
    REP(i,(1<<n)) dp[i]=INF;
    RST(l,0);
    REP(i,n) cin>>x[i].F>>x[i].S;
    //sort(x,x+n);
    dp[0]=0;
    //debug((1<<n)-1);
    REP(i,n){
      for(int j=i+1;j<n;j++){
        if(chk(x[i].F,x[j].F)) continue;
        lf ta=(x[i].S/x[i].F-x[j].S/x[j].F)/(x[i].F-x[j].F);
        lf tb=x[i].S/x[i].F-ta*x[i].F;
        if(ta>=0) continue;
        ll tmp = (1<<i)|(1<<j);
        for(int k=0;k<n;k++)if(k!=i && k!=j && chk(x[k].F*x[k].F*ta+tb*x[k].F,x[k].S)) tmp|=(1<<k);
        //debug(tmp,i,j);
        l[i][j]=tmp;
      }
    }
    REP(i,n) pary(l[i],l[i]+n);
    //cal(0);
    //pary(x,x+n);
    REP(i,(1<<n)){
      if(dp[i]==INF) continue;
      REP(j,n){
        if((1<<j)&i) continue;
        for(int k=j+1;k<n;k++){
          if(((1<<k)&i)==0 && l[j][k]) chkmin(dp[i|l[j][k]],dp[i]+1);
          // if((1<<k)&i && l[j][k]){
          //   ll len = i^(i&l[j][k]);
          //   chkmin(dp[i|(1<<j)],dp[len]+1);
          // }
        }
        chkmin(dp[i|(1<<j)],dp[i]+1);
        break;
      }
    }
    cout<<dp[(1<<n)-1]<<endl;
  }
}
