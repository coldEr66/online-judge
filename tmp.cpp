#include <bits/stdc++.h>
using namespace std;

#define SZ(a) (int)a.size()


const int MAXN = 1e3+5;
int d[MAXN];

void insertion_sort()
int main(){
    int n;
    cin >> n;
    for (int i=0;i<n;++i) cin >> d[i];
    for (int i=1;i<n;++i) {
        int cur = d[i], j = i-1;
        while (cur < d[j] && j >= 0) {
            d[j+1] = d[j];
            j--;
        }
        d[j+1] = cur;
    }
    for (int i=0;i<n;++i) cout << d[i] << " \n"[i==n-1];
}
