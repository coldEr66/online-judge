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

vector<ll> f,s;
bool cnt[MAXn];
ll ans;
void dfs(ll x,ll gal,vector<ll> &tmp1,vector<ll> &tmp2){
  if (x == 4) {
    // debug(gal);
    if (cnt[gal] == false) {
      ans++,cnt[gal] = true;
      // debug(gal,tmp1,tmp2);
    }
    return;
  }
  if (x&1) { //2,4
    vector<ll> tp1 = tmp2;
    vector<ll> tp2 = tmp1;
    REP (i,SZ(tp2)) {
      ll tt = tp2[i];
      tp1.eb(tt);
      tp2.erase(tp2.begin()+i);
      dfs(x+1,gal+tt,tp1,tp2);
      tp1.pob();
      tp2.insert(tp2.begin()+i,tt);
    }
  }
  else { //1,3,5
    vector<ll> tp1 = tmp2;
    vector<ll> tp2 = tmp1;
    REP (i,SZ(tp2)) {
      ll tt = tp2[i];
      tp1.eb(tt);
      tp2.erase(tp2.begin()+i);
      dfs(x+1,gal-tt,tp1,tp2);
      tp1.pob();
      tp2.insert(tp2.begin()+i,tt);
    }
  }
}
int main(){
  IOS();
  freopen("backforth.in","r",stdin);
  freopen("backforth.out","w",stdout);

  REP (i,10) {
    ll x;
    cin >> x;
    f.eb(x);
  }
  REP (i,10) {
    ll x;
    cin >> x;
    s.eb(x);
  }

  dfs(0,1000,f,s);
  // REP (i,MAXn) if (cnt[i]) debug(i);
  cout << ans << endl;
}
