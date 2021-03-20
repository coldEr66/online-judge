#include <bits/stdc++.h>
using namespace std;


const int MAXN = 1e2+5;
int dp[MAXN][MAXN];
int d[MAXN];
int sum[MAXN];
int tmp[MAXN];
int gogo(int l,int r){
    if (l == r) return tmp[l]&1;
    if (dp[l][r] != -100000000) return dp[l][r];
    int tt = sum[r] - sum[l-1];
    return dp[l][r] = tt - min(gogo(l,r-1),gogo(l+1,r));
}
int main(){
    int n;
    cin >> n;
    int cnt = 0;
    int tt = 0;
    for (int i=1;i<=n;++i) {
        cin >> d[i];
        tt += (d[i]&1);
    }
    for (int i=1;i<=n;++i) {
        int idx = 1;
        memset(tmp,0,sizeof tmp);
        for (int j=i+1;j<=n;++j) {
            tmp[idx] = d[j];
            idx++;
        }
        for (int j=1;j<i;++j) {
            tmp[idx] = d[j];
            idx++;
        }
        memset(sum,0,sizeof sum);
        for (int j=1;j<=n-1;++j) {
            sum[j] = sum[j-1] + (tmp[j]&1);
        }
        for (int j=1;j<=n-1;++j) for (int k=1;k<=n-1;++k) dp[j][k] = -100000000;
        if (2 * gogo(1,n-1) < tt) cnt++;
    }
    cout << cnt << endl;
}
