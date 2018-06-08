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

ll x[MAXn];
ll len[MAXn];
vector<ll> v;
vector<ii> rk[MAXn];
ll search(ll u){
  ll l = 0,r = SZ(v);
  while(l!=r-1){
    ll mid = (l + r) / 2;
    if(v[mid]<u) r = mid;
    else l = mid;
  }
  return l+1;
}
int main(){
  IOS();
  ll n;
  cin>>n;
  REP(i,n) cin>>x[n-i-1];
  if(n==1) return cout<<"1\n1\n1\n",0;
  len[n-1] = 1;
  ll mx = 1;
  v.pb(x[0]);
  if(x[1]<=x[0]){
    v.pb(x[1]);
    len[n-2]=2;
    debug("hi");
    mx=2;
  }
  else{
    v[0]=max(x[0],x[1]);
    len[n-2]=1;
  }
  for(int i=2;i<n;i++){
    ll cur = x[i];
    ll idx = search(cur);
    debug(v,idx,cur);
    if(idx==SZ(v)){
      if(cur<=v.back()){
        v.pb(cur);
        len[n-i-1]=idx+1;
      }
      else{
        //chkmax(v[idx],cur);
        v[idx]=max(v[idx],cur);
        len[n-i-1]=idx;
      }
    }
    else if(idx==1){
      if(cur>v[0]){
        v[0]=cur;
        len[n-i-1]=1;
      }
      else{
        //chkmax(v[idx],cur);
        v[idx]=max(v[idx],cur);
        len[n-i-1]=idx+1;
      }
    }
    else{
      //chkmax(v[idx],cur);
      v[idx]=max(v[idx],cur);
      len[n-i-1]=idx+1;
    }
    //chkmax(mx,len[n-i-1]);
    mx=max(mx,len[n-i-1]);
  }
  pary(len,len+n);
  //pary(x,x+n);
  REP1(i,mx) rk[i].pb({0,0});
  for(int i=(int)n-1;i>=0;i--){
    if(len[i]==1){
      rk[len[i]].pb({len[i],n-i-1});
      if(SZ(rk[len[i]])>1) rk[len[i]].back().F+=rk[len[i]][SZ(rk[len[i]])-2].F;
      //while(rk[len[i]].back().F>=MOD) rk[len[i]].back().F-=MOD;
      rk[len[i]].back().F%=MOD;
      //debug(rk[len[i]]);
      continue;
    }
    ll l = 0,r = SZ(rk[len[i]-1]);
    while(l!=r-1){
      ll mid = (l + r) / 2;
      //debug(x[rk[len[i]-1][mid].S],rk[len[i]-1][mid].S,x[n-i-1]);
      if(x[rk[len[i]-1][mid].S]>=x[n-i-1]) r = mid;
      else l = mid;
    }
    //debug(rk[len[i]-1][l].F,n-i-1);
    ll tmp=rk[len[i]-1].back().F-rk[len[i]-1][l].F;
    while(tmp<0) tmp+=MOD;
    //rk[len[i]].pb({rk[len[i]-1][l].F,n-i-1});
    rk[len[i]].pb({tmp,n-i-1});
    if(SZ(rk[len[i]])>1) rk[len[i]].back().F+=rk[len[i]][SZ(rk[len[i]])-2].F;
    rk[len[i]].back().F%=MOD;
    //while(rk[len[i]].back().F>=MOD) rk[len[i]].back().F-=MOD;
    //debug(rk[len[i]],len[i],tmp);
    //debug(rk[len[i]][SZ(rk[len[i]])-2].F);
  }
  debug(mx);
  //debug(v);
  //REP1(i,SZ(v)) debug(rk[i]);
  cout<<mx<<endl;
  cout<<rk[mx].back().F<<endl;
  ll tmp=mx;
  REP(i,n){
    if(tmp==0) break;
    if(len[i]==tmp){
      if(tmp!=1) cout<<i+1<<' ';
      else return cout<<i+1<<endl,0;
      //debug(i+1);
      tmp--;
    }
  }
}
