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

const ll MAXn=1e4+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll sg[1005];
void build(){
  sg[0] = 0;
  sg[1] = 1;
  sg[2] = 1;
  sg[3] = 1;
  sg[4] = 2;
  sg[5] = 2;
  for (ll i=6;i<=1000;i++) {
    vector<bool> tmp(1000,0);
    for (ll j=1;j<=(i+1)>>1;j++) {
      // if (j-3 > 0) tmp[sg[j-3]] = true;
      // if (i-j-3 > 0) tmp[sg[i-j-2]] = true;
      ll tp = sg[max(0LL,j-3)]^sg[max(0LL,i-j-2)];
      tmp[tp] = true;
    }
    for (ll j=0;;j++) {
      if (!tmp[j]) {
        sg[i] = j;
        break;
      }
    }
  }
}
int main(){
  IOS();
  build();
  ll t;
  cin >> t;
  debug(sg[6]);
  while (t--) {
    ll n;
    cin >> n;
    ll ans = 0;
    bool draw = true;
    REP (i,n) {
      ll x;
      cin >> x;
      if (x == 2) continue;
      if (x > 2) draw = false;
      ans ^= sg[x];
    }
    if (draw) cout << "Draw" << endl;
    else if (ans != 0) cout << "First" << endl;
    else cout << "Second" << endl;
  }
}
