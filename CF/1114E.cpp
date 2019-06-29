#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ask(ll x){
	cout << "> " << x << endl;
	ll bck;
	cin >> bck;
	return bck;
}
int main(){
	srand(clock());
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >> n;
	ll l = 0, r = (ll)1e9+1;
	ll cnt = 0;
	while (l != r-1) {
		cnt++;
		ll mid = (l+r)>>1;
		bool chk = ask(mid);
		if (chk) l = mid;
		else r = mid;
	}
	vector<ll> v;
	for (int i=0;i<60-cnt;i++) {
		ll tmp = (rand()<<15 | rand() )%n;
		cout << "? " << tmp+1 << endl;
		ll bck;
		cin >> bck;
		v.emplace_back(bck);
	}
	sort(v.begin(),v.end());

	ll d = 0;
	for (int i=0;i<(int)v.size()-1;i++) {
		d = __gcd(d,v[i+1]-v[i]);
	}
	cout << "! " << r - (n-1)*d << ' ' << d << endl;
}
