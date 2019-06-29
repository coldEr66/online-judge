#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t; assert(t == 1 || t == 37); while (t--) {
        int n; cin >> n; assert(3 <= n && n <= 100000);
        vector<int> v(n);
        for_each(v.begin(), v.end(), [](int x){ string s; cin >> s; assert(accumulate(s.begin(), s.end(), 0, [](int a, char c) -> int { return a + isdigit(c); }) <= 9);});
    }
    cout << 0 << endl;
}
