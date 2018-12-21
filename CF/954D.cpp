#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,j,n,m) for(int i=j;i<n;i+=m)
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
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.F<<","<<_p.S<<")";}
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

ll n,m,s,t;
bool adj[MAXn][MAXn];
void BFS(ll *d,ll st){
  queue<ll> q;
  q.push(st);
  d[st] = 0;
  while(SZ(q)){
    ll cur = q.front();
    q.pop();
    REP(i,n)if(adj[cur][i]){
      if(d[i]>d[cur]+1){
        d[i] = d[cur] + 1;
        q.push(i);
      }
    }
  }
}
ll d1[MAXn],d2[MAXn];
int main(){
  IOS();
  cin>>n>>m>>s>>t;
  s--,t--;
  REP(i,m){
    ll a,b;
    cin>>a>>b;
    a--,b--;
    adj[a][b] = adj[b][a] = 1;
  }
  RST(d1,INF);
  RST(d2,INF);
  BFS(d1,s);
  BFS(d2,t);
  pary(d1,d1+n);
  pary(d2,d2+n);
  ll ans = d1[t];
  ll cnt = 0;
  REP(i,n)for(int j=i+1;j<n;j++){
    if(i==j) continue;
    if(adj[i][j]) continue;
    if(d1[i]+d2[j]+1<ans || d1[j]+d2[i]+1<ans) adj[i][j] = adj[j][i] = 1;
    else cnt++;
    debug(i,j,cnt);
  }
  cout<<cnt<<endl;
}
