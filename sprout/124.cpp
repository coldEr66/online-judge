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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=(ll)1e18;

void Report(int x1,int y1,int x2,int y2,int x3,int y3);
void solve(int n,int x,int y,int dx=0,int dy=0){
  if(n==1) return;
  int tmp=n/2;
  if(x<=tmp && y<=tmp){
    Report(tmp+dx,tmp+1+dy,tmp+1+dx,tmp+1+dy,tmp+1+dx,tmp+dy);
    solve(tmp,x,y,dx,dy);
    solve(tmp,tmp,1,dx,dy+tmp);
    solve(tmp,1,1,dx+tmp,dy+tmp);
    solve(tmp,1,tmp,dx+tmp,dy);
  }
  else if(x<=tmp){
    Report(tmp+dx,tmp+dy,tmp+dx+1,tmp+dy,tmp+dx+1,tmp+dy+1);
    solve(tmp,x,y-tmp,dx,dy+tmp);
    solve(tmp,tmp,tmp,dx,dy);
    solve(tmp,1,tmp,dx+tmp,dy);
    solve(tmp,1,1,dx+tmp,dy+tmp);
  }
  else if(y<=tmp){
    Report(tmp+dx,tmp+dy,tmp+dx,tmp+dy+1,tmp+dx+1,tmp+dy+1);
    solve(tmp,x-tmp,y,dx+tmp,dy);
    solve(tmp,tmp,tmp,dx,dy);
    solve(tmp,tmp,1,dx,dy+tmp);
    solve(tmp,1,1,dx+tmp,dy+tmp);
  }
  else{
    Report(tmp+dx,tmp+dy+1,tmp+dx,tmp+dy,tmp+dx+1,tmp+dy);
    solve(tmp,x-tmp,y-tmp,dx+tmp,dy+tmp);
    solve(tmp,1,tmp,dx+tmp,dy);
    solve(tmp,tmp,1,dx,dy+tmp);
    solve(tmp,tmp,tmp,dx,dy);
  }
}
