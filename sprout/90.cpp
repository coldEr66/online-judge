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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=(ll)1e18;

ll b[MAXn];
map<ll,ll> cnt,cnt1;
vector<ll> v,d,r;

int main(){
  IOS();
  ll t;
  cin>>t;
  while(t--){
    RST(b,0);
    cnt.clear();
    cnt1.clear();
    v.clear();
    d.clear();
    r.clear();
    ll n,m;
    cin>>n>>m;
    REP(i,n) cin>>b[i];
    REP(i,m){
      ll k;
      cin>>k;
      v.pb(k);
    }
    sort(ALL(v),greater<ll>());
    debug(v);
    ll idx=0;
    ll ans=0;
    REP(i,n){
      idx=0;
      while(v[idx]>b[i] || cnt[v[idx]]==0) idx++;
      while(v[idx]<=b[i] && cnt[v[idx]]>0){
        debug(v[idx],idx,b[i]);
        b[i]-=v[idx];
        cnt[v[idx]]--;
        if(cnt[v[idx]]==0) idx++;
        ans++;
        d.pb(v[idx]);
        debug(cnt[v[idx]]);
      }
      if(cnt[b[i]]!=0){
        cnt[b[i]]--;
        d.pb(b[i]);
        ans++;
        b[i]=0;
      }
    }
    if(ans==m){
      cout<<ans<<endl;
      continue;
    }
    debug(d);
    debug(ans);
    sort(ALL(d),greater<ll>());
    sort(ALL(v));
    debug(v);
    ll x=v[0];
    REP(i,SZ(v)){
      ll k=v[i];
      if(i!=0 && x==k) continue;
      cnt1[k]=cnt1[k]-cnt[k];
      x=k;
    }
    for(auto it:cnt){
      REP(i,it.S) r.pb(it.F);
    }
    sort(ALL(r));
    debug(r);
    idx=0;
    for(auto k:d){
      ll tmp=0,rt=0;
      while(tmp+r[idx]<=k && cnt[r[idx]]>0){
        tmp+=r[idx];
        cnt[r[idx]]--;
        rt++;
      }
      if(cnt[k-tmp]!=0){
        rt++;
        cnt[k-tmp]--;
      }
      if(rt!=0) ans+=(rt-1);
      idx++;
    }
    cout<<ans<<endl;
  }
}
