#include <stdio.h>
#include <string.h>

int r;
char ok[35][35];
int vis[35];
int old[35][35], young[35][35];
int gt(char* cur) { // 去找這個字串cur有沒有出現過
    for (int i=0;i<r;++i) {
        if (strcmp(ok[i],cur) == 0) return i;
    }
    vis[r] = 1000;
    strcpy(ok[r],cur);
    return r++;
}
void dfs(int x, int lev) { // 從Dong出發，看誰比他老誰比他年輕
    vis[x] = lev;
    for (int i=0;i<r;++i) {
        if (vis[i] == 1000) {
            if (old[x][i]) dfs(i,lev+1);
            if (young[x][i]) dfs(i,lev-1);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    char tps[35], tpt[35];
    for (int i=0;i<n;++i) {
        scanf("%s %s",tps,tpt); // s is t's son
        int s = gt(tps), t = gt(tpt);
        young[t][s] = 1;
        old[s][t] = 1;
    }
    int cur = gt("Dong");
    dfs(cur,0);
    for (int i=0;i<r;++i) {
        if (i == cur) continue;
        printf("%s ",ok[i]);
        if (vis[i] == 1000) printf("unknown\n");
        else if (vis[i] > 0) printf("elder\n");
        else if (vis[i] < 0) printf("younger\n");
        else printf("same\n");
    }
}
