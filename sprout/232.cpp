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

ll d[MAXn];
ll id[10005];
ll u[500][500];
ll w[500][10005];
ll adj[MAXn];
ll big[500];
ll small[10005];
vector<vector<ll>> b,s,t;
int main(){
  ll n,m,q;
  const ll k=450;
  cin>>n>>m>>q;
  ll idx1=0,idx2=0;
  REP(i,n) cin>>d[i];
  REP(i,m){
    ll x;
    cin>>x;
    vector<ll> tmp;
    ll sum=0;
    REP(j,x){
      ll v;
      cin>>v;
      v--;
      tmp.pb(v);
      sum+=d[v];
    }
    sort(ALL(tmp));
    t.pb(tmp);
    if(x>k){
      b.pb(tmp);
      id[i]=idx1++;
      big[id[i]]=sum;
    }
    else{
      s.pb(tmp);
      id[i]=idx2++;
    }
  }
  debug(SZ(b));
  REP(i,SZ(b)){
    for(int j=i+1;j<SZ(b);j++){
      vector<ll> x=b[i],y=b[j];
      ll l=0,r=0;
      ll cnt=0;
      while(l<SZ(x) && r<SZ(y)){
        while(x[l]>y[r] && r<SZ(y)) r++;
        if(x[l]==y[r] && l<SZ(x) && r<SZ(y)) l++,r++,cnt++;
        else l++;
      }
      u[i][j]=u[j][i]=cnt;
      debug(i,j,u[i][j],cnt);
    }
  }
  ll tp=0;
  tp++;
  REP(i,SZ(b)){
    for(auto it:b[i]) adj[it]=tp;
    ll cnt;
    REP(j,SZ(s)){
      cnt=0;
      vector<ll> y=s[j];
      for(auto g:y)if(adj[g]==tp) cnt++;
      w[i][j]=cnt;
    }
    tp++;
  }
  pary(id,id+m);
  debug(u[3][4]);
  //debug(id[2],w[0][0]);
  while(q--){
    string str;
    cin>>str;
    if(str[0]=='A'){
      ll x,y;
      cin>>x>>y;
      x--;
      if(SZ(t[x])>k){
        ll cur=id[x];
        big[cur]+=SZ(t[x])*y;
        debug(big[cur]);
        REP(i,m){
          if(i==x) continue;
          if(SZ(t[i])>k) big[id[i]]+=u[cur][id[i]]*y;
          else small[id[i]]+=w[cur][id[i]]*y;
          debug(small[id[i]],big[id[i]],u[cur][id[i]],w[cur][id[i]],cur,id[i],i);
          //debug(small[id[i]],id[i],cur,w[cur][id[i]],i,y,w[cur][id[i]]*y);
        }
      }
      else{
        ll cur=id[x];
        REP(i,SZ(t[x])) d[t[x][i]]+=y;
        REP(i,idx1) big[i]+=w[i][cur]*y;
        pary(d,d+n);
      }
    }
    else{
      ll x;
      cin>>x;
      x--;
      ll cur=id[x];
      if(SZ(t[x])>k) cout<<big[cur]<<endl;
      else{
        ll sum=0;
        debug(cur,s[cur]);
        REP(i,SZ(s[cur])) sum+=d[s[cur][i]];
        debug(small[cur]);
        sum+=small[cur];
        cout<<sum<<endl;
      }
    }
  }
}
