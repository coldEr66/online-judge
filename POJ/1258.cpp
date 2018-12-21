#include <iostream>
#include <utility>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
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

const ll MAXn=1e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int fa[MAXn],sz[MAXn];
int fd(int x){return fa[x] = (fa[x]==x ?x:fd(fa[x]));}
void uni(int u,int v){
  if( sz[u]<sz[v] ) swap(u,v);
  u=fd(u),v=fd(v);
  fa[v]=u;
  sz[u]+=sz[v];
  sz[v]=0;
}
struct E{
  int l,r,w;
  bool operator < (const E &a) const{
    return (w<a.w);
  }
} e[MAXn*MAXn];
int main(){
  IOS();
  int n;
  while( cin>>n ){
    int cnt=0;
    REP(i,n) fa[i]=i,sz[i]=1;
    REP(i,n)REP(j,n){
      int x;
      cin>>x;
      if( i<j ) e[cnt++]=(E){i,j,x};
    }
    sort(e,e+cnt);
    ll ans=0;
    REP(i,cnt){
      int l=e[i].l,r=e[i].r,w=e[i].w;
      if( fd(l)==fd(r) ) continue;
      ans+=w;
      uni(l,r);
    }
    cout<<ans<<endl;
  }
}
