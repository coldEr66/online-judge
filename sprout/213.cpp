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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=(ll)1e18;
const ll MAXsq=1e3+5;

deque<ll> dq[MAXsq];
int main(){
  IOS();
  ll n,m;
  cin>>n>>m;
  ll k=(ll)sqrt(n),j=0;
  REP1(i,n){
    ll t;
    cin>>t;
    dq[j].pb(t);
    if(i%k==0) j++;
  }
  while(m--){
    string s;
    ll x;
    cin>>s>>x;
    x--;
    ll cur=x/k,tp=x%k;
    if(s[0]=='A'){
      ll y;
      cin>>y;
      dq[cur].insert(dq[cur].begin()+tp,y);
      while(SZ(dq[cur])>k){
        ll u=dq[cur].back();
        dq[cur].pob();
        dq[cur+1].push_front(u);
        cur++;
      }
    }
    else{
      debug(SZ(dq[cur]),cur,tp);
      if(s[0]=='Q') cout<<dq[cur].at(tp)<<endl;
      else{
        dq[cur].erase(dq[cur].begin()+tp);
        while(SZ(dq[cur])<k && SZ(dq[cur+1])>0){
          ll u=dq[cur+1].front();
          dq[cur+1].pop_front();
          dq[cur].pb(u);
          cur++;
        }
      }
    }
  }
}
