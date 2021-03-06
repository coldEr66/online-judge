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

MaxHeap<ll> pq;
ll sum,idx,ans;
vector<ii> d;
int main(){
  IOS();
  ll n,m,r;
  cin>>n>>m>>r;
  ll hp=m;
  REP(i,n){
    ll a,b;
    cin>>a>>b;
    if(a==100) pq.push(b);
    if(a==0) continue;
    d.pb({a,b});
    sum+=b;
  }
  n=SZ(d);
  debug(SZ(pq),sum);
  sort(ALL(d),greater<ii>());
  while(d[idx].F==100) idx++;
  if(!SZ(pq)) return cout<<-1<<endl,0;
  ll tmp=-r;
  while(m>0){
    debug(tmp);
    m-=tmp;
    if(m>hp) m=hp;
    if(m<=0) break;
    debug(m);
    debug(idx,tmp);
    if(idx==n && tmp==sum-r){
      if(tmp<=0) break;
      ll tp=m;
      lf x=ceil((lf)tp/(lf)tmp);
      debug(ans,x);
      m=0;
      ans+=x;
      break;
    }
    else ans++;
    debug(SZ(pq));
    if(!SZ(pq)){
      if(tmp<=0) break;
      ll tp=floor((lf)d[idx].F*(lf)hp/100.0);
      debug(tp);
      tp=m-tp;
      debug(tp,d[idx].F);
      ans+=ceil((lf)tp/(lf)tmp);
      m-=ceil((lf)tp/(lf)tmp)*tmp;
    }
    debug((lf)d[idx].F/100.0*(lf)hp,m);
    while((lf)d[idx].F*(lf)hp/100.0>=m && idx<n) pq.push(d[idx++].S);
    debug(m,SZ(pq));
    if(!SZ(pq)) break;
    ll cur=pq.top();
    pq.pop();
    tmp+=cur;
    debug(tmp);
  }
  if(m<=0) cout<<ans<<endl;
  else cout<<-1<<endl;
}
