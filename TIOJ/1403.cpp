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

const ll MAXn=250005,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000;
const ll INF=0x3f3f3f3f;
const lf eps = 1e-6;

int bit[305],x[MAXn],v[MAXn];
struct car{
  int l,r;
  lf t;
  car(int _l,int _r) {
    l = _l, r = _r;
    t = lf((x[r]-x[l])/lf(v[l]-v[r]));
  }
  bool operator < (const car &a) const {
    if (fabs(t-a.t) > eps) return t < a.t;
    return lf((lf)x[l] + t*lf(v[l])) < lf((lf)x[a.l] + a.t*lf(v[a.l]));
  }
};
int pre[MAXn],nxt[MAXn];
set<car> st;
void event(int a) {
  int b = nxt[a];
  if (!a || !b || v[b] >= v[a]) return;
  st.insert(car(a,b));
}
int lowbit(int a){return a&(-a);}
void ins(int a) {
  for(;a<=105;a+=lowbit(a)) bit[a]++;
}
int qr(int a) {
  int ret = 0;
  for(;a>0;a-=lowbit(a)) ret += bit[a];
  return ret;
}
void add(int &a,int b) {
  a = (a+b)%MOD;
}
int main(){
  IOS();
  int n;
  cin >> n;
  REP1 (i,n) cin >> x[i] >> v[i];
  int ans = 0;
  for (int i=n;i>0;i--) {
    add(ans,qr(v[i]-1));
    ins(v[i]);
  }
  cout << ans << endl;
  REP1 (i,n) {
    pre[i] = i-1;
    nxt[i] = i+1;
    if (i == n) nxt[i] = 0;
    event(i);
  }
  int cnt = 0;
  while (SZ(st)) {
    car cur = *st.begin();
    st.erase(st.begin());
    cout << cur.l << ' ' << cur.r << endl;
    int tp1 = pre[cur.l], tp2 = nxt[cur.r];
    st.erase(car(tp1,cur.l));
    st.erase(car(cur.r,tp2));
    pre[cur.r] = tp1;
    nxt[cur.l] = tp2;
    nxt[tp1] = cur.r;
    pre[tp2] = cur.l;
    pre[cur.l] = cur.r;
    nxt[cur.r] = cur.l;
    event(tp1);
    event(cur.l);
    cnt++;
    if (cnt >= 10000) break;
  }
}
