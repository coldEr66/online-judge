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
  ll pri,key;
  treap(ll k):l(0),r(0),pri(rand()),key(k){}
};
inline ll kk(treap *o){return o ?o->key:-INF;}
treap *merge(treap *a,treap *b){
  if( !a || !b ) return a?a:b;
  if( a->pri < b->pri ){
    a->r = merge(a->r,b);
    return a;
  }
  else{
    b->l = merge(a,b->l);
    return b;
  }
}
void split(treap *o,treap *&a,treap *&b,ll k){
  // if( o )debug(o->key);
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
  }
}
void ins(treap *&o,ll x){
  if( !o ){
    o = new treap(x);
    return;
  }
  treap *a,*b;
  split(o,a,b,x);
  o = merge(a,merge(new treap(x),b));
}
void del(treap *&o,ll x){
  treap *a,*b,*c;
  split(o,a,b,x);
  split(b,b,c,x+1);
  treap *kll = b;
  b = merge(b->l,b->r);
  delete kll;
  o = merge(a,merge(b,c));
}
ii qr(treap *&o,ll x){
  treap *a,*b;
  split(o,a,b,x);
  treap *c=a,*d=b;
  if( a )while( a->r ) a = a->r;
  if( b )while( b->l ) b = b->l;
  o = merge(c,d);
  return mkp(kk(b),kk(a));
}
void p_tree(treap *o){
  if( o->l ) p_tree(o->l);
  cout<<o->key<<' ';
  if( o->r ) p_tree(o->r);
}
int main(){
  IOS();
  srand(time(0));
  treap *root = 0;
  ll n;
  cin>>n;
  while(n--){
    string s;
    ll x;
    cin>>s>>x;
    if( s[0]=='i' ) ins(root,x);
    else if( s[0]=='d') del(root,x);
    else{
      ii ans = qr(root,x);
      // debug(ans);
      if( abs(ans.X-x)<abs(x-ans.Y) ) cout<<ans.X<<endl;
      else if( abs(ans.X-x)==abs(x-ans.Y) ) cout<<ans.Y<<' '<<ans.X<<endl;
      else cout<<ans.Y<<endl;
    }
    // cout<<"P"<<' ';
    // p_tree(root);
    // cout<<endl;
  }
}
