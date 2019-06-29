#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
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

const ll MAXn=4e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

struct event{
  int l,r;
  bool cmd;
  int u,v;
  event(int _l,int _r,bool _cmd,int _u,int _v):l(_l),r(_r),cmd(_cmd),u(_u),v(_v){};
};
int n,m,q;
vector<event> E;
int dsu[MAXn],sz[MAXn];
vector<event> tr[MAXn];
map<ii,vector<ll>> mp;
void init(){
  E.clear();
  REP (i,n) dsu[i] = i, sz[i] = 1;
  REP (i,MAXn) tr[i].clear();
}
void ins_event(int id,int L,int R,int ql,int qr,event e){
  if (L >= ql && R <= qr) {
    tr[id].eb(e);
    return;
  }
  int mid = (L+R)>>1;
  if (qr <= mid) ins_event(id*2+1,L,mid,ql,qr,e);
  else if (ql > mid) ins_event(id*2+2,mid+1,R,ql,qr,e);
  else {
    ins_event(id*2+1,L,mid,ql,qr,e);
    ins_event(id*2+2,mid+1,R,ql,qr,e);
  }
}
int main(){
  IOS();
  int t;
  cin >> t;
  while (t--) {
    init();
    cin >> n >> m >> q;
    REP (i,m) {
      int u,v;
      cin >> u >> v;
      if (u > v) swap(u,v);
      mp[{u,v}] = {0,0};
    }

    REP1 (i,q) {
      char c;
      int u,v;
      cin >> c >> u >> v;
      if (u > v) swap(u,v);
      if (c == 'N') mp[{u,v}] = i;
      else mp[{u,v}] = i;
    }
    vector<ll> v;
    ii tmp = {-1,-1};
    for (auto i:mp) {
      ii p = i.X, t = i.Y;
      if (tmp.X == -1)
    }
  }
}
