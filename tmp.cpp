#include <iostream>
#include <algorithm>
using namespace std;

int d[24];
int id[24];
int main(){
    srand(clock());
    int n = 12;
    for (int i=0;i<n;i++) {
        id[i] = i;
        d[i] = rand() % 1000;
        cout << i+1 << " " << d[i] << endl;
    }
    sort(id,id+n,[&](const int a,const int b){
        return d[a] < d[b];
    });
    for (int i=0;i<n;i++) {
        cout << id[i]+1 << " \n"[i==n-1];
    }
}
