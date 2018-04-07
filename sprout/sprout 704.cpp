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
#define F first
#define S second
#define pb push_back
#define pob pop_back
#define MP make_pair
#define VI vector<int>
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

const ll MAXn=2005;
const ll MOD=1000000007;
const ll INF=(ll)1e18;

ii d[MAXn][MAXn];
ii r[MAXn],c[MAXn];
ll bl,re,non;
ll n,m,k;

lf dis(ll a1,ll b1,ll a2,ll b2){
  lf rt=sqrt((a1-a2)*(a1-a2)+(b1-b2)*(b1-b2));
  return rt;
}

void chk(ll x){
  if(x==1) bl++;
  else re++;
}

void sol(ll i,ll j){
  ii a=r[i],b=c[j],cir=d[i][j];
  debug(a.F,a.S,b.F,b.S,cir.F,cir.S);
  if(a.S==0 && b.S==0 && cir.S==0) non++;
  else if(a.S>b.S && a.S>cir.S) chk(a.F);
  else if(b.S>a.S && b.S>cir.S) chk(b.F);
  else if(cir.S>a.S && cir.S>b.S) chk(cir.F);
  debug(bl,re,non,i,j);
}
int main(){
  IOS();
  cin>>n>>m>>k;
  ll t=1;
  while(k--){
    ll x;
    cin>>x;
    if(x==1){
      ll a,b;
      cin>>a>>b;
      b--;
      if(b>0) r[b-1]=MP(a,t);
      r[b]=MP(a,t);
      if(b+1<n) r[b+1]=MP(a,t);
    }
    else if(x==2){
      ll a,b;
      cin>>a>>b;
      b--;
      if(b>0) c[b-1]=MP(a,t);
      c[b]=MP(a,t);
      if(b+1<m) c[b+1]=MP(a,t);
    }
    else{
      ll a,x,y,r;
      cin>>a>>x>>y>>r;
      x--,y--;
      for(int i=x-r;i<=x+r;i++){
        for(int j=y-r;j<=y+r;j++){
          if(i<0 || j<0 || i>=n || j>=m) continue;
          if(dis(x,y,i,j)<=(lf)r) d[i][j]=MP(a,t);
        }
      }
    }
    t++;
  }
  REP(i,n)REP(j,m) sol(i,j);
  cout<<bl<<' '<<re<<' '<<non<<endl;
}

