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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=(ll)1e18;

struct S{
  ll l,r;
  ll mx,tmp;
} seg[MAXn*4];
ll d[MAXn];
void build(ll x,ll y,ll id){
  seg[id].l=x,seg[id].r=y;
  seg[id].mx=seg[id].tmp=0;
  if(x==y-1) seg[id].mx=d[x];
  else{
    ll mid=(x+y)/2;
    build(x,mid,id*2+1);
    build(mid,y,id*2+2);
    seg[id].mx=max(seg[id*2+1].mx,seg[id*2+2].mx);
  }
}
void ins(ll x,ll y,ll v,ll id){
  //debug(x,y,id,seg[id].l,seg[id].r);
  if(seg[id].l==x && seg[id].r==y){
    seg[id].tmp+=v;
    //debug("ok");
  }
  else{
    ll mid=(seg[id].l+seg[id].r)/2;
    if(y<=mid) ins(x,y,v,id*2+1);
    else if(x>=mid) ins(x,y,v,id*2+2);
    else{
      ins(x,mid,v,id*2+1);
      ins(mid,y,v,id*2+2);
    }
    seg[id].mx=max(seg[id*2+1].mx+seg[id*2+1].tmp,seg[id*2+2].mx+seg[id*2+2].tmp);
  }
}
ll qr(ll x,ll y,ll id){
  //debug("hi",x,y,id);
  if(seg[id].l==x && seg[id].r==y) return seg[id].mx+seg[id].tmp;
  else{
    ll mid=(seg[id].l+seg[id].r)/2;
    if(y<=mid) return seg[id].tmp+qr(x,y,id*2+1);
    else if(x>=mid) return seg[id].tmp+qr(x,y,id*2+2);
    else return seg[id].tmp+max(qr(x,mid,id*2+1),qr(mid,y,id*2+2));
  }
}
int main(){
  IOS();
  ll n,q;
  cin>>n>>q;
  REP(i,n) cin>>d[i];
  build(0,n,0);
  //REP(i,4*n) debug(seg[i].mx,seg[i].l,seg[i].r);
  while(q--){
    ll u,l,r;
    cin>>u>>l>>r;
    l--;
    if(u==1){
      ll x;
      cin>>x;
      ins(l,r,x,0);
      //REP(i,4*n) debug(seg[i].mx,seg[i].l,seg[i].r);
    }
    else cout<<qr(l,r,0)<<endl;
  }
}
