#include "Alicelib.h"
#include <cassert>
#include <cstdio>
using namespace std;
#define REP1(i,n) for(int i=1;i<=n;i++)
#define REP(i,n) for(int i=0;i<n;i++)

void Alice( int N, int M, int A[], int B[] ){
	int V = N + 12; // N~N+9 ,N+10~N+11;
	int U = M;
	REP (i,N) {
		U += __builtin_popcount(i);
	}
	U += 9, U += 2*N;
	InitG(V,U);
	int idx = 0;
	REP (i,M) {
		MakeG(idx++,A[i],B[i]);
	}
	for (int i=N;i<N+9;i++) MakeG(idx++,i,i+1);
	REP (i,N) {
		MakeG(idx++,i,N+10), MakeG(idx++,i,N+11);
		int tmp = i;
		int bit = 0;
		while (tmp) {
			if (tmp&1) MakeG(idx++,i,N+bit);
			tmp >>= 1;
			bit++;
		}
	}
}
