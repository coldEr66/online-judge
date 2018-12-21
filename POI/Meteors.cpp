#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
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

const ll MAXn=3e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll n,m;
struct query{
  ll l,r,w;
} q[MAXn];
vector<ll> planet[MAXn], dt;
ll d[MAXn], zkw[MAXn*2], ans[MAXn];
void ins(ll l,ll r,ll v){
  for(l+=m,r+=m;l<r;l>>=1,r>>=1){
    if(l&1) zkw[l++] += v;
    if(r&1) zkw[--r] += v;
  }
}
ll qr(ll r){
  ll ret = 0;
  for(r+=m;r>0;r>>=1) ret += zkw[r];
  return ret;
}
void gogo(ll l,ll mid,ll cmd){
  for(ll i=l;i<=mid;i++){
    ll tmpl = q[i].l, tmpr = q[i].r, val = q[i].w*cmd;
    debug(tmpl,tmpr,val);
    if(tmpl > tmpr){
      ins(tmpl,m+1,val);
      ins(1,tmpr+1,val);
    }
    else ins(tmpl,tmpr+1,val);
  }
}
void split(ll M,vector<ll> &x,vector<ll> &s,vector<ll> &t){
  for(ll i:x){
    ll tmp = 0;
    REP(j,SZ(planet[i])){
      debug(planet[i][j],qr(planet[i][j]));
      tmp += qr(planet[i][j]);
      debug(tmp);
      if(tmp >= d[i]) break;
    }
    debug(tmp,i);
    if(tmp >= d[i]){
      chkmin(ans[i],M);
      s.eb(i);
    }
    else{
      d[i] -= tmp;
      t.eb(i);
    }
  }
}
void sol(ll l,ll r,vector<ll> &vec){
  debug(l,r);
  if(l == r){
    for(ll i:vec) ans[i] = l;
    return;
  }
  if(!SZ(vec)) return;
  ll mid = (l+r)>>1;
  gogo(l,mid,1);
  vector<ll> a,b; // a is finished
  split(mid,vec,a,b);
  gogo(l,mid,-1);
  debug(a,b);
  sol(l,mid,a);
  sol(mid+1,r,b);
}
int main(){
  IOS();
  cin >> n >> m;
  REP1(i,m){
    ll x;
    cin >> x;
    planet[x].eb(i);
  }
  REP1(i,n){
    cin >> d[i];
    dt.eb(i);
  }
  ll k;
  cin >> k;
  REP(i,k) cin >> q[i].l >> q[i].r >> q[i].w;
  sol(0,k,dt);
  REP1(i,n){
    if(ans[i] == k) cout<<"NIE"<<endl;
    else cout<<ans[i]+1<<endl;
  }
}
