/*
1
6
3 4
4 5
4 5
4 5
3 5
3 4
*/
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

const ll MAXn=1e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3ff3f3f;

ll n,t;
vector<ll> dt,tg,e[MAXn];
map<ii,vector<ll>> mp;
ll lev[MAXn],ok[MAXn],cnt[MAXn],in[MAXn];
void BFS(ll x){
  queue<ll> q;
  q.push(x);
  while(SZ(q)){
    ll cur = q.front();
    debug(cur);
    q.pop();
    for (auto i:e[cur]) {
      chkmax(lev[i],lev[cur]+1);
      q.push(i);
    }
  }
}
ll sol6(){
  debug("alive");
  REP (i,6) {
    cout << '?';
    REP (j,5) {
      ll cur = (i+j)%6;
      cout << ' ' << tg[cur];
    }
    cout << endl;
    cout.flush();
    ll x,y;
    cin >> x >> y;
    mp[mkp(x,y)].eb(i);
    e[x].eb(y);
    ok[x] = ok[y] = 1;
    in[y]++;
  }
  REP1 (i,n) {
    if (!SZ(e[i])) continue;
    sort(ALL(e[i]));
    unique(ALL(e[i]));
  }
  REP1 (i,n) if (ok[i] == 1 && in[i] == 0) {
    BFS(i);
    break;
  }
  pary(lev,lev+100);
  ii d;
  REP1 (i,n) {
    if (lev[i] == 1) d.X = i;
    if (lev[i] == 2) d.Y = i;
  }
  debug(d);
  for (auto it:mp[d]) {
    REP (j,5) {
      ll cur = (it+j)%6;
      if (tg[cur] == d.X || tg[cur] == d.Y) continue;
      cnt[tg[cur]]++;
    }
  }
  ll tmp = 0, ret = -1;
  REP1 (i,n) if (chkmax(tmp,cnt[i])) ret = i;
  return ret;
}
int main(){
  IOS();
  cin >> t;
  while (t--) {
    RST(lev,0);
    RST(ok,-1);
    RST(in,0);
    RST(cnt,0);
    dt.clear();
    REP(i,MAXn) e[i].clear();
    mp.clear();
    cin >> n;
    ll ct = n;
    REP1 (i,5) dt.eb(i);
    ll now = 6;
    if (n > 7) {
      debug(dt);
      while (ct-2 >= 6) {
        cout << '?';
        for (auto i:dt)  cout << ' ' << i;
        cout << endl;
        cout.flush();
        ll x,y;
        cin >> x >> y;
        REP (i,5) if(dt[i] == x) dt[i] = now;
        now++;
        REP (i,5) if(dt[i] == y) dt[i] = now;
        debug(dt);
        now++;
        ct -= 2;
      }
    }
    tg = dt;
    while (now <= n) tg.eb(now++);
    debug(ct);
    debug(tg);
    if (SZ(tg) == 6) {
      ll ans = sol6();
      cout << "! " << ans << endl;
      cout.flush();
    }
    else {
      ll ans = sol6();
      debug(ans);
      cout << "? " << ans << ' ' << tg[6];
      ct = 0;
      REP (i,SZ(tg)) {
        if (i == 6 || tg[i] == ans) continue;
        if(ct == 3) break;
        cout << ' ' << tg[i];
        ct++;
      }
      cout << endl;
      cout.flush();
      ll x,y;
      cin >> x >> y;
      if(y == ans) ans = tg[6];
      cout << "! " << ans << endl;
      cout.flush();
    }
  }
}
