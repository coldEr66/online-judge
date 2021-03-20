#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const ll MOD = 1e9+7;
ll dp[5],tmpdp[5];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    dp[0] = 1;
    for (int i=0;i<n;++i) {
        for (int j=0;j<=3;++j) tmpdp[j] = dp[j];
        if (s[i] == '?') {
            for (int j=0;j<=3;++j) tmpdp[j] = 3 * tmpdp[j] % MOD;
            for (int j=0;j<3;++j) tmpdp[j+1] = (tmpdp[j+1] + dp[j]) % MOD;
        }
        else {
            tmpdp[s[i] - 'a' + 1] = (tmpdp[s[i] - 'a' + 1] + dp[s[i] - 'a']) % MOD;
        }
        for (int j=0;j<=3;++j) dp[j] = tmpdp[j];
    }
    cout << dp[3] << endl;
}
