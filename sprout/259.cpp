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

const ll MAXn=2e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=(ll)1e18;

ll l[MAXn*4],r[MAXn*4],mx[MAXn*4],mn[MAXn*4];
ll ans[MAXn];
ll n,m;
void build(ll x,ll y,ll id){
  l[id]=x,r[id]=y;
  mx[id]=INF,mn[id]=0;
  if(x==y-1) return;
  ll mid=(x+y)/2;
  build(x,mid,id*2+1);
  build(mid,y,id*2+2);
}
void high(ll x,ll y,ll id,ll v);
void low(ll x,ll y,ll id,ll v);
void pushdown(ll id){
  if(mx[id]==INF && mn[id]==0) return;
  if(mx[id]==-1){
    mx[id*2+1]=mx[id*2+2]=-1;
    mn[id*2+1]=mn[id*2+2]=mn[id];
    mn[id]=0;
    mx[id]=INF;
    return;
  }
  ll mid = (l[id] + r[id]) / 2;
  if(mx[id]!=INF){
    low(l[id],mid,id*2+1,mx[id]);
    low(mid,r[id],id*2+2,mx[id]);
  }
  if(mn[id]!=0){
    high(l[id],mid,id*2+1,mn[id]);
    high(mid,r[id],id*2+2,mn[id]);
  }
  mn[id]=0;
  mx[id]=INF;
}
void sol(ll x,ll y,ll id){
  if(x==y-1){
    ans[x] = mn[id];
    debug(ans[x],x,id,mn[id]);
    return;
  }
  pushdown(id);
  ll mid = (l[id] + r[id]) / 2;
  sol(l[id],mid,id*2+1);
  sol(mid,r[id],id*2+2);
}
int main(){
  IOS();
  cin>>n>>m;
  build(0,n,0);
  while(m--){
    ll cmd,x,y,h;
    cin>>cmd>>x>>y>>h;
    y++;
    if(cmd==1) high(x,y,0,h);
    else low(x,y,0,h);
  }
  REP(i,4*n) debug(l[i],r[i],mn[i],mx[i],i);
  sol(0,n,0);
  REP(i,n) cout<<ans[i]<<endl;
}

void high(ll x,ll y,ll id,ll v){   //不足的補上去
  if(l[id]==x && r[id]==y){
    if(mx[id]==-1) chkmax(mn[id],v);
    else if(mx[id]<=v){
      mn[id]=v;
      mx[id]=-1;
    }
    else if(mn[id]<=v) mn[id]=v;
    return;
  }
  pushdown(id);
  ll mid = (l[id] + r[id]) / 2;
  if(y<=mid) high(x,y,id*2+1,v);
  else if(x>=mid) high(x,y,id*2+2,v);
  else{
    high(x,mid,id*2+1,v);
    high(mid,y,id*2+2,v);
  }
  //REP(i,4*n) debug(l[i],r[i],mx[i],mn[i]);
}
void low(ll x,ll y,ll id,ll v){    //超過的往下扣
  if(l[id]==x && r[id]==y){
    if(mx[id]==-1) chkmin(mn[id],v);
    else if(mn[id]>=v){
      mn[id]=v;
      mx[id]=-1;
    }
    else if(mx[id]>=v) mx[id]=v;
    return;
  }
  pushdown(id);
  ll mid = (l[id] + r[id]) / 2;
  if(y<=mid) low(x,y,id*2+1,v);
  else if(x>=mid) low(x,y,id*2+2,v);
  else{
    low(x,mid,id*2+1,v);
    low(mid,y,id*2+2,v);
  }
  //REP(i,4*n) debug(l[i],r[i],mx[i],mn[i]);
}
