#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

const ll MAXn=1e4+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int n,m,k;
vector<ii> lit;
map<ii,int> cnt;
vector<int> row[MAXn],col[MAXn];
MinHeap<ii> pq;
int dis[MAXn];
bitset<MAXn> cr,cc;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
void filrow(int r,int v){
  if( r>=1 && r<=n && !cr[r] ){
    cr[r] = true;
    for( auto it:row[r] )if( dis[it]>v ){
      dis[it] = v;
      pq.push(mkp(v,it));
    }
  }
}
void filcol(int c,int v){
  if( c>=1 && c<=m && !cc[c] ){
    cc[c] = true;
    for( auto it:col[c] )if( dis[it]>v ){
      dis[it] = v;
      pq.push(mkp(v,it));
    }
  }
}
int main(){
  IOS();
  cin>>n>>m>>k;
  RST(dis,INF);
  REP(i,k){
    int r,c;
    cin>>r>>c;
    lit.eb(mkp(r,c));
    row[r].eb(i);
    col[c].eb(i);
    cnt[mkp(r,c)] = i;
  }
  if( cnt.count(mkp(n,m)) ) pq.push(mkp(0,cnt[mkp(n,m)]));
  else{
    filrow(n-1,1);
    filrow(n,1);
    filcol(m-1,1);
    filcol(m,1);
  }
  while( SZ(pq) ){
    ii cur = pq.top();
    pq.pop();
    if( cur.X>dis[cur.Y] ) continue;
    REP(i,4){
      int tx = lit[cur.Y].X+dx[i];
      int ty = lit[cur.Y].Y+dy[i];
      if( cnt.count(mkp(tx,ty)) ){
        int id = cnt[mkp(tx,ty)];
        if( dis[id]>cur.X ){
          dis[id] = cur.X;
          pq.push(mkp(cur.X,id));
        }
      }
    }
    for(int i=lit[cur.Y].X-2;i<=lit[cur.Y].X+2;i++) filrow(i,cur.X+1);
    for(int i=lit[cur.Y].Y-2;i<=lit[cur.Y].Y+2;i++) filcol(i,cur.X+1);
  }
  if( dis[0]==INF ) cout<<-1<<endl;
  else cout<<dis[0]<<endl;
}
