#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAXN 105

const int INF = 100000000;
int dis[MAXN];
int vis[MAXN];
int it[MAXN], sz[MAXN];
int u[MAXN],v[MAXN];
int *e[MAXN];
int q[MAXN];
int min(int a,int b){
    return a > b ?b:a;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=0;i<n;++i) dis[i] = INF;
    for (int i=0;i<m;++i) {
        scanf("%d %d",&u[i],&v[i]);
        sz[u[i]]++, sz[v[i]]++;
    }
    for (int i=0;i<n;++i) {
        e[i] = (int*)malloc(sizeof(int) * (sz[i]+1));
    }
    for (int i=0;i<m;++i) {
        int U = u[i], V = v[i];
        e[U][it[U]++] = V;
        e[V][it[V]++] = U;
    }
    int s,t;
    scanf("%d %d",&s,&t);
    int l = 0, r = -1;
    dis[s] = 0, q[++r] = s;
    while (l <= r) {
        int cur = q[l++];
        vis[cur] = true;
        for (int i=0;i<it[cur];++i) {
            int to = e[cur][i];
            if (!vis[to] && dis[to] > dis[cur] + 1) {
                dis[to] = dis[cur] + 1;
                q[++r] = to;
            }
        }
    }
    if (dis[t] == INF) printf("Oops\n");
    else printf("%d\n",dis[t]);
}
