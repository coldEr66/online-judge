#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
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

const ll MAXn=1e5+5;
ll dt[MAXn];
deque<ll> dq;
map<ll,vector<ll> > mp;
int main(){
	IOS();
	ll n,k,d;
	cin >> n >> k >> d;
	REP (i,n) {
		cin >> dt[i];
	}
	sort(dt,dt+n);
	REP (i,n) mp[dt[i]%d].eb(dt[i]);
	
	ll ans = 0;
	for (auto it:mp) {
		vector<ll> V = it.Y;
		ll tmp = (k-1)*d;
		ll cnt = 1;
		ll r = V[0]+tmp;
//		for (auto i:V) {
//			debug(it.X,i,r);
//			if (!ok) {
//				cnt++;
//				r = i + tmp;
//				ok = true;
//			}
//			if (i <= r) continue;
//			else {
//				ok = false;
//			}
//		}
		for (ll i=1;i<SZ(V);i++) {
			if (V[i] <= r) continue;
			r = V[i] + tmp;
			cnt++;
		}
		ans += cnt;
	}
	cout << ans << endl;
}

