#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
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

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;
const ll MAXsq=(ll)sqrt(MAXn)+5;
const ll k = 10*MAXsq;

int n,m;
int pre[MAXsq][MAXn];
int pos[MAXn];
int b[MAXn];
int block[MAXn],tp[MAXsq];
int lowbit(int x){return x&(-x);}
void ins(int x,int val,int bit[]){
  for (;x<=n;x+=lowbit(x)) bit[x] += val;
}
int qr(int x,int bit[]){
  int ret = 0;
  for (;x>0;x-=lowbit(x)) ret += bit[x];
  return ret;
}
int cal(int la,int ra,int i){
  if (i == 0) return 0;
  int ret = qr(ra,pre[block[i]-1]) - qr(la-1,pre[block[i]-1]);
  debug(ret);
  for (int j=tp[block[i]];j<=i;j++) {
    if (la <= b[j] && b[j] <= ra) ret++;
  }
  return ret;
}
void del(int x,int v){
  for (int i=block[x];i<=block[n];i++) {
    ins(v,-1,pre[i]);
  }
}
void add(int x,int v){
  for (int i=block[x];i<=block[n];i++) {
    ins(v,1,pre[i]);
  }
}
int main(){
  IOS();
  cin >> n >> m;
  REP1 (i,n) {
    int a;
    cin >> a;
    pos[a] = i;
  }
  REP1 (i,n) {
    cin >> b[i];
    b[i] = pos[b[i]];
  }
  REP1 (i,n) {
    block[i] = (i-1) / k + 1;
    if (block[i] != block[i-1]) tp[block[i]] = i;
  }
  pary(b+1,b+n+1);
  REP1 (i,n) add(i,b[i]);

  while (m--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int la,ra,lb,rb;
      cin >> la >> ra >> lb >> rb;
      int r = cal(la,ra,rb);
      int l = cal(la,ra,lb-1);
      cout << r-l << endl;
    }
    else {
      int x,y;
      cin >> x >> y;
      del(x,b[x]);
      del(y,b[y]);
      add(x,b[y]);
      add(y,b[x]);
      swap(b[x],b[y]);
    }
  }
}
