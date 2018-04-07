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
#define F first
#define S second
#define pb push_back
#define pob pop_back
#define MP make_pair
#define VI vector<int>
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

const ll MAXn=1e5+5;
const ll MOD=1000000007;
const ll INF=(ll)1e18;

ll x[9][9],y[9][9],z[9][9];
ll a[9][9],b[9][9],c[9][9];
ll su[9][9];
bool ok;

ll id(ll x,ll y){
  return x/3+(y/3)*3;
}

bool chk(char tmp[9][9]){
  RST(a,0);
  RST(b,0);
  RST(c,0);
  REP(i,9){
    REP(j,9){
      if(tmp[i][j]=='.') return false;
      if(a[i][tmp[i][j]-'0'-1]==1 || b[j][tmp[i][j]-'0'-1]==1 || c[id(i,j)][tmp[i][j]-'0'-1]==1) return false;
      a[i][tmp[i][j]-'0'-1]=b[j][tmp[i][j]-'0'-1]=c[id(i,j)][tmp[i][j]-'0'-1]=1;
    }
  }
  return true;
}
bool sol(ll k){
  if(k==81){
    return true;
  }
  ll u=k/9,v=k%9;
  if(su[u][v]) return sol(k+1);
  REP(i,9){
    if(!x[u][i] && !y[v][i] && !z[id(u,v)][i]){
      su[u][v]=i+1;
      x[u][i]=1,y[v][i]=1,z[id(u,v)][i]=1;
      if(sol(k+1)) return true;
      su[u][v]=0;
      x[u][i]=0,y[v][i]=0,z[id(u,v)][i]=0;
    }
  }
  return false;
}

int main(){
  IOS();
  string s;
  while(cin>>s){
    ok=false;
    if(s=="end") break;
    RST(su,0);
    RST(x,0);
    RST(y,0);
    RST(z,0);
    debug(SZ(s));
    bool rr=false;
    if(SZ(s)!=81){
      cout<<"No solution."<<endl;
      continue;
    }
    debug(1);
    REP(i,SZ(s))if(s[i]!='.' && (s[i]<'1' || s[i]>'9')){
      cout<<"No solution."<<endl;
      rr=true;
      break;
    }
    if(rr) continue;
    ll idx=0;
    bool fg=false;
    REP(i,9){
      REP(j,9){
        if(s[idx]=='.'){
          su[i][j]=0;
          idx++;
          continue;
        }
        if(x[i][s[idx]-'0'-1]==1 || y[j][s[idx]-'0'-1]==1 || z[id(i,j)][s[idx]-'0'-1]==1){
          fg=true;
          break;
        }
        x[i][s[idx]-'0'-1]=y[j][s[idx]-'0'-1]=z[id(i,j)][s[idx]-'0'-1]=1;
        su[i][j]=s[idx]-'0';
        idx++;
      }
      if(fg) break;
    }
    if(fg){
      cout<<"No solution."<<endl;
      continue;
    }
    REP(i,9) pary(su[i],su[i]+9);
    if(sol(0)){
      REP(i,9)REP(j,9) cout<<su[i][j];
      cout<<endl;
    }
    else cout<<"No solution."<<endl;
  }
}
