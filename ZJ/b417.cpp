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
#define eb emplace_back
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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;
const int k=330;

int n,m,tmp;
int d[MAXn],cnt[MAXn],t[MAXn];
ii ans[1000005];
struct query{
  int l,r,id;
  bool operator < (const query &q)const{
    return (l/k)<(q.l/k) || ((l/k)==(q.l/k) && r<q.r);
  }
} q[1000005];
void add(int x){
  t[cnt[x]]--;
  cnt[x]++;
  t[cnt[x]]++;
  if( t[cnt[x]]==1 ) chkmax(tmp,cnt[x]);
}
void sub(int x){
  t[cnt[x]]--;
  cnt[x]--;
  t[cnt[x]]++;
  if( t[cnt[x]+1]==0 && tmp==cnt[x]+1 ) tmp = cnt[x];
}
int main(){
  IOS();
  cin>>n>>m;
  REP1(i,n) cin>>d[i];
  REP(i,m){
    cin>>q[i].l>>q[i].r;
    q[i].id = i;
  }
  sort(q,q+m);
  int l=0,r=-1;
  REP(i,m){
    debug("QAQ");
    while( r<q[i].r ) add(d[++r]);
    while( r>q[i].r ) sub(d[r--]);
    while( l<q[i].l ) sub(d[l++]);
    while( l>q[i].l ) add(d[--l]);
    debug("alive");
    ans[q[i].id].X = tmp,ans[q[i].id].Y = t[tmp];
  }
  REP(i,m) cout<<ans[i].X<<' '<<ans[i].Y<<endl;
}
