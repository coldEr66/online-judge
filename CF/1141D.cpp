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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

vector<ll> cts,ctt;
vector<ll> is[30],it[30];
int main(){
  IOS();
  ll n;
  cin >> n;
  string s,t;
  cin >> s >> t;
  REP (i,n) {
    if (s[i] == '?') cts.eb(i);
    else is[s[i]-'a'].eb(i);
  }
  REP (i,n) {
    if (t[i] == '?') ctt.eb(i);
    else it[t[i]-'a'].eb(i);
  }

  vector<ii> ans;
  REP (i,26) {
    debug(is[i],it[i]);
    ll tmp = min(SZ(is[i]),SZ(it[i]));
    REP (j,tmp) {
      ll ta = is[i].back(), tb = it[i].back();
      is[i].pob(), it[i].pob();
      ans.eb(ta,tb);
    }
  }
  debug(ans);
  vector<ll> ta,tb;
  REP (i,26) for (auto u:is[i]) ta.eb(u);
  REP (i,26) for (auto u:it[i]) tb.eb(u);
  debug(ta,tb);
  debug(cts,ctt);
  ll sz = min(SZ(ta),SZ(ctt));
  REP (i,sz) {
    ll tpa = ta.back(), tpb = ctt.back();
    ta.pob(), ctt.pob();
    debug("OK");
    ans.eb(tpa,tpb);
  }
  debug(ans);
  debug(tb,cts);
  debug(min(SZ(tb),SZ(cts)));
  sz = min(SZ(tb),SZ(cts));
  REP (i,sz) {
    debug("HI");
    ll tpa = cts.back(), tpb = tb.back();
    debug(tpa,tpb);
    cts.pob(), tb.pob();
    ans.eb(tpa,tpb);
  }
  debug(ans);
  debug(cts,ctt);
  sz = min(SZ(cts),SZ(ctt));
  REP (i,sz) {
    ll tpa = cts.back(), tpb = ctt.back();
    debug(tpa,tpb);
    cts.pob(), ctt.pob();
    ans.eb(tpa,tpb);
  }
  cout << SZ(ans) << endl;
  for (auto i:ans) cout << i.X+1 << ' ' << i.Y+1 << endl;
}
