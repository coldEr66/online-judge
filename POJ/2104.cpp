#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<sstream>
#include<queue>
#include<cmath>
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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

struct node{
  int sum;
  node *lc,*rc;
  node():sum(0),lc(0),rc(0){}
};
// vector<node*> ptr;
node *root[MAXn];
vector<int> d,rk;
node *ins(node *x,node *&cur,int l,int r,int data){
  debug(l,r);
  cur = new node();
  // ptr.eb(cur);
  debug("QAQ");
  *cur = *x;
  cur->sum++;
  if( l==r-1 ) return cur;
  // debug("?");
  int mid = (l+r)/2;
  if( data<mid ){
    if( !x->lc ){
      x->lc = new node();
      // ptr.eb(x->lc);
      // debug(x->lc->sum);
    }
    ins(x->lc,cur->lc,l,mid,data);
  }
  else{
    if( !x->rc ){
      x->rc = new node();
      // ptr.eb(x->rc);
    }
    ins(x->rc,cur->rc,mid,r,data);
  }
  return cur;
}
int qr(node *&x,node *&y,int l,int r,int k){
  if( l==r-1 ) return d[l];
  int xtmp = x->lc ?x->lc->sum:0;
  int ytmp = y->lc ?y->lc->sum:0;
  int tmp = ytmp-xtmp;
  int mid = (l+r)/2;
  if( k<=tmp ){
    if( !x->lc ){
      x->lc = new node();
      // ptr.eb(x->lc);
    }
    return qr(x->lc,y->lc,l,mid,k);
  }
  else{
    if( !x->rc ){
      x->rc = new node();
      // ptr.eb(x->rc);
    }
    return qr(x->rc,y->rc,mid,r,k-tmp);
  }
}
int main(){
  IOS();
  // int t;
  // cin>>t;
  // while(t--){
    int n,q;
    cin>>n>>q;
    d.clear();
    rk.clear();
    d.eb(-INF);
    rk.eb(-INF);
    REP(i,n){
      int x;
      cin>>x;
      d.eb(x);
      rk.eb(x);
    }
    sort(ALL(d));
    auto it = d.begin();
    it++;
    d.resize(unique(it,d.end())-it);
    int sz = SZ(d);
    sz++;
    debug(sz);
    REP1(i,n) rk[i] = int((lower_bound(it,d.end(),rk[i])-it)+1);
    root[0] = new node();
    REP1(i,n){
      ins(root[i-1],root[i],1,sz,rk[i]);
      debug("hi");
    }
    debug("HI");
    while(q--){
      int l,r,k;
      cin>>l>>r>>k;
      int ans = qr(root[l-1],root[r],1,sz,k);
      cout<<ans<<endl;
    }
    // for( auto i:ptr ) delete i;
    // ptr.clear();
  // }
}
