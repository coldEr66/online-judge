#include "Brunolib.h"
#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int,int> ii;
#define X first
#define Y second

ii gt(int a,int b,int c){
    int ret = 4*a + 2*b + c;
    if (ret == 0) return ii(1,0);
    if (ret == 1) return ii(2,0);
    if (ret == 2) return ii(4,1);
    if (ret == 3) return ii(4,3);
    if (ret == 4) return ii(2,1);
    if (ret == 5) return ii(4,2);
    if (ret == 6) return ii(2,0);
    if (ret == 7) return ii(4,0);
    return ii(0,0);
}
long long Bruno( int N, int A[] ){
    long long ret = 0;
    for (int i=N-3;i>=0;i-=3) {
        ii tmp = gt(A[i],A[i+1],A[i+2]);
        ret = ret * tmp.X + tmp.Y;
    }
    return ret;
}
