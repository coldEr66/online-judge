#include <iostream>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ld;
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
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);

const ll MaxN=1e5+5;
const ll MOD=1000000007;
const ll INF=ll(1e15);

int main(){
	ll n,x,y,m,t;
	cin>>t;
	while(t--&&cin>>n>>x>>y>>m) cout<<(n-m*y)/(x-y)<<' '<<m-(n-m*y)/(x-y)<<endl;
}
