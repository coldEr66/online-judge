#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,k;
    cin >> n >> k;
    long long result = n / k;
    if (result % 2 == 0) cout << "NO" << endl;
    else cout << "YES" << endl;
}
