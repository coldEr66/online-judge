  #include <queue>
  #include <bitset>
  #include "lib1168.h"
  using namespace std;

  priority_queue<pair<int,int>> mxpq;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> mnpq;
  bitset<1000005> ok;
  int cnt;
  void pop_big(){
    while(ok[mxpq.top().second]) mxpq.pop();
    ok[mxpq.top().second] = 1;
    mxpq.pop();
  }
  void pop_small(){
    while(ok[mnpq.top().second]) mnpq.pop();
    ok[mnpq.top().second] = 1;
    mnpq.pop();
  }
  void push(int s){
    mnpq.push({s,cnt});
    mxpq.push({s,cnt});
    ++cnt;
  }
  int big(){
    while(ok[mxpq.top().second]) mxpq.pop();
    return mxpq.top().first;
  }
  int small(){
    while(ok[mnpq.top().second]) mnpq.pop();
    return mnpq.top().first;
  }
