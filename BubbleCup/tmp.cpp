#include <bits/stdc++.h>
using namespace std;

int main(){
    for (int i=0;i<100;++i) {
        cout << (~i) << endl;
        cout << -i << endl;
        cout << ((~i) == (-i)) << endl;
        cout << endl;
    }
}
