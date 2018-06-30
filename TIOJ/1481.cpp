#include<bits/stdc++.h>
#include"lib1481.h"
using namespace std;
const int MAXn=2e3+5,MAXm=2e4+5;

struct P{int from,to;};

bool vis[MAXm];
int ans[MAXm],cnt=0;
vector<int> v[MAXn];
vector<P> e;

void dfs(int x){
  for(auto i : v[x])if(!vis[i]){
    int to= e[i].from==x ?e[i].to:e[i].from;
    vis[i]=1;
    ans[i]=++cnt;
    dfs(to);
  }
}

int main(){
  Init() ;
  int n,k ;
  cin>>n>>k;
  for(int i=0;i<k;i++){
      int x,y;
      cin>>x>>y;
      e.push_back((P){x,y});
      v[x].push_back(i);
      v[y].push_back(i);
  }
  dfs(1);
  Possible();
  for(int i=0;i<k;i++) Number(ans[i]);
  Finish();
}
