#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define RI(X) cin>>X
#define RII(X,Y) cin>>X>>Y
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define pob pop_back
#define mp make_pair
#define VI vector<int>
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

const ll MaxN=1e2+5;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll dp[MaxN][MaxN][30];
vector<ii> g[MaxN];

ll sol(ll i,ll j,ll x){
	if(dp[i][j][x]!=-1) return dp[i][j][x];
	for(auto u:g[i]){
		if(u.S>=x&&sol(j,u.F,u.S)==0) return dp[i][j][x]=1;
	}
	return dp[i][j][x]=0;
}

int main(){
	IOS();
	ll n,m;
	RII(n,m);
	REP(i,m){
		ll a,b;
		char c;
		RII(a,b);
		cin>>c;
		a--,b--;
		g[a].pb(mp(b,c-'a'));
		dp[a][b][0]=1;
	}
	RST(dp,-1);
	REP(i,n)REP(j,n) dp[i][j][0]=sol(i,j,0);
	REP(i,n){
		REP(j,n){
			if(dp[i][j][0]==1) cout<<'A';
			else cout<<'B';
		}
		cout<<endl;
	}
}

