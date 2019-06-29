#include <bits/stdc++.h>
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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

struct edge{
  ll u,v,W;
  bool operator < (const edge &a) const {
    return W < a.W;
  }
};
vector<edge> e;
ll w[MAXn];
ll dsu[MAXn],szw[MAXn],sz[MAXn];
ll V[MAXn];
bitset<MAXn> ok;
ll fnd(ll x){
  if (x == dsu[x]) return x;
  return fnd(dsu[x]);
}
void mrg(ll x,ll y){
  dsu[y] = x;
  szw[x] += szw[y];
  sz[x] += sz[y];
}
int main(){
  IOS();
  ll n,m;
  cin >> n >> m;
  REP (i,n) {
    cin >> w[i];
    dsu[i] = i, szw[i] = w[i], sz[i] = 1;
  }
  REP (i,m) {
    ll u,v,W;
    cin >> u >> v >> W;
    u--,v--;
    e.eb((edge){u,v,W});
  }

  sort(ALL(e));
  REP (i,SZ(e)) {
    ll u = fnd(e[i].u), v = fnd(e[i].v);
    if (u == v) continue;
    debug(e[i].W);
    if (sz[u] < sz[v]) {
      swap(u,v);
      swap(e[i].u,e[i].v);
    }
    debug(e[i].u,e[i].v,i);
    V[i] = v;
    debug(v);
    ok[i] = true;
    mrg(u,v);
  }

  ll ans = 0;
  for (ll i=SZ(e)-1;i>=0;i--) {
    // debug(szw[fnd(e[i].u)]);
    // debug(e[i].u,e[i].v,e[i].W);
    ll u = fnd(e[i].u);
    if (szw[u] >= e[i].W) continue;
    ans++;
    // debug(lr[i]);
    if (!ok[i]) continue;
    debug(e[i].v,V[e[i].v]);
    dsu[V[i]] = V[i];
    szw[u] -= szw[V[i]];
    debug(szw[V[e[i].v]],szw[u],e[i].v,u);
  }
  cout << ans << endl;
}
