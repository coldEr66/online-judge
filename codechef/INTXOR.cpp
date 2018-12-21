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

const ll MAXn=5e4+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll n;
ll d[MAXn], ans[MAXn];
ll cnt[15]; // 0-indexed
void sol4(ll x){
  RST(cnt,0);
  ll now = 0;
  REP (i,4) {
    cout << 1 << ' ';
    REP (j,3) cout << d[(now+j)%4+x-1] << " \n"[j==2];
    cout.flush();
    ll tmp;
    cin >> tmp;
    cnt[i] = tmp;
    now++;
  }
  ans[x] = cnt[0]^cnt[1]^cnt[3];
  now = 1;
  REP (i,3) {
    ll tmp = cnt[now]^cnt[(now+1)%4];
    tmp ^= ans[now%4+x-1];
    now = (now+3)%4;
    ans[now+x-1] = tmp;
  }
  pary(ans,ans+n);
}
void sol5(ll x){
  RST(cnt,0);
  ll now = 0;
  REP (i,5) {
    cout << 1 << ' ';
    REP (j,3) cout << d[(now+j)%5+x-1] << " \n"[j==2];
    cout.flush();
    ll tmp;
    cin >> tmp;
    cnt[i] = tmp;
    now++;
  }
  ans[x-1] = cnt[1]^cnt[2]^cnt[4];
  now = 0;
  REP (i,4) {
    ll tmp = cnt[now]^cnt[(now+1)%5];
    tmp ^= ans[now%5+x-1];
    now = (now+3)%5;
    ans[now+x-1] = tmp;
  }
}
int main(){
  IOS();
  REP(i,MAXn) d[i] = i+1;
  ll t;
  cin >> t;
  while (t--) {
    RST(ans,0);
    cin >> n;
    if(n == 11){
      ll cur = 0;
      REP (i,n) {
        cout << 1 << ' ';
        REP (j,3) cout << d[(cur+j)%n] << " \n"[j==2];
        cout.flush();
        cur++;
        ll tmp;
        cin >> tmp;
        cnt[i] = tmp;
      }
      pary(cnt,cnt+n);
      for(int i=0;i<=6;i+=3) ans[10] = ans[10]^cnt[i]^cnt[i+1];
      ans[10] ^= cnt[9];
      debug(ans[10]);
      cur = 10;
      ll now = 10;
      ll tp = 10;
      while(tp--){
        ll tmp = cnt[cur]^ans[cur];
        cur = (cur+1)%n;
        tmp ^= cnt[cur];
        now = (now+3)%n;
        ans[now] = tmp;
      }
      pary(ans,ans+n);
      cout << 2 << ' ';
      REP (i,n) cout << ans[i] << " \n"[i==n-1];
      cout.flush();
      ll x;
      cin >> x;
      continue;
    }
    ll tp1 = 0, tp2 = 0;
    ll u = n;
    while (u%4 != 0) {
      tp1++;
      u-=5;
    }
    tp2 = u/4;
    ll cur = 1;
    while(tp1--){
      sol5(cur);
      cur += 5;
    }
    while(tp2--){
      sol4(cur);
      cur += 4;
    }
    cout << 2 << ' ';
    REP (i,n) cout << ans[i] << " \n"[i==n-1];
    cout.flush();
    ll x;
    cin >> x;
    if(x == -1) return 0;
  }
}
/*
2 4 9 7 6 1 5 8 2 3 4     1 10 15 1 10 6 7 12 13 2 9
3 8 2 9
2 6 9 15 3      12 4 10 8 11
3 8 6 7 6 6 9 7 14    8 2 9 3 12 4 10 8 11
*/
