#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
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

int ka,ti;
struct treap{
  treap *l,*r,*fa;
  ii key;
  int pri,sz;
  string name;
  treap(ii k,string s):l(0),r(0),key(k),pri(rand()),sz(1),name(s){};
  void up(){
    sz=1;
    if( l ) sz+=l->sz;
    if( r ) sz+=r->sz;
  }
};
inline int size(treap *o){return o ?o->sz:0;}
treap *merge(treap *a,treap *b){
  if( !a || !b ) return a ?a:b;
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
void split(treap *o,treap *&a,treap *&b,ii k){
  if( !o ) a=b=0;
  else{
    if( o->key < k ){
      a=o;
      split(o->r,a->r,b,k);
    }
    else{
      b=o;
      split(o->l,a,b->l,k);
    }
    o->up();
  }
}
void split2(treap *o,treap *&a,treap *&b,int k){
  if( !o ) a=b=0;
  else{
    if( size(o->l)+1 <= k ){
      int tmp = k-size(o->l)-1;
      a=o;
      split2(o->r,a->r,b,tmp);
    }
    else{
      b=o;
      split2(o->l,a,b->l,k);
    }
    o->up();
  }
}
void ins(treap *&root,string s,ii k){
  if( !root ) root = new treap(k,s);
  else{
    treap *a=0,*b=0;
    split(root,a,b,k);
    root = merge(a,merge(new treap(k,s),b));
  }
}
string gogo(treap *&root,ii k){
  // if( root )debug(root->key.X);
  if( !root ) return "";
  // debug("HI");
  if( root->key > k && ( !root->l || root->l->key < k ) ){
    treap *v = root;
    string ret = v->name;
    root = merge(root->l,root->r);
    // if( !v ) return "";
    // debug("OK");
    delete v;
    v=0;
    return ret;
  }
  treap *&v = root->key < k ?root->r:root->l;
  // debug("QQ");
  return gogo(v,k);
}
void erase(treap *&o,ii k){
  if( !o ) return;
  if( o->key == k ){
    treap *t = o;
    o = merge(o->l,o->r);
    delete t;
    return;
  }
  treap *t = o->key > k ?o->l:o->r;
  erase(t,k);
}
void sol(treap *&o,int k){
  treap *a,*b,*c;
  debug("alive");
  split(o,a,c,mkp(k,-INF));
  split2(c,b,c,1);
  debug("ok");
  o = merge(a,c);
  if( b ) cout<<b->name<<endl;
  else cout<<"WAIT..."<<endl;
  delete b;
}
void del(treap *&root){
  if( root->l ) del(root->l);
  if( root->r ) del(root->r);
  root->up();
  delete root;
  root=0;
}
void print_tree(treap *node){
  if( node->l ) print_tree(node->l);
  cout<<node->name<<' ';
  if( node->r ) print_tree(node->r);
}
int main(){
  IOS();
  srand(time(0));
  int t;
  cin>>t;
  while( t-- ){
    cout<<"Case #"<<++ka<<":"<<endl;
    treap *root = 0;
    ti=0;
    int n;
    cin>>n;
    string cmd;
    while( n-- ){
      cin>>cmd;
      if( cmd[0]=='A' ){
        string s;
        int tmp;
        cin>>s>>tmp;
        ins(root,s,mkp(tmp,ti++));
        cout<<size(root)<<endl;
      }
      else{
        int tmp;
        cin>>tmp;
        // // if( !root ){
        // //   cout<<"WAIT..."<<endl;
        // //   continue;
        // // }
        // treap *ret = NULL;
        // if( !root ){
        //   cout<<"WAIT..."<<endl;
        //   continue;
        // }
        // sol(root,ret,mkp(tmp,-INF));
        // if( !ret ) cout<<"WAIT..."<<endl;
        // else{
        //   cout<<ret->name<<endl;
        //   erase(root,ret->key);
        // }
        // string ans = gogo(root,mkp(tmp,-INF));
        // // debug("alive");
        // if( ans=="" ) cout<<"WAIT..."<<endl;
        // else cout<<ans<<endl;
        sol(root,tmp);
      }
      // cout<<"print"<<endl;
      // if( root ) print_tree(root);
      // cout<<endl;
    }
    if( root ) del(root);
  }
}
// 2
// 5
// Add lcy 1
// Add lyd 19
// Find 11
// Find 13
// Add zxs 10
// 5
// Add lcy 1
// Add lyd 19
// Find 11

// 1
// 10
// A l 11
// A s 12
// A e 24
// F 11
// F 11

// 1
// 10
// A l 3
// A ll 4
// A bb 3
// A lf 4
// F 2
// F 2
