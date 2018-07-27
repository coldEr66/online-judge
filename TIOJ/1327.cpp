#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
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
const ll INF=0x3f3f3f3f3f3f3f3f;

struct E{
  ll fr,to,w;
  bool operator <(const E &a){
    return w<a.w;
  }
};
ll fa[MAXn],sz[MAXn];
ll fd(ll x){return fa[x] = (x==fa[x] ?x:fd(fa[x]));}
void uni(ll a,ll b){
  a=fd(a), b=fd(b);
  if(sz[a]<sz[b]) swap(a,b);
  fa[b] = a;
  sz[a]+=sz[b];
  sz[b] = 0;
}
vector<pair<ii,ll>> d;
vector<E> e;
bool cmp(const pair<ii,ll> &a,const pair<ii,ll> &b){
  if(a.X.Y==b.X.Y) return a.X.X<b.X.X;
  else return a.X.Y<b.X.Y;
}
int main(){
  IOS();
  int t;
  cin>>t;
  while(t--){
    ll n;
    cin>>n;
    d.clear();
    e.clear();
    REP(i,n){
      fa[i] = i;
      sz[i] = 1;
    }
    REP(i,n){
      ll x,y;
      cin>>x>>y;
      d.pb(mkp(mkp(x,y),i));
    }
    sort(ALL(d));
    d.resize(unique(ALL(d))-d.begin());
    n = SZ(d);
    REP(i,n-1)if(d[i].X.X==d[i+1].X.X) e.pb((E){d[i].Y,d[i+1].Y,abs(d[i].X.Y-d[i+1].X.Y)});
    sort(ALL(d),cmp);
    REP(i,n-1)if(d[i].X.Y==d[i+1].X.Y) e.pb((E){d[i].Y,d[i+1].Y,abs(d[i].X.X-d[i+1].X.X)});
    sort(ALL(e));
    REP(i,SZ(e)) debug(e[i].fr,e[i].to,e[i].w);
    ll ans = 0;
    REP(i,SZ(e)){
      ll x=e[i].fr,y=e[i].to,w=e[i].w;
      if(fd(x)==fd(y)) continue;
      uni(x,y);
      ans+=w;
    }
    cout<<ans<<endl;
  }
}