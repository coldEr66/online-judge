#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);

const int MAXN = 1e5+5;

int n;
ll L[MAXN],R[MAXN];
ll b[MAXN], sum[MAXN];
ll gt(int x){
    return R[x] - L[x];
}
bool lchk(int x){
    return L[x] > 1 && gt(x) * 500 > b[L[x]-1] - 1000;
}
bool rchk(int x){
    return R[x] <= n && gt(x) * 500 > b[R[x]] - 1000;
}
int main(){
    IOS();
    cin >> n;
    for (int i=1;i<=n;++i) {
        cin >> b[i];
        sum[i] = b[i] + sum[i-1];
    }

    for (int i=1;i<=n;++i) {
        L[i] = i, R[i] = i+1;
        while (1) {
            if (lchk(i)) {
                R[i] = max(R[i],R[L[i]-1]);
                L[i] = min(L[i],L[L[i]-1]);
            }
            else if (rchk(i)) {
                while (rchk(i)) R[i]++;
            }
            else break;    
        }
    }
    int bst = 1;
    for (int i=1;i<=n;++i) {
        if (R[i] - L[i] > R[bst] - L[bst]) bst = i;
    }
    cout << R[bst] - L[bst] << ' ' << bst-1 << endl;
}
