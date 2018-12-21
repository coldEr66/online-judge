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

const ll MAXn=1e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll n;
string s[MAXn];
vector<pair<string,ll>> v[MAXn];
bool ans[MAXn];
void sol(string a){
  REP1 (i,n-1) {
    string tmp = v[i][0].X;
    bool fg = true;
    REP (j,i) if (tmp[j] != a[j]) fg = false;
    ans[v[i][0].Y] = fg;
    ans[v[i][1].Y] = !fg;
  }
}
bool chk(string a){
  REP1 (i,n-2) {
    string tmp1 = v[i][0].X;
    string tmp2 = v[i][1].X;
    bool fg = true;
    REP (j,i) if (tmp1[j] != a[j]) fg = false;
    REP (j,i) if (tmp2[j] != a[n-i+j]) fg = false;
    if (!fg) {
      swap(tmp1,tmp2);
      fg = true;
      REP (j,i) if (tmp1[j] != a[j]) fg = false;
      REP (j,i) if (tmp2[j] != a[n-i+j]) fg = false;
    }
    if (!fg) return false;
  }
  return true;
}
int main(){
  IOS();
  cin >> n;
  REP (i,2*n-2) {
    cin >> s[i];
    v[SZ(s[i])].eb(s[i],i);
  }
  string a;
  bool fg = true;
  string ta = v[n-1][0].X,tb = v[n-1][1].X;
  debug(ta,tb);
  REP (i,n-2) if (ta[i+1] != tb[i]) fg = false;
  if (fg) {
    swap(ta,tb);
    REP (i,n-2) if (ta[i+1] != tb[i]) fg = false;
    if (!fg) {
      a = tb + ta[n-2];
      sol(a);
    }
    else {
      string x = tb+ta[n-2];
      string y = ta+tb[n-2];

      if (chk(x)) sol(x);
      else sol(y);
    }
  }
  else {
    a = tb+ta[n-2];
    debug(a);
    sol(a);
  }
  REP (i,2*n-2) cout << (ans[i] ?'P':'S');
  cout << endl;
}
