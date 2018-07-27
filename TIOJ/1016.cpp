#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

int main(){
  IOS();
  string s;
  while(cin>>s){
    int n = SZ(s);
    int a = 0,b = 0;
    int out = 0;
    int now = 0;
    bool fg = false;
    REP(i,n){
      if(out==3){
        fg = !fg;
        out=0,now=0;
      }
      char tp = s[i];
      if(tp=='K' || tp=='O') out++;
      else if(tp=='H' || tp=='T'){
        debug(now,a);
        for(int j=0;j<3;j++)if(now&(1<<j)) (fg==true ?b++:a++);
        now=0;
        debug(a);
        if(tp=='H') fg==true ?b++:a++;
        else now=4;
      }
      else if(tp=='S'){
        for(int j=2;j>=0;j--){
          if(j==2 && now&(1<<j)){
            now-=(1<<j);
            fg==true ?b++:a++;
          }
          else if(now&(1<<j)){
            now-=(1<<j);
            now|=(1<<(j+1));
          }
        }
        now|=1;
        debug(now,a);
      }
      else if(tp=='D'){
        for(int j=2;j>=0;j--){
          if(j>=1 && now&(1<<j)){
            now-=(1<<j);
            fg==true ?b++:a++;
          }
          else if(now&(1<<j)){
            now-=(1<<j);
            now|=(1<<(j+2));
          }
        }
        now|=2;
      }
      else if(tp=='W'){
        if(now==7) fg==true ?b++:a++;
        else if(now%2==0) now+=1;
        else if(now==1) now = 3;
        else now = 7;
        debug(a);
      }
    }
    cout<<a<<' '<<b<<endl;
  }
}
