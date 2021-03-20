#include <stdio.h>
typedef long long ll;
#define MAXN 55


int vis[MAXN][MAXN];
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
ll ans;
int x,y;
int chk(int i,int j){
    return i < 0 || i >= x+1 || j < 0 || j >= y+1;
}
void dfs(int i,int j) {
    if (x == i && y == j) {
        ans++;
        return;
    }
    vis[i][j] = 1;
    for (int k=0;k<4;++k) {
        int tx = i + dx[k], ty = j + dy[k];
        if (chk(tx,ty) || vis[tx][ty]) continue;
        dfs(tx,ty);
    }
    vis[i][j] = 0;
}

int main(){
    scanf("%d %d",&x,&y);
    x--, y--;
    dfs(0,0);
    printf("%lld\n",ans);
}
