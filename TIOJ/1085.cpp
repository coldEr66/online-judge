#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
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

const ll MAXn=55,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int x,y,z;
int d[MAXn][MAXn][MAXn];
int t[MAXn][MAXn][MAXn];
int dis[MAXn][MAXn][MAXn];
int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};
bool chk(int a,int b,int c){
  if(a>0 && a<=x && b>0 && b<=y && c>0 && c<=z) return false;
  return true;
}
void dfs(ll a,ll b,ll c){
  if(a==1 && b==1 && c==1){
    cout<<'('<<1<<','<<1<<','<<1<<")";
    return;
  }
  ll i = t[a][b][c];
  dfs(a-dx[i],b-dy[i],c-dz[i]);
  cout<<"->("<<a<<','<<b<<','<<c<<')';
}
int main(){
  IOS();
  cin>>x>>y>>z;
  REP1(k,z)REP1(j,y)REP1(i,x){
    cin>>d[i][j][k];
    dis[i][j][k] = INF;
  }
  queue<int> q;
  if(d[1][1][1]==0) REP(i,3) q.push(1);
  dis[1][1][1] = 0;
  while(SZ(q)){
    int tx = q.front();q.pop();
    int ty = q.front();q.pop();
    int tz = q.front();q.pop();
    REP(i,6){
      int nx = tx+dx[i];
      int ny = ty+dy[i];
      int nz = tz+dz[i];
      if(chk(nx,ny,nz)) continue;
      if(dis[nx][ny][nz]!=INF) continue;
      if(d[nx][ny][nz]) continue;
      dis[nx][ny][nz] = dis[tx][ty][tz]+1;
      t[nx][ny][nz] = i;
      q.push(nx);
      q.push(ny);
      q.push(nz);
    }
  }
  if(dis[x][y][z]==INF) cout<<"no route";
  else dfs(x,y,z);
  cout<<'\n';
}
