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

const ll MaxN=1e6+5;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll dp[MaxN];
ll d[10][MaxN];

ll g(ll x){
	//debug(x);
	if(dp[x]!=-1) return dp[x];
	ll k=x;
	ll ret=1;
	while(x!=0){
		if(x%10==0){
			x/=10;
			continue;
		}
		ret*=(x%10);
		x/=10;
	}
	//debug(ret,k);
	if(dp[ret]!=-1) return dp[x]=dp[ret];
	else return dp[x]=dp[ret]=g(ret);
}

int main(){
	IOS();
	ll n;
	cin>>n;
	RST(dp,-1);
	ll tmp=0;
	REP(i,10) dp[i]=i;
	REP1(i,1000000){
		dp[i]=g(i);
		if(dp[i]==9) debug("9",i);
		REP1(j,9) d[j][i]=d[j][i-1];
		d[dp[i]][i]++;
	}
	REP(i,n){
		ll l,r,k;
		cin>>l>>r>>k;
		cout<<d[k][r]-d[k][l-1]<<endl;
	}
}
