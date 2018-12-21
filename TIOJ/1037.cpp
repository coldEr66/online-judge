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

const ll MAXn=1e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int n,m;
int e1[MAXn][MAXn],e2[MAXn][MAXn];
bool chk1(){
  REP(i,n)REP(j,m)if( !e1[i][j] ) return false;
  return true;
}
bool chk2(){
  REP(i,n)REP(j,m)if( !e2[i][j] ) return false;
  return true;
}
int main(){
  IOS();
  cin>>n>>m;
  int x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
  e1[x1][y1]=true;
  int k;
  cin>>k;
  REP(u,k){
    int x;
    cin>>x;
    if( u&1 ){
      RST(e1,0);
      REP(i,n)REP(j,m)if( e2[i][j] ){
        int tmp=(i+x)%n;
        e1[tmp][j]=true;
        tmp=(i-x)%n;
        while( tmp<0 ) tmp+=n;
        e1[tmp][j]=true;
        tmp=(j+x)%m;
        e1[i][tmp]=true;
        tmp=(j-x)%m;
        while( tmp<0 ) tmp+=m;
        e1[i][tmp]=true;
      }
      if( chk1() ) return cout<<"YES"<<endl,0;
    }
    else{
      RST(e2,0);
      REP(i,n)REP(j,m)if( e1[i][j] ){
        int tmp=(i+x)%n;
        e2[tmp][j]=true;
        tmp=(i-x)%n;
        while( tmp<0 ) tmp+=n;
        e2[tmp][j]=true;
        tmp=(j+x)%m;
        e2[i][tmp]=true;
        tmp=(j-x)%m;
        while( tmp<0 ) tmp+=m;
        e2[i][tmp]=true;
      }
      if( chk2() ) return cout<<"YES"<<endl,0;
    }
  }
  if( k&1 ) cout<<(e2[x2][y2] ?"YES":"NO")<<endl;
  else cout<<(e1[x2][y2] ?"YES":"NO")<<endl;
}
