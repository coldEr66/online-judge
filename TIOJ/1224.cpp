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
#define eb emplace_back
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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

vector<int> yy;
struct node{
  int l,r;
  int val,tag;
} seg[MAXn*4];
struct rec{
  int x,dy,ty,k;
  bool operator < ( const rec &a )const{
    return x<a.x;
  }
} d[MAXn<<1];
void build(int id,int l,int r) {
  seg[id].l = l, seg[id].r = r;
  seg[id].tag = seg[id].val = 0;
  if (l == r-1) return;
  int mid = (l+r)>>1;
  build(id*2+1,l,mid);
  build(id*2+2,mid,r);
}
void ins(int L,int R,int l,int r,int id,int k){
  if( l==L && r==R ){
    seg[id].tag+=k;
    return;
  }
  int mid = (L+R)>>1;
  if( r<=mid ) ins(L,mid,l,r,id*2+1,k);
  else if( l>=mid ) ins(mid,R,l,r,id*2+2,k);
  else{
    ins(L,mid,l,mid,id*2+1,k);
    ins(mid,R,mid,r,id*2+2,k);
  }
  seg[id].val = (seg[id*2+1].tag ?yy[seg[id*2+1].r]-yy[seg[id*2+1].l]:seg[id*2+1].val) +
                (seg[id*2+2].tag ?yy[seg[id*2+2].r]-yy[seg[id*2+2].l]:seg[id*2+2].val);
}
int main(){
  IOS();
  int n;
  cin>>n;
  REP(i,n){
    cin>>d[i*2].x>>d[i*2+1].x>>d[i*2].dy>>d[i*2].ty;
    d[i*2+1].dy = d[i*2].dy;
    d[i*2+1].ty = d[i*2].ty;
    d[i*2].k = 1;
    d[i*2+1].k = -1;
    yy.eb(d[i*2].dy);
    yy.eb(d[i*2].ty);
   }
   sort(d,d+2*n);
   sort(ALL(yy));
   yy.resize(unique(ALL(yy))-yy.begin());
   debug(yy);
   REP (i,2*n) {
     d[i].ty = int(lower_bound(ALL(yy),d[i].ty)-yy.begin());
     d[i].dy = int(lower_bound(ALL(yy),d[i].dy)-yy.begin());
   }
   ll ans=0,cur=0,tmp=0;
   build(0,0,MAXn);
   REP(i,2*n){
     ans+=(d[i].x-cur)*tmp;
     cur = d[i].x;
     ins(0,MAXn,d[i].dy,d[i].ty,0,d[i].k);
     tmp = seg[0].val;
   }
   cout<<ans<<endl;
}
