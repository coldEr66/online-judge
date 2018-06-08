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

struct SX{
  ll l,r;
  ll cnt1,cnt2,t,rs;
} seg[MAXn*4];
void build(ll x,ll y,ll id){
  seg[id].l=x,seg[id].r=y;
  seg[id].t=seg[id].rs=seg[id].cnt2=0;
  if(x==y-1){
    seg[id].cnt1=1;
    return;
  }
  ll mid=(x+y)/2;
  build(x,mid,id*2+1);
  build(mid,y,id*2+2);
  seg[id].cnt1=seg[id*2+1].cnt1+seg[id*2+2].cnt1;
}
void tt(ll id){
  ll tmp=seg[id].cnt1;
  seg[id].cnt1=seg[id].r-seg[id].l-seg[id].cnt1-seg[id].cnt2;
  seg[id].cnt2=tmp;
}
void pushdown(ll id){
  if(seg[id].t==0 && seg[id].rs==0) return;
  if(seg[id].rs){
    seg[id*2+1].t=seg[id*2+2].t=0;
    seg[id*2+1].rs=seg[id*2+2].rs=seg[id].rs;
    seg[id].cnt1=seg[id].r-seg[id].l;
    seg[id].cnt2=0;
    seg[id].rs=0;
  }
  if(seg[id].t){
    seg[id*2+1].t+=seg[id].t;
    if(seg[id*2+1].t>=3) seg[id*2+1].t-=3;
    seg[id*2+2].t+=seg[id].t;
    if(seg[id*2+2].t>=3) seg[id*2+2].t-=3;
    ll g=seg[id].t;
    while(g--) tt(id);
    seg[id].t=0;
  }
}
ii cal(ll id){
  if(seg[id].t==0 && seg[id].rs==0) return {seg[id].cnt1,seg[id].cnt2};
  ii ret;
  pushdown(id);
  /*
  if(seg[id].r) seg[id].cnt1=seg[id].r-seg[id].l,seg[id].cnt2=0,seg[id].rs=0;
  if(seg[id].t){
    ll g=seg[id].t;
    while(g--) tt(id);
    seg[id].t=0;
  }
  */
  ret.F=seg[id].cnt1;
  ret.S=seg[id].cnt2;
  debug(ret,id);
  return ret;
}
void turn(ll x,ll y,ll id){
  pushdown(id);
  if(seg[id].l==x && seg[id].r==y){
    seg[id].t++;
    if(seg[id].t>=3) seg[id].t-=3;
    //seg[id].t%=3;
    return;
  }
  ll mid=(seg[id].l+seg[id].r)/2;
  if(y<=mid) turn(x,y,id*2+1);
  else if(x>=mid) turn(x,y,id*2+2);
  else{
    turn(x,mid,id*2+1);
    turn(mid,y,id*2+2);
  }
  ii p1=cal(id*2+1),p2=cal(id*2+2);
  debug(p1,p2);
  seg[id].cnt1=p1.F+p2.F;
  seg[id].cnt2=p1.S+p2.S;
  debug(seg[id].cnt1,seg[id].cnt2,id);
}
void res(ll x,ll y,ll id){
  if(seg[id].l==x && seg[id].r==y){
    seg[id].rs=1;
    seg[id].t=0;
    return;
  }
  pushdown(id);
  ll mid=(seg[id].l+seg[id].r)/2;
  if(y<=mid) res(x,y,id*2+1);
  else if(x>=mid) res(x,y,id*2+2);
  else{
    res(x,mid,id*2+1);
    res(mid,y,id*2+2);
  }
  ii p1=cal(id*2+1),p2=cal(id*2+2);
  seg[id].cnt1=p1.F+p2.F;
  seg[id].cnt2=p1.S+p2.S;
  debug(seg[id].cnt1,seg[id].cnt2,id);
}
ll qr(ll x,ll y,ll id){
  pushdown(id);
  if(seg[id].l==x && seg[id].r==y && seg[id].l==seg[id].r-1){
    ii o=cal(id);
    seg[id].cnt2=o.S;
    return seg[id].cnt1=o.F;
  }
  if(seg[id].l==x && seg[id].r==y){
    ii p1=cal(id*2+1),p2=cal(id*2+2);
    seg[id].cnt2=p1.S+p2.S;
    debug(p1,p2,id,seg[id].l,seg[id].r,seg[id].cnt1,seg[id].cnt2);
    return seg[id].cnt1=p1.F+p2.F;
  }
  ll mid=(seg[id].l+seg[id].r)/2;
  if(y<=mid) return qr(x,y,id*2+1);
  else if(x>=mid) return qr(x,y,id*2+2);
  else return qr(x,mid,id*2+1)+qr(mid,y,id*2+2);
}
int main(){
  IOS();
  ll n,q;
  cin>>n>>q;
  build(0,n,0);
  //REP(i,4*n) debug(seg[i].l,seg[i].r,seg[i].cnt1,seg[i].cnt2);
  while(q--){
    string u;
    ll l,r;
    cin>>u>>l>>r;
    l--;
    if(u[0]=='T') turn(l,r,0);
    else if(u[0]=='R') res(l,r,0);
    else cout<<qr(l,r,0)<<endl;
  }
}
