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

const ll MAXn=3e3+5;
const ll MOD=1000000007;
const ll INF=(ll)1e18;

ll cnt[MAXn][27],rccnt[MAXn];
queue<ii> q;
bool ok[MAXn];
vector<ii> ans;

ll id(int x){
  REP(i,26){
    if(cnt[x][i]) return i; 
  }
}

int main(){
  IOS();
  ll n,m;
  cin>>n>>m;
  REP(i,n){
    string d;
    cin>>d;
    REP(j,m){
      cnt[i][d[j]-'a']++;
      if(cnt[i][d[j]-'a']==1) rccnt[i]++;
      cnt[n+j][d[j]-'a']++;
      if(cnt[n+j][d[j]-'a']==1) rccnt[n+j]++;
    }
  }
  pary(rccnt,rccnt+10);
  REP(i,n)if(rccnt[i]==1){
    q.push(MP(i,id(i)));
    ok[i]=true;
  }
  REP(j,m)if(rccnt[n+j]==1){
    q.push(MP(n+j,id(n+j)));
    ok[n+j]=true;
  }
  debug(SZ(q));
  while(SZ(q)){
    ii cur=q.front();
    q.pop();
    if(cur.F<n){
      REP(i,m)if(!ok[n+i]){
        cnt[n+i][cur.S]--;
        if(cnt[n+i][cur.S]==0) rccnt[n+i]--;
        if(rccnt[n+i]==1){
          q.push(MP(n+i,id(n+i)));
          ok[n+i]=true;
        }
      }
    }
    else{
      REP(i,n)if(!ok[i]){
        cnt[i][cur.S]--;
        if(cnt[i][cur.S]==0) rccnt[i]--;
        if(rccnt[i]==1){
          q.push(MP(i,id(i)));
          ok[i]=true;
        }
      }
    }
    debug(1);
    ans.pb(cur);
  }
  reverse(ALL(ans));
  debug(SZ(ans));
  for(ii cur:ans){
    if(cur.F<n) cout<<"row "<<cur.F+1<<" "<<char(cur.S+'a')<<endl;
    else cout<<"column "<<cur.F-n+1<<" "<<char(cur.S+'a')<<endl;
  }
}
