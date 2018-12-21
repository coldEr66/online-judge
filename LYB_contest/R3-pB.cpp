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

const ll MAXn=5e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

struct tour{
  int id,st,ed,len;
  bool operator < (const tour &a){
    if(ed!=a.ed) return ed<a.ed;
    else return id<a.id;
  }
}t[MAXn];
int tmp[MAXn];
int len[MAXn];
int an[MAXn];
int main(){
  IOS();
  int n;
  cin>>n;
  REP(i,n){
    int x,y;
    cin>>x>>y;
    t[i].st=x;
    t[i].ed=y;
    t[i].id=i;
  }
  sort(t,t+n);
  int ans=0;
  tmp[n-1]=1;
  for(int i=n-2;i>=0;i--){
    int l=t[i].st,r=t[i].ed;
    debug(l,r);
    int x = 1;
    for(int j=i+1;j<n;j++){
      if( t[j].st<=r ) continue;
      chkmax(x,tmp[j]+1);
    }
    tmp[i]=x;
    debug(i,x);
    chkmax(ans,x);
  }
  pary(tmp,tmp+n);
  cout<<ans<<endl;
  int cur=ans;
  vector<int> v;
  int x=-1;
  REP(i,n){
    if( cur==0 ) break;
    if( tmp[i]==cur && x==-1 ) v.pb(t[i].id),cur--,x=i;
    else if( tmp[i]==cur && x!=-1 && t[i].st>t[x].ed) v.pb(t[i].id),cur--,x=i;
  }
  REP(i,SZ(v)) cout<<v[i]+1<<(i==SZ(v)-1 ?'\n':' ');
}
