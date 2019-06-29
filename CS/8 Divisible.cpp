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

ll cnt[11];
string s;
string trans(ll x){
  string ret = "";
  while (x) {
    ret += char(x%10 + '0');
    x /= 10;
  }
  if (SZ(ret) < SZ(s)) {
    while (SZ(ret) < 3) ret += '0';
  }
  reverse(ALL(ret));
  return ret;
}
int main(){
  IOS();
  cin >> s;
  REP (i,SZ(s)) cnt[s[i]-'0']++;

  pary(cnt,cnt+10);
  string ans = "";
  for (ll i=0;i<1000;i+=8) {
    string tmp = trans(i);
    REP (j,SZ(tmp)) cnt[tmp[j]-'0']--;
    pary(cnt,cnt+10);
    string cur = "";
    bool ok = true;
    REP (j,10) if (cnt[j] < 0) {
      ok = false;
      break;
    }
    bool c = true;
    for (ll j=1;j<=9;j++) {
      REP (k,cnt[j]) {
        cur += char(j+'0');
        if (k == 0 && c) {
          REP (T,cnt[0]) cur += '0';
          c = false;
        }
      }
    }
    if (c && cnt[0] > 0) ok = false;
    cur += tmp;
    debug(cur,ok);
    if (cur[0] == '0') ok = false;
    if (ok) {
      if (ans == "") ans = cur;
      else if (cur < ans) ans = cur;
    }
    // debug("ALIVE");
    REP (j,SZ(tmp)) cnt[tmp[j]-'0']++;
  }
  if (ans == "") cout << -1 << endl;
  else cout << ans << endl;
}
