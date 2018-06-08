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
  ll sum,sl,sr,mx;
} seg[MAXn*4];
ll d[MAXn];
void build(ll x,ll y,ll id){
  seg[id].l=x,seg[id].r=y;
  seg[id].sum=seg[id].sl=seg[id].sr=seg[id].mx=0;
  if(x==y-1) seg[id].sum=seg[id].sl=seg[id].sr=seg[id].mx=d[x];
  else{
    ll mid=(x+y)/2;
    build(x,mid,id*2+1);
    build(mid,y,id*2+2);
    seg[id].sum=seg[id*2+1].sum+seg[id*2+2].sum;
    seg[id].sl=max(seg[id*2+1].sl,seg[id*2+1].sum+seg[id*2+2].sl);
    seg[id].sr=max(seg[id*2+2].sr,seg[id*2+2].sum+seg[id*2+1].sr);
    chkmax(seg[id].mx,seg[id*2+1].sr+seg[id*2+2].sl);
    chkmax(seg[id].mx,seg[id].sum);
    chkmax(seg[id].mx,seg[id*2+1].mx);
    chkmax(seg[id].mx,seg[id*2+2].mx);
    chkmax(seg[id].mx,0LL);
  }
}
S qr(ll x,ll y,ll id){
  if(seg[id].l==x && seg[id].r==y) return seg[id];
  ll mid=(seg[id].l+seg[id].r)/2;
  if(y<=mid) return qr(x,y,id*2+1);
  else if(x>=mid) return qr(x,y,id*2+2);
  else{
    S ld,rd,ret;
    ld=qr(x,mid,id*2+1);
    rd=qr(mid,y,id*2+2);
    ret.sum=ld.sum+rd.sum;
    ret.sl=max(ld.sl,ld.sum+rd.sl);
    ret.sr=max(rd.sr,rd.sum+ld.sr);
    ret.mx=max(ld.mx,rd.mx);
    chkmax(ret.mx,ld.sr+rd.sl);
    chkmax(ret.mx,ld.sum+rd.sum);
    chkmax(ret.mx,0LL);
    debug(ret.mx);
    return ret;
  }
}
int main(){
  IOS();
  ll n,q;
  cin>>n>>q;
  REP(i,n) cin>>d[i];
  build(0,n,0);
  while(q--){
    ll l,r;
    cin>>l>>r;
    l--;
    cout<<max(qr(l,r,0).mx,0LL)<<endl;
  }
}
