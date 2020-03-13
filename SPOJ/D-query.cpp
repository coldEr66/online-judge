#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define X first
#define Y second
#define mkp make_pair
#define pb push_back
#define pob pop_back
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
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

const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int d[30005];
int bit[MAXn],l[MAXn],ans[MAXn];
pair<ii,int> dt[MAXn];
int lowbit(int x){return x&(-x);}
void ins(int i,int val){
  while( i<MAXn ){
    bit[i]+=val;
    i+=lowbit(i);
  }
}
int qr(int i){
  int ret=0;
  while( i ){
    ret+=bit[i];
    i-=lowbit(i);
  }
  return ret;
}
int main(){
  IOS();
  int n;
  cin>>n;
  REP1(i,n) cin>>d[i];
  int q;
  cin>>q;
  REP1(i,q){
    cin>>dt[i].X.Y>>dt[i].X.X;
    dt[i].Y=i;
  }
  sort(dt+1,dt+q+1);
  REP1(i,q) debug(dt[i]);
  int idx=1;
  for(int i=1;i<=n && idx<=q;i++){
    if( l[d[i]] ) ins(l[d[i]],-1);
    l[d[i]] = i;
    ins(l[d[i]],1);
    debug(l[d[i]],i);
    while( idx<=q && dt[idx].X.X<=i ) ans[dt[idx].Y]=qr(dt[idx].X.X)-qr(dt[idx].X.Y-1),idx++;
    pary(bit+1,bit+1+n);
  }
  REP1(i,q) cout<<ans[i]<<endl;
}