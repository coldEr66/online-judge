#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define eb emplace_back

const int MAXn=1e5+5,MAXlg=__lg(MAXn)+2;

vector<int> e[MAXn];
int low[MAXn],dfn[MAXn],t;
vector<int> ans;
void dfs(int x,int p){
  low[x] = dfn[x] = ++t;
  int cnt=0;
  bool ok=false;
  for( auto i:e[x] ){
    if( !dfn[i] ){
      cnt++;
      dfs(i,x);
      low[x] = min(low[x],low[i]);
      if( low[i]>=dfn[x] ) ok=true;
    }
    else low[x] = min(low[x],dfn[i]);
  }
  if( ok && x!=p || x==p && cnt>1 ) ans.eb(x);
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m;
  REP(i,m){
    int a,b;
    cin>>a>>b;
    e[a].eb(b);
    e[b].eb(a);
  }
  REP(i,n)if( !dfn[i] ) dfs(i,i);
  for( auto i:ans ) cout<<i<<' ';
  cout<<endl;
}
