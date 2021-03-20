#include <stdio.h>
#include <string.h>
#define MAXN 105
#define INF 1e9


struct {
    int u, to;
    int nxt;
} e[MAXN*2];
int head[MAXN], dis[MAXN], idx;
int q[MAXN];
int vis[MAXN];
void addedge(int u,int v){
    e[idx].u = u, e[idx].to = v;
    e[idx].nxt = head[u];
    head[u] = idx++;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=0;i<n;++i) dis[i] = INF;
    memset(head,-1,sizeof head);
    for (int i=0;i<m;++i) {
        int u,v;
        scanf("%d %d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    int l = 0, r = -1;
    int s,t;
    scanf("%d %d",&s,&t);
    dis[s] = 0, q[++r] = s;
    while (l <= r) {
        int cur = q[l++];
        for (int i=head[cur];i!=-1;i = e[i].nxt) {
            int to = e[i].to;
            if (!vis[to] && dis[to] > dis[cur] + 1) {
                dis[to] = dis[cur] + 1;
                q[++r] = to;
            }
        }
    }
    if (dis[t] == INF) printf("Oops\n");
    else printf("%d\n",dis[t]);
}
