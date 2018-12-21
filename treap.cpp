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

struct treap{
  treap *l,*r;
  ll val,pri,sz;
  treap(ll k):l(0),r(0),val(k),pri( rand() ),sz(1){};
  void up(){
    sz=1;
    if( l ) sz+=l->sz;
    if( r ) sz+=r->sz;
  }
};
treap *merge(treap *a,treap *b){
  if( !a || !b ) return a ?a:b;
  // debug("hi");
  if( a->pri < b->pri ){
    a->r = merge(a->r,b);
    a->up();
    return a;
  }
  else{
    b->l = merge(a,b->l);
    b->up();
    return b;
  }
}
inline ll size(treap *o){return o ?o->sz:0LL;}
void print_tree(treap *root){
  if( root->l ) print_tree(root->l);
  cout<<root->pri<<' ';
  if( root->r ) print_tree(root->r);
}
bool erase(treap *&o,ll k){
  if( !o ) return false;
  if( o->val == k ){
    treap *t = o;
    o = merge(o->l,o->r);
    delete t;
    return true;
  }
  treap *t = k < o->val ?o->l:o->r;
  if( erase(t,k) ) return o->up(),true;
  else return false;
}
void split1(treap *o,treap *&a,treap *&b,ll k){
  if( !o ) a=b=0;
  else{
    if( o->val < k ){
      a=o;
      split1(o->r,a->r,b,k);
    }
    else{
      b=o;
      split1(o->l,a,b->l,k);
    }
    o->up();
  }
}
void split2(treap *o,treap *&a,treap *&b,ll k){
  if( !o ) a=b=nullptr;
  else{
    if( k >= size(o->l)+1 ){
      ll tmp = k-(size(o->l)+1);
      a=o;
      split2(o->r,a->r,b,tmp);
    }
    else{
      b=o;
      split2(o->l,a,b->l,k);
    }
    o->up();
    // if( a ){
    //   cout<<"a: ";
    //   print_tree(a);
    //   cout<<endl<<endl;
    // }
    // if( b ){
    //   cout<<"b: ";
    //   print_tree(b);
    //   cout<<endl<<endl;
    // }
  }
}
void ins(treap *&root,ll k){
  if( !root ) root = new treap(k);
  else{
    treap *a,*b;
    split1(root,a,b,k);
    root = merge(a,merge(new treap(k),b));
  }
}
inline treap *kth(treap *&root,ll k){
  treap *a,*b,*c;
  split2(root,a,c,k);
  split2(a,a,b,k-1);
  root = merge(a,merge(b,c));
  return b;
}
int main(){
  IOS();
  srand(time(0));
  treap *root = 0;
  ll n,k;
  cin>>n>>k;
  REP(i,n){
    ll x;
    cin>>x;
    // debug("HI");
    ins(root,x);
    // print_tree(root);
    // cout<<endl<<endl;
  }
  // debug("ok");
  treap *ans = kth(root,k);
  cout<<ans->val<<endl;
}
