#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll floor_sum(ll n,ll m,ll a,ll b){
    ll ret = 0;
    if (a >= m) {
        ret += n * (n-1) * (a/m) / 2;
        a %= m;
    }
    if (b >= m) {
        ret += n * (b/m);
        b %= m;
    }

    ll Y = (a * (n-1) + b) / m;
    if (Y == 0) return ret;
    ll X = m * Y - b;
    ret += Y * (n - (X + a - 1) / a);
    ret += floor_sum(Y, a, m, (a - X % a) % a);
    return ret;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        cout << floor_sum(a,b,c,d) << endl;
    }
}
