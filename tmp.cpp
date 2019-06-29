#include <bits/stdc++.h>
using namespace std;

char d[24];
int main(){
    ll n,g;
    cin >> n >> g;
    REP (i,n) cin >> d[i];
    sort(d,d+n);
    do {
        int cur = 0;
        int tt = 0;
        for (int i=0;i<n;i++) {
            if (!i && !isdigit(d[i])) break;
            
        }
    }while (next_permutation(d,d+n));
}
