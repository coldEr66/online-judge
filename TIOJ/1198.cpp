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

map<ll,ll> mp;
ll d[MAXn];
ll dx[] = {1,0,-1,0};
ll dy[] = {0,1,0,-1};
ll encode(vector<ll> v){
  ll ret = 0;
  REP (i,9) ret |= (v[i]<<(4*i));
  return ret;
}
vector<ll> decode(ll x){
  vector<ll> ret;
  ll tmp = 15;
  REP (i,9) {
    if (i) tmp = tmp<<4;
    // debug((tmp&x)>>(4*i));
    ret.eb(((tmp&x)>>(4*i)));
  }
  return ret;
}
inline bool chk(ll x,ll y){
  return x<0 || x>=3 || y<0 || y>=3;
}
int main(){
  IOS();
  ll st = 0;
  REP (i,9) {
    cin >> d[i];
    st |= (d[i]<<(4*i));
  }
  debug(st);
  mp[st] = 0;
  ll tg = 0;
  REP (i,9) {
    ll x;
    cin >> x;
    tg |= (x<<(4*i));
  }
  queue<ll> q;
  q.push(st);
  while (SZ(q)) {
    if (mp.count(tg)) break;
    ll cur = q.front();
    q.pop();
    vector<ll> tmp = decode(cur);
    ll id = -1;
    REP (i,9) if (tmp[i] == 0) id = i;
    assert(id!=-1);
    ll x = id/3, y = id%3;
    REP (i,4) {
      ll tx = x+dx[i], ty = y+dy[i];
      if (chk(tx,ty)) continue;
      ll nxt = tx*3+ty;
      // debug(nxt);
      swap(tmp[id],tmp[nxt]);
      // debug(tmp);
      ll go = encode(tmp);
      // debug(mp.count(go));
      if (!mp.count(go)) {
        mp[go] = mp[cur]+1;
        q.push(go);
      }
      swap(tmp[id],tmp[nxt]);
    }
  }
  cout << mp[tg] << endl;
}
