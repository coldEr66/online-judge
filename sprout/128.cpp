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

const ll MAXn=1030,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=(ll)1e18;

int d[MAXn][MAXn];
void fil(int x,int y,int val){
  d[x][y]=val;
}
void solve(int n,int x=0,int y=0,int l=1,int r=-1,int ok=1,int tp=0){
  if(ok) r=2*n-1;
  debug(r);
  if(n==2){
    fil(x,y,l);
    fil(x+1,y+1,l);
    fil(x,y+1,r);
    if(r-l==2) fil(x+1,y,l+1);
    else fil(x+1,y,r);
    if(ok){
      REP(i,n)REP(j,n) Report(d[i][j]);
    }
    return;
  }
  int tmp=n/2;
  if(!tp){
    solve(tmp,x,y,l,r/2,0,0);
    solve(tmp,x,y+tmp,r/2+1,3*r/4,0,1);
    solve(tmp,x+tmp,y,3*r/4+1,r,0,1);
    solve(tmp,x+tmp,y+tmp,l,r/2,0,0);
  }
  else{
    solve(tmp,x,y,l,(l+r)/2,0,1);
    solve(tmp,x,y+tmp,(l+r)/2+1,r,0,1);
    solve(tmp,x+tmp,y,(l+r)/2+1,r,0,1);
    solve(tmp,x+tmp,y+tmp,l,(l+r)/2,0,1);
  }
  if(ok){
    REP(i,n)REP(j,n) Report(d[i][j]);
  }
}
