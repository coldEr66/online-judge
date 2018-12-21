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

map<int,ii> mp;
map<ii,int> m;
vector<ii> v;
bool chk(vector<ii> &tmp){
  REP(i,SZ(tmp)){
    int x = m[tmp[i]];
    if( x<1 || x>10 ) return false;
  }
  return true;
}
int main(){
  IOS();
  int n;
  string s;
  cin>>n>>s;
  if( n==1 ) return cout<<"NO"<<endl,0;
  REP(i,n)if( s[i]=='0' ) s[i] = '0'+10;
  REP(i,9) mp[i+1] = mkp(i/3,i%3),m[mkp(i/3,i%3)] = i+1;
  mp[10] = mkp(3,1);
  m[mkp(3,1)] = 10;
  REP(i,n-1) v.eb(mkp(mp[s[i]-'0'].X-mp[s[i+1]-'0'].X,mp[s[i]-'0'].Y-mp[s[i+1]-'0'].Y));
  REP1(i,10){
    if( i==s[0]-'0' ) continue;
    vector<ii> tmp;
    int now = i;
    tmp.eb(mp[now]);
    REP(j,n-1){
      ii tp = mkp(mp[now].X-v[j].X,mp[now].Y-v[j].Y);
      tmp.eb(tp);
      now = m[tp];
    }
    if( chk(tmp) ) return cout<<"NO"<<endl,0;
  }
  cout<<"YES"<<endl;
}
