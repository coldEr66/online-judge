const int MAXn=1e5+5;

vector<int> e[MAXn],re[MAXn];
int vis[MAXn];
vector<int> topo;
int scc[MAXn];
void dfs1(int cur){
  vis[cur] = 1;
  for(int it:e[cur])if(!vis[it]) dfs1(it);
  topo.pb(cur);
}
void dfs2(int cur,int cnt){
  scc[cur] = cnt;
  vis[cur] = 1;
  for(int it:re[cur])if(!vis[it]) dfs2(it,cnt);
}
int main(){
  IOS();
  int n,m;
  cin>>n>>m;
  REP(i,m){
    int a,b;
    cin>>a>>b;
    a--,b--;
    e[a].pb(b);
    re[b].pb(a);
  }
  REP(i,n)if(!vis[i]) dfs1(i);
  RST(vis,0);
  int cnt = 0;
  reverse(ALL(topo));
  REP(i,n)if(!vis[topo[i]]) dfs2(topo[i],cnt++);
}
