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

const ll MaxN=505;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll dp[2][MaxN][MaxN];
ll d[MaxN];

int main(){
	IOS();
	ll n,m,b,mod;
	cin>>n>>m>>b>>mod;
	REP(i,n) cin>>d[i];
	RST(dp,0);
	dp[0][0][0]=1;
	ll nxt=0;
	REP(i,n){
		nxt=!nxt;
		REP(j,m+1)REP(k,b+1){
			dp[nxt][j][k]=dp[!nxt][j][k]%mod;
			if(j>0&&k-d[i]>=0) dp[nxt][j][k]+=dp[nxt][j-1][k-d[i]],dp[nxt][j][k]%=mod;
		}
	}
	ll ans=0;
	REP(i,b+1){
		ans+=dp[nxt][m][i];
		ans%=mod;
	}
	cout<<ans<<endl;
}

