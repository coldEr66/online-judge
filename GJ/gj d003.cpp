#include<iostream>                          
#include<iomanip>                          
#include<cstdio>                          
#include<cstring>                          
#include<string>                          
#include<set>                          
#include<map>                          
#include<vector>                          
#include<algorithm>                          
#include<sstream>                         
#include <queue>                     
#include<cmath>            
#include <ctype.h>           
#include <numeric>    
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

const ll MaxN=25;
const ll MOD=1000000007;
const ll INF=ll(1e18);

string s,t;
ll dp[MaxN][MaxN];
ll st[MaxN][MaxN];
void init(){
	cin>>s>>t;
	s=' '+s;
	t=' '+t;
	RST(dp,0);
	RST(st,0);
	REP(i,SZ(s)+1) dp[i][0]=0;
	REP(i,SZ(t)+1) dp[0][i]=0;
}

void build(){
	REP1(i,SZ(s)-1){
		REP1(j,SZ(t)-1){
			if(s[i]==t[j]){
				dp[i][j]=dp[i-1][j-1]+1;
				st[i][j]=0;
			}
			else{
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
				st[i][j]= dp[i][j-1]>dp[i-1][j] ?1:2;
			}
			//debug(dp[i][j],i,j,s[4],t[6]);
		}
	}
}

void LCS(ll x,ll y){
	if(x==0||y==0) return;
	if(st[x][y]==0){
		LCS(x-1,y-1);
		cout<<s[x];
	}
	else{
		st[x][y]==1 ?LCS(x,y-1):LCS(x-1,y);
	}
}

void sol(){
	REP(i,SZ(s))if(s[i]!=' ') cout<<s[i];
	cout<<' ';
	REP(i,SZ(t))if(t[i]!=' ') cout<<t[i];
	cout<<" = ";
	//debug(dp[SZ(s)][SZ(t)]);
	if(dp[SZ(s)-1][SZ(t)-1]==0) cout<<0<<endl;
	else{
		LCS(SZ(s)-1,SZ(t)-1);
		cout<<endl;
	}
}

int main(){
	IOS();
	REP(i,3){
		init();
		build();
		sol();
	}
	return 0;
}

