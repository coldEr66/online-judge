/*input
3
1 3
1 3
1 3

*/
#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define F first
#define S second
#define REP(i,n) for(int i=0;i<((int)n);i++)
#define pb push_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#ifdef leowang
#define debug(...) do{\
	fprintf(stderr,"%s - %d : (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
	_DO(__VA_ARGS__);\
}while(0)
template<typename I> void _DO(I&&x){cerr<<x<<endl;}
template<typename I,typename...T> void _DO(I&&x,T&&...tail){cerr<<x<<", ";_DO(tail...);}
#else
#define debug(...)
#endif
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
	out<<'('<<P.F<<','<<P.S<<')';
	return out;
}
//}}}
const ll maxn=300005;
const ll maxlg=__lg(maxn)+2;
const ll INF64=8000000000000000000LL;
const int INF=0x3f3f3f3f;
const ll MOD=ll(1e9+7);
const double PI=acos(-1);
//const ll p=880301;
//const ll P=31;

ll mypow(ll a,ll b){
	ll res=1LL;
	while(b){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return res;
}

int n;
int x[maxn],y[maxn];
vector<int> __;
vector<int> p[maxn];

int BIT[maxn];

int low(int i){return i&(-i);}
int add(int n){
	for(int i=n;i<maxn;i+=low(i))
		BIT[i]++;
}
int query(int n){
	int ans=0;
	for(int i=n;i>0;i-=low(i)){
		ans+=BIT[i];
	}
	return ans;
}

int main()
{
	//IOS;
	cin>>n;
	REP(i,n) cin>>x[i]>>y[i];
	{
		REP(i,n) __.pb(x[i]);
		SORT_UNIQUE(__);
		REP(i,n) x[i]=GET_POS(__,x[i]);
	}
	{
		__.clear();
		REP(i,n) __.pb(y[i]);
		SORT_UNIQUE(__);
		REP(i,n) y[i]=n-GET_POS(__,y[i]); 
	}
	REP(i,n) p[x[i]].pb(y[i]);

	ll ans=0;
	REP(i,n){
		for(int j:p[i]) ans+=query(j);
		for(int j:p[i]) add(j);
		//cout<<ans<<'\n';
	}

	REP(i,maxn) sort(ALL(p[i]));
	REP(i,maxn){
		ans+=(ll)SZ(p[i])*(SZ(p[i])-1)/2;

		int l=0;
		REP(j,SZ(p[i])){
			if(j!=SZ(p[i])-1&&p[i][j]==p[i][j+1])
				continue;
			//cout<<j<<' '<<l<<'\n';

			ans+=(ll)(j-l+1)*(j-l)/2;
			l=j+1;
		}
	}

	cout<<ans<<'\n';
	return 0;
}
