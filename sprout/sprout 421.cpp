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

const ll MAXn=1e5+5;
const ll MOD=1000000007;
const ll INF=(ll)1e18;

ll n,m;
ll d[MAXn];
ll dp[MAXn];
void init(){
	cin>>n>>m;
	REP(i,n) cin>>d[i];
	REP(i,MAXn) dp[i]=INF;
	dp[0]=0;
}

void build(){

}
ll search(ll x){
	ll l=0,r=MAXn-1;
	while(l+1<r){
		ll mid=(l+r)/2;
		if(dp[mid]>x) r=mid;
		else l=mid;
	}
	return l+1;
}
ll ans;
void sol(){
	REP(i,n){
		ll x=search(d[i]);
		ll y=search(d[i]*2);
		if(d[i]>=m) dp[x]=min(dp[x],d[i]);
		if(d[i]*2>=m) dp[y]=min(dp[y],d[i]*2);
		debug(dp[x],dp[y]);
	}
	REP(i,MAXn)if(dp[i]!=INF) ans=i;
	cout<<ans<<endl;
}

int main(){
	IOS();
	ll t;
	cin>>t;
	while(t--){
		init();
		sol();
	}
}

