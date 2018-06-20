#include <bits/stdc++.h>
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
#define F first
#define S second
#define pb push_back
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
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // cold66
//}

template<class T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

const ll MAXn=2e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=(ll)1e9;

int n,m;
int d[MAXn][MAXn];
int dis[MAXn][MAXn];
bool vis[MAXn][MAXn];
MinHeap<pair<int,ii>> pq;
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
bool chk(int a,int b){
  return a<0 || a>=n || b<0 || b>=m;
}
int main(){
  IOS();
  cin>>n>>m;
  REP(i,n)REP(j,m){
    char c;
    cin>>c;
    if(c=='#') d[i][j] = 0;
    else d[i][j] = 1;
  }
  int s1,s2,e1,e2;
  cin>>s1>>s2>>e1>>e2;
  s1--,s2--,e1--,e2--;
  //debug(st,dst);
  REP(i,n)REP(j,m) dis[i][j] = INF;
  dis[s1][s2] = d[s1][s2];
  pq.push({dis[s1][s2],{s1,s2}});
  REP(i,n*m){
    ii tp = {-1,-1};
    while(SZ(pq) && vis[tp.F = pq.top().S.F][tp.S = pq.top().S.S]) pq.pop();
    if(tp==(ii){-1,-1}) break;
    vis[tp.F][tp.S] = true;
    REP(k,4){
      int x = tp.F + dx[k],y = tp.S + dy[k];
      if(chk(x,y)) continue;
      if(!vis[x][y] && dis[x][y] > dis[tp.F][tp.S] + d[x][y]){
        dis[x][y] = dis[tp.F][tp.S] + d[x][y];
        pq.push({dis[x][y],{x,y}});
      }
    }
  }
  cout<<dis[e1][e2]<<endl;
}
