#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define X first
#define Y second
#define mkp make_pair
#define pb push_back
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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int dt[30],d[30];
ii al[30];
vector<char> ans;
vector<int> v;
int main(){
  IOS();
  string s,t;
  cin>>s>>t;
  int ct=0;
  al[26]=mkp(INF,INF);
  REP(i,SZ(t)) dt[t[i]-'a']++;
  REP(i,SZ(s)){
    if( s[i]=='?' ) ct++;
    else d[s[i]-'a']++;
  }
  REP(i,26){
    if( !dt[i] ) continue;
    al[i]=mkp(d[i]/dt[i],d[i]%dt[i]);
    v.pb(i);
    debug(al[i]);
  }
  // pary(d,d+26);
  // pary(dt,dt+26);
  debug(v);
  while( ct ){
    int tp=26;
    for( int i:v )if( al[i].X<al[tp].X ) tp=i;
    REP(i,min(dt[tp]-al[tp].Y,ct)) ans.pb(char(tp+'a'));
    ct-=min(dt[tp]-al[tp].Y,ct);
    al[tp] = mkp(al[tp].X+1,0);
  }
  REP(i,SZ(s)){
    if( s[i]=='?' ){
      cout<<ans.back();
      ans.pob();
    }
    else cout<<s[i];
  }
  cout<<endl;
}
