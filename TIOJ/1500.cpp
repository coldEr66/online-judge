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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f;
typedef pair<lf,lf> pdd;

pdd d[MAXn],t[MAXn];
bool cmpx(const pdd &a,const pdd &b){return a.X<b.X;}
bool cmpy(const pdd &a,const pdd &b){return a.Y<b.Y;}
lf cal(const pdd &a,const pdd &b){return (lf)sqrt((a.X-b.X)*(a.X-b.X)+(a.Y-b.Y)*(a.Y-b.Y));}
lf sol(int l,int r){
  if( l>=r ) return INF;
  int mid = (l+r)/2;
  lf ret = min(sol(l,mid),sol(mid+1,r));
  if( ret==0 ) return ret;
  int it = 0;
  for(int i=mid;i>=l && d[mid].X-d[i].X<ret;i--) t[it++] = d[i];
  for(int i=mid+1;i<=r && d[i].X-d[mid].X<ret;i++) t[it++] = d[i];
  sort(t,t+it,cmpy);
  REP(i,it-1)for(int j=1;j<=3 && i+j<it;j++) chkmin(ret,cal(t[i],t[i+j]));
  return ret;
}
int main(){
  IOS();
  int n;
  cout<<fixed<<setprecision(6);
  while( cin>>n ){
    REP(i,n) cin>>d[i].X>>d[i].Y;
    sort(d,d+n,cmpx);
    lf ans = sol(0,n-1);
    assert(ans>=0.0);
    cout<<ans<<endl;
  }
}
