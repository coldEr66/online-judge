#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

const ll MAXn=1e5+50,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int c[MAXn],sa[MAXn];
int tmp[2][MAXn];
int main(){
  IOS();
  string s;
  getline(cin,s);
  int n=SZ(s);
  int A=100000;
  int* rank = tmp[0];
  int* nrank = tmp[1];
  RST(c,0);
  REP(i,n) c[rank[i]=s[i]]++;
  REP(i,A) c[i]+=c[i-1];
  for(int i=n-1;i>=0;i--) sa[--c[s[i]]] = i;
  for(int u=1;u<=n;u<<=1){
    REP(i,A) c[i]=0;
    REP(i,n) c[rank[i]]++;
    REP(i,A) c[i]+=c[i-1];
    int* sa2 = nrank;
    int r=0;
    for(int i=n-u;i<n;i++) sa2[r++] = i;
    REP(i,n)if( sa[i]>=u ) sa2[r++] = sa[i]-u;
    for(int i=n-1;i>=0;i--) sa[--c[rank[sa2[i]]]] = sa2[i];
    nrank[sa[0]] = r = 0;
    for(int i=1;i<n;i++){
      if( !(rank[sa[i-1]]==rank[sa[i]] &&
          sa[i-1]+u<n &&
          rank[sa[i-1]+u]==rank[sa[i]+u]) )
          r++;
      nrank[sa[i]] = r;
    }
    swap(rank,nrank);
    if( r==n-1 ) break;
    A = r+1;
  }
  REP(i,n) cout<<sa[i]<<endl;
}
