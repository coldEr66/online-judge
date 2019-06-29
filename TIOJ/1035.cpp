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

const ll MAXn=1<<17,MAXlg=__lg(MAXn);
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;
const complex<lf> I(0,1);
const lf pi = acos(-1);

int rev_bit(int x){
  int ret = 0;
  REP (i,MAXlg) {
    if (x&(1<<i)) ret |= (1<<(MAXlg-i-1));
  }
  return ret;
}
void fft(complex<lf> *poly,bool inv = false){
  REP (i,MAXn) {
    int tmp = rev_bit(i);
    if (i < tmp) swap(poly[i],poly[tmp]);
  }

  for (int len=1;len*2<=MAXn;len<<=1) {
    for (int i=0;i<MAXn;i+=len*2) {
      complex<lf> w;
      if (inv) w = cos(pi/len) - I * sin(pi/len);
      else w = cos(pi/len) + I * sin(pi/len);
      complex<lf> step = 1;
      for (int j=i;j<i+len;j++) {
        complex<lf> u = poly[j], v = poly[j+len];
        poly[j] = u + step * v;
        poly[j+len] = u - step * v;
        step *= w;
      }
    }
  }
  if (inv) REP (i,MAXn) poly[i] /= MAXn;
}
complex<lf> a[MAXn],b[MAXn];
int cnt[MAXn];
int main(){
  IOS();
  string s,t;
  cin >> s >> t;
  int slen = SZ(s), tlen = SZ(t);
  for (char c='a';c<='j';c++) {
    REP (i,MAXn) a[i] = b[i] = 0;
    REP (i,slen) {
      if (s[i] == c) a[i] = 1;
      else a[i] = 0;
    }
    REP (i,tlen) {
      if (t[i] == c) b[tlen-i-1] = 1;
      else b[tlen-i-1] = 0;
    }

    fft(a);
    fft(b);
    REP (i,MAXn) a[i] *= b[i];
    fft(a,1);
    REP (i,MAXn) {
      lf tmp = a[i].real();
      int x = (int)floor(tmp)-1;
      while (abs(x-tmp) > abs(x-tmp+1)) x++;
      cnt[i] += x;
    }
  }

  int ans = 0;
  REP (i,MAXn) ans = max(ans,cnt[i]);
  cout << ans << endl;
}
