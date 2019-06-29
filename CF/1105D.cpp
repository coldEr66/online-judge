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

typedef pair<ll,ii> iii;
ll n,m,p;
ll s[11];
ll d[MAXn][MAXn];
vector<ii> e[11];
ll ans[11];
ll dx[] = {1,0,0,-1};
ll dy[] = {0,1,-1,0};
bool chk(ll x,ll y){
  return x<0 || x>=n || y<0 || y>=m;
}
int main(){
  IOS();
  cin >> n >> m >> p;
  REP1 (i,p) cin >> s[i];
  REP (i,n) REP (j,m) {
    char c;
    cin >> c;
    if (c == '#') d[i][j] = -1;
    else if (c == '.') d[i][j] = 0;
    else {
      d[i][j] = c - '0';
      e[c-'0'].eb(i,j);
    }
  }

  while (1 == 1) {
    bool fg = false;
    REP1 (i,p) if (SZ(e[i])) fg = true;
    if (!fg) break;
    priority_queue<iii, vector<iii>, greater<iii> > pq;
    REP1 (i,p) {
      for (auto it:e[i]) pq.emplace(0,it);
      vector<ii> tmp;
      while (SZ(pq)) {
        ll dis = pq.top().X;
        ll x = pq.top().Y.X;
        ll y = pq.top().Y.Y;
        pq.pop();
        if (dis == s[i]) continue;
        REP (j,4) {
          ll tx = x + dx[j], ty = y + dy[j];
          if (chk(tx,ty)) continue;
          if (d[tx][ty] == 0) {
            d[tx][ty] = i;
            pq.push({dis+1,{tx,ty}});
            tmp.eb(tx,ty);
          }
        }
      }
      e[i] = tmp;
    }
  }

  REP (i,n) REP (j,m) if (d[i][j] > 0) ans[d[i][j]]++;
  REP1 (i,p) cout << ans[i] << " \n"[i==p];
}
