#include <bits/stdc++.h>
#include "combo.h"
#define SZ(a) (int)a.size()
using namespace std;

int press(string p);
char pre(){
  if (press("AB") > 0) {
    if (press("A") > 0) return 'A';
    return 'B';
  }
  else {
    if (press("X") > 0) return 'X';
    return 'Y';
  }
}
string s="ABXY";
char ok[3];
string guess_sequence(int N){
  string S = "";
  S += pre();
  int cnt = 0;
  for (int i=0;i<4;i++) {
    if (s[i] == S[0]) continue;
    ok[cnt++] = s[i];
  }

  for (int i=1;i<N-1;i++) {
    string tmp = S + ok[0];
    for (int j=0;j<3;j++) tmp += (S + ok[1] + ok[j]);
    int Q = press(tmp);
    if (Q == SZ(S)) S += ok[2];
    else if (Q == SZ(S)+1) S += ok[0];
    else S += ok[1];
  }

  if (N > 1) {
    for (int i=0;i<2;i++) {
      if (press(S + ok[i]) == SZ(S) + 1) {
        S += ok[i];
        break;
      }
    }
    if (SZ(S) < N) S += ok[2];
  }

  return S;
}
