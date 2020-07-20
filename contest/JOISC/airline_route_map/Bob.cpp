#include "Boblib.h"
#include <bits/stdc++.h>
using namespace std;
#define REP1(i,n) for(int i=1;i<=n;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define SZ(a) (int)a.size()

const int MAXn=1e3+20;

bitset<MAXn> bs[MAXn];
int bit[MAXn];
int deg[MAXn];
int id[MAXn];
vector<int> e[MAXn];
int p[MAXn];
void dfs(int x,int par,int b){
	bit[x] = (1<<b);
	for (auto i:e[x]) {
		if (i == par || id[i] != 2) continue;
		dfs(i,x,b+1);
	}
}
void Bob( int V, int U, int C[], int D[] ){
	int N = V-12;
	REP (i,U) {
		bs[C[i]][D[i]] = 1;
		bs[D[i]][C[i]] = 1;
		e[C[i]].emplace_back(D[i]);
		e[D[i]].emplace_back(C[i]);
	}
	int S = -1, T = -1;
	REP (i,V) {
		if (int(bs[i].count()) != N) continue;
		for (int j=i+1;j<V;j++) {
			if (int(bs[j].count()) != N) continue;
			if (int((bs[i] & bs[j]).count()) == N) {
				S = i, T = j;
				id[S] = 1, id[T] = 1;
			}
		}
	}
	vector<int> tmp;
	REP (i,V) {
		if (bs[S][i] == 0 && i != S && i != T) {
			tmp.emplace_back(i);
			id[i] = 2;
		}
	}
	int X = -1;
	REP (i,SZ(tmp)) {
		int cur = tmp[i];
		int cnt = 0;
		for (auto it:e[cur]) {
			if (id[it] == 2) cnt++;
		}
		if (cnt == 1) {
			if (X == -1) X = cur;
			else if (SZ(e[cur]) > SZ(e[X])) X = cur;
		}
	}
	dfs(X,X,0);
	int M = 0;
	REP (i,V) {
		if (id[i] == 0) {
			for (auto it:e[i]) {
				if (id[it] == 0) M++;
				if (id[it] == 2) {
					p[i] += bit[it];
				}
			}
		}
	}
	M /= 2;
	InitMap(N,M);
	REP (i,U) {
		if (id[C[i]] == 0 && id[D[i]] == 0) {
			MakeMap(p[C[i]],p[D[i]]);
		}
	}
}
