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

const ll MAXn=5e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

string s,t;
ll scnt,tcnt;
ll f[MAXn];
void build(){
  ll cur=f[0]=-1;
  for(int i=1;t[i];i++){
    while(cur!=-1 && t[i]!=t[cur+1]) cur=f[cur];
    if(t[i]==t[cur+1]) cur++;
    f[i]=cur;
  }
}
ll cal(string x,ll z,ll o){
  ll a = 0, b = 0;
  REP (i,SZ(x)) {
    if (x[i] == '0') a++;
    else b++;
  }
  ll tmp = 0;
  if (a == 0 || b == 0) {
    if (a != 0) tmp = z/a;
    if (b != 0) tmp = o/b;
  }
  else tmp = min(o/b,z/a);
  return tmp;
}
int main(){
  IOS();
  cin >> s >> t;
  REP (i,SZ(s)) if (s[i] == '1') scnt++;
  REP (i,SZ(t)) if (t[i] == '1') tcnt++;

  build();

  pary(f,f+SZ(t));
  ll tmp = f[SZ(t)-1]+1;
  string pre = t.substr(0,tmp);
  string tt = t.substr(tmp,SZ(t)-tmp);
  string ans = "";
  debug(pre,tt);
  if (tmp != 0) {
    if (!cal(pre,SZ(s)-scnt,scnt)) return cout << s << endl,0;
    ll z = SZ(s)-scnt, o = scnt;
    REP (i,SZ(pre)) {
      if (pre[i] == '0') z--;
      if (pre[i] == '1') o--;
    }
    ll ct = cal(tt,z,o);
    ans = pre;
    REP (i,ct) ans += tt;
    ll zz = 0, oo = 0;
    REP (i,SZ(tt)) {
      if (tt[i] == '0') zz++;
      if (tt[i] == '1') oo++;
    }
    z -= zz*ct, o -= oo*ct;
    REP (i,z) ans += '0';
    REP (i,o) ans += '1';
    cout << ans << endl;
    debug("ALIVE");
  }
  else {
    ll ct = cal(t,SZ(s)-scnt,scnt);
    REP (i,ct) ans += t;
    debug(SZ(s)-scnt-ct * (SZ(t)-tcnt));
    REP (i,SZ(s)-scnt-ct * (SZ(t)-tcnt)) ans += '0';
    REP (i,scnt - ct * tcnt) ans += '1';
    cout << ans << endl;
  }
}
