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

const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=10000019;
const ll INF=(ll)1e18;

ll d[MAXn];

void mrg(ll l,ll r){
  ll tmp[MAXn];
  ll i=l,j=(l+r)/2,idx=l;
  ll mid=j;
  for(ll k=l;k<r;k++) tmp[k]=d[k];
  while(i<mid){
    while(j<r && tmp[j]<tmp[i]) d[idx++]=tmp[j++];
    d[idx++]=tmp[i++];
  }
}

ll sol(ll l,ll r){
  debug(l,r);
  if(l==r-1) return 0;
  ll i=l,j=(l+r)/2,mid=(l+r)/2;
  //debug(i,j);
  //debug("hi");
  ll rt=(sol(l,j)+sol(j,r))%MOD;
  debug(rt,l,r);
  //debug("OK");
  ll tmp=0;
  debug(mid,i,j);
  while(i<mid){
    debug(d[i],d[j]);
    while(j<r && d[i]>d[j]) tmp+=d[j++],tmp%=MOD;
    debug(rt,tmp,i,j);
    rt=(rt+(j-mid)*d[i]+tmp)%MOD;
    i++;
  }
  mrg(l,r);
  debug(l,r,rt);
  return rt;
}

int main(){
  IOS();
  ll n;
  cin>>n;
  REP(i,n) cin>>d[i];
  //debug("sol");
  pary(d,d+n);
  cout<<sol(0,n)<<endl;
}
