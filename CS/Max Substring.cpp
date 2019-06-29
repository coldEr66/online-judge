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

ll cnt[30];
vector<ll> idx[30];
ll llen[30];
vector<string> ans;
int main(){
  IOS();
  string s;
  cin >> s;
  ll n = SZ(s);

  REP (i,n) cnt[s[i]-'a']++;
  ll mx = *max_element(cnt,cnt+26);
  vector<ll> tmp;
  REP (i,26) if (cnt[i] == mx) tmp.eb(i);
  REP (i,SZ(s)) {
    if (cnt[s[i]-'a'] == mx) idx[s[i]-'a'].eb(i);
  }
  ll mlen = 1;
  REP (i,SZ(tmp)) {
    ll cur = tmp[i];
    debug(cur);
    ll len = 1;
    while (1) {
      bool ok = true;
      REP (j,SZ(idx[cur])-1) {
        if (idx[cur][j] + len >= idx[cur][j+1]) {
          debug(cur,len);
          llen[cur] = len;
          break;
        }
      }
      if (llen[cur] != 0) break;
      if (idx[cur][0]+len >= SZ(s)) {
        llen[cur] = len;
        break;
      }
      char nxt = s[idx[cur][0]+len];
      if (cnt[nxt-'a'] != mx) {
        llen[cur] = len;
        break;
      }
      for (ll j=1;j<SZ(idx[cur]);j++) {
        if (idx[cur][j]+len >= SZ(s) || s[idx[cur][j]+len] != nxt) {
          ok = false;
          break;
        }
      }
      if (!ok) {
        debug(cur,len);
        llen[cur] = len;
        break;
      }
      else len++;
    }
    mlen = max(mlen,llen[cur]);
  }
  REP (i,26) {
    if (llen[i] == mlen) {
      cout << s.substr(idx[i][0],mlen) << endl;
      return 0;
    }
  }
}
