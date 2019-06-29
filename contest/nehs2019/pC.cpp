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

const ll MAXn =1e5+5;
vector<ll> perfect;
void build(){
	for (ll i=1;i*i<MAXn*2;i++) {
		debug(i*i);
		perfect.eb(i*i);
	}
	debug(SZ(perfect));
}
int main(){
	IOS();
	build();
	string s;
	ll t;
	cin >> s >> t;
	string tmp = s;
	string last = "";
	REP (i,t) {
		if (SZ(tmp) == 1) break;
		string now = "";
		REP (j,SZ(perfect)) {
			if (perfect[j] > SZ(tmp)*2) break;
			ll nxt = (perfect[j]%SZ(tmp))-1;
			if (nxt < 0) nxt += SZ(tmp);
//			now += tmp[(perfect[j]-1+SZ(tmp))%SZ(tmp)];
			now += tmp[nxt];
			debug(now);
		}
		if (last == now) break;
		tmp = now;
		last = now;
	}
	cout << tmp << endl;
}

