#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool chk(ll x,ll n){
    map<ll,ll> mp;
    ll cnt = 1;
    mp[x] = true;
    ll cur = x;
    while (1) {
        cur *= x;
        cur %= n;
        if (mp.count(cur)) break;
        cnt++;
        mp[cur] = true;
    }
    if (cnt == n-1) return true;
    return false;
}
int main(){
    ll n;
    cin >> n;
    ll ret = 10000000000000LL;
    for (ll i=2;i*i<=sqrt(n-1);++i) {
        if ((n-1) % i == 0) {
            if (chk(i,n)) ret = min(ret,i);
            if (chk((n-1)/i,n)) ret = min(ret,n/i);
        }
    }
    cout << ret << endl;
}
