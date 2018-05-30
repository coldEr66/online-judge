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

const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=(ll)1e18;

struct S{
  ll l,r;
  ll mn;
} seg[MAXn*4];
ll d[MAXn];
ll qr(ll x,ll y,ll id){
  if(seg[id].l==x && seg[id].r==y) return seg[id].mn;
  ll mid=(seg[id].l+seg[id].r)/2;
  if(y<=mid) return qr(x,y,id*2+1);
  else if(x>=mid) return qr(x,y,id*2+2);
  else return min(qr(x,mid,id*2+1),qr(mid,y,id*2+2));
}
void ins(ll x,ll y,ll id){
  if(seg[id].l==seg[id].r-1) seg[id].mn=y;
  else{
    ll mid=(seg[id].l+seg[id].r)/2;
    if(x<mid) ins(x,y,id*2+1);
    else ins(x,y,id*2+2);
    seg[id].mn=min(seg[id*2+1].mn,seg[id*2+2].mn);
  }
}
void build(ll x,ll l,ll r){
  seg[x].l=l,seg[x].r=r;
  if(l==r-1){
    seg[x].mn=d[l];
    return;
  }
  ll mid=(l+r)/2;
  build(2*x+1,l,mid);
  build(2*x+2,mid,r);
  seg[x].mn=min(seg[2*x+1].mn,seg[2*x+2].mn);
}
int main(){
  IOS();
  ll t,n;
  cin>>t>>n;
  REP(i,n) cin>>d[i];
  REP(i,4*MAXn) seg[i].mn=INF;
  build(0,0,n);
  while(t--){
    //REP(i,4*n) debug(seg[i].l,seg[i].r,seg[i].mn);
    ll u,x,y;
    cin>>u>>x>>y;
    if(u==1){
      ll ans=qr(x,y+1,0);
      cout<<ans<<endl;
    }
    else{
      d[x]=y;
      ins(x,y,0);
    }
  }
}
