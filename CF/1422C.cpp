#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SZ(a) (int)a.size()
#define endl '\n'

const int MAXn = 1e5+5;
const ll MOD = 1e9+7;
ll add(ll a,ll b){
    ll ret = a + b;
    if (ret >= MOD) ret -= MOD;
    return ret;
}
ll sub(ll a,ll b){
    ll ret = a-b;
    if (ret < 0) ret += MOD;
    return ret;
}
ll mul(ll a,ll b){
    return a * b % MOD;
}
ll dp[2];
ll a[2];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    cin >> s;
    int n = SZ(s);
    dp[0] = a[0] = ll(s[0] - '0');
    ll cur = s[0] - '0';
    int roll = 0;
    for (ll i=1;i<n;++i) {
        ll tmp = i * (i+1) / 2 + 1;
        dp[!roll] = mul(dp[roll],10);
        dp[!roll] = add(dp[!roll],mul(ll(s[i]-'0'),tmp));
        dp[!roll] = add(dp[!roll],a[roll]);
        cur = add(mul(cur,10),ll(s[i]-'0'));
        a[!roll] = add(a[roll],cur);
        roll = !roll;
    }
    cout << sub(dp[roll],cur)  << endl;
}
