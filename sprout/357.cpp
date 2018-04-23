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

ii d[MAXn];
MaxHeap<ll> pq;
ll ans,cnt,ok;
int main(){
  IOS();
  ll n,m,r,k=0;
  cin>>n>>m>>r;
  ll hp=m;
  REP(i,n){
    cin>>d[i].F>>d[i].S;
    if(d[i].F==100) pq.push(d[i].S);
    k+=d[i].S;
  }
  sort(d,d+n,greater<ii>());
  ll tmp=-r,idx=0;
  while(d[idx].F==100) idx++;
  if(!SZ(pq)) return cout<<-1<<endl,0;
  debug(idx,k);
  while(SZ(pq) && m>0){
    ll cur=pq.top();
    debug(tmp,cur);
    pq.pop();
    if(cur+tmp<0){
      ok=1;
      break;
    }
    else{
      tmp+=cur;
      m-=tmp;
      if(m<=0) break;
      ans++;
    }
    if(idx==n && tmp==k-r){
      ll tp=m;
      debug(tp);
      if(tmp!=0)ans+=ceil((lf)tp/tmp);
      debug(ans,tmp);
      m-=ceil((lf)tp/tmp)*tmp;
      break;
    }
    //debug("ok");
    if(!SZ(pq)){
      ll tp=m-d[idx].F;
      if(tmp!=0){
        m-=ceil((lf)tp/tmp)*tmp;
        ans+=ceil((lf)tp/tmp);
      }
      debug(ans,m,tp);
      debug(d[idx].F,floor((lf)d[idx].F/100)*(lf)hp,hp);
      while(floor((lf)d[idx].F/100)*(lf)hp<=m && idx<n) pq.push(d[idx++].S);
      //debug(SZ(pq));
    }
    //debug("hi");
  }
  if(ok || m>0) cout<<-1<<endl;
  else cout<<ans<<endl;
}

// 2 100 10
// 100 11
// 90 9

// 5 100 10
// 100 10
// 100 7
// 100 6
// 100 5
// 100 1

// 5 10 10
// 100 9
// 100 10
// 100 11
// 90 1
// 100 1

// 1 10
// 9
// 100 19
