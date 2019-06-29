#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define eb emplace_back
#define X first
#define Y second
#ifdef cold66
#define debug(...) do{\
		fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
		_do(__VA_ARGS__);\
}while(0)
template<typename T> void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<", ";_do(_t...);}
#define IOS()
#else
#define debug(...)
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#endif

const ll MAXn = 1e6+5;
bitset<MAXn> dp;
vector<ll> d;
ll dt[MAXn];
int main(){
	IOS();
	int t;
	cin >> t;
	while (t--) {
		dp.reset();
		d.clear();
		memset(dt,0,sizeof dt);
		ll n,sum = 0;
		cin >> n;
		REP (i,n) {
			ll x;
			cin >> x;
			sum += x;
			dt[x]++;
		}
		if (sum&1) {
			cout << "NO" << endl;
			continue;
		}
		REP1 (i,MAXn-1) {
			while (dt[i] >= 3) {
				dt[i] -= 2;
				dt[i<<1]++;
			}
			REP (j,dt[i]) d.eb(i);
		}
		dp[0] = 1;
		REP (i,SZ(d)) dp |= (dp<<d[i]);
		if (dp[sum/2]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
