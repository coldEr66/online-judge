#include <bits/stdc++.h>
using namespace std;
#include "molecules.h"
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define X first
#define Y second

std::vector<int> find_subset(int l, int u, std::vector<int> w) {
  vector<int> ret;
  vector<pair<int,int> > tmp;
  for (int i=0;i<SZ(w);i++) tmp.emplace_back(w[i],i);
  sort(ALL(tmp));

  long long sum = 0;
  int L = 0, R = 0;
  for (;L<SZ(w);L++) {
    while (sum < l && R < SZ(w)) sum += tmp[R++].X;
    if (l <= sum && sum <= u) {
      for (int i=L;i<R;i++) ret.emplace_back(tmp[i].Y);
      break;
    }
    if (L < R) sum -= tmp[L].X;
  }
  return ret;
}
