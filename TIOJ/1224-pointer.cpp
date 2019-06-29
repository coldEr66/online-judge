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
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<", ";_do(_t...);}
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

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

vector<int> yy;
struct node{
  int l,r;
  node *lc,*rc;
  int tag,val;
  node(int _l,int _r,node *_lc,node *_rc,int _tag,int _val):l(_l),r(_r),lc(_lc),rc(_rc),tag(_tag),val(_val){};
  node* build(int L,int R) {
    if (L == R-1) return new node(L,R,0,0,0,0);
    int mid = (L+R)>>1;
    return new node(L,R,build(L,mid),build(mid,R),0,0);
  }
  void pull(node *root) {
    root->val = 0;
    if (root->lc->tag) root->val += (yy[root->lc->r]-yy[root->lc->l]);
    else root->val += root->lc->val;
    if (root->rc->tag) root->val += (yy[root->rc->r]-yy[root->rc->l]);
    else root->val += root->rc->val;
  }
  void ins(node *root,int L,int R,int v) {
    if (root->l == L && root->r == R) {
      root->tag += v;
      return;
    }
    int mid = (root->l + root->r)>>1;
    if (mid >= R) ins(root->lc,L,R,v);
    else if (mid <= L) ins(root->rc,L,R,v);
    else {
      ins(root->lc,L,mid,v);
      ins(root->rc,mid,R,v);
    }
    root->pull(root);
  }
};
struct rec{
  int x,uy,dy,tag;
  bool operator < (const rec &a) const {
    return x < a.x;
  }
} d[MAXn];
int main(){
  IOS();
  int n;
  cin >> n;
  REP (i,n) {
    cin >> d[i*2].x >> d[i*2+1].x >> d[i*2].dy >> d[i*2].uy;
    d[i*2+1].uy = d[i*2].uy;
    d[i*2+1].dy = d[i*2].dy;
    d[i*2].tag = 1;
    d[i*2+1].tag = -1;
    yy.eb(d[i*2].uy);
    yy.eb(d[i*2].dy);
  }
  sort(ALL(yy));
  yy.resize(unique(ALL(yy))-yy.begin());
  sort(d,d+2*n);
  REP (i,2*n) {
    d[i].uy = int(lower_bound(ALL(yy),d[i].uy)-yy.begin());
    d[i].dy = int(lower_bound(ALL(yy),d[i].dy)-yy.begin());
  }
  REP (i,2*n) debug(d[i].x,d[i].uy,d[i].dy);
  node *root = new node(0,MAXn,0,0,0,0);
  root = root->build(0,MAXn);
  ll ans = 0;
  ll cur = 0;
  int lst = 0;
  REP (i,2*n) {
    // debug(d[i].x,lst,cur,d[i].dy,d[i].uy);
    ans += (d[i].x-lst)*cur;
    lst = d[i].x;
    root->ins(root,d[i].dy,d[i].uy,d[i].tag);
    cur = root->val;
  }
  cout << ans << endl;
}
