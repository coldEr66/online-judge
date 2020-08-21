#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

const int MAXn = 2003;
int deg[MAXn],mx[MAXn];
int fa[MAXn],dep[MAXn];
int ans,col[MAXn],pr[MAXn];
bool vis[MAXn];
vector<int> e[MAXn];
pair<int,int> d[MAXn],tmp[MAXn];
void dfs1(int x,int p){
    fa[x] = p;
    dep[x] = dep[fa[x]] + 1;
    for (auto i:e[x]) {
        if (i == p) continue;
        dfs1(i,x);
    }
}
int LCA(int x,int y){
    while (x != y) {
        if (dep[x] < dep[y]) swap(x,y);
        x = fa[x];
    }
    return x;
}
void dfs2(int x) {
    for (auto i:e[x]) {
        if (i == fa[x]) continue;
        dfs2(i);
        mx[x] += mx[i];
    }
    ans += min(mx[x],2);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=0;i<n-1;++i) {
        int u,v;
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
        deg[u]++, deg[v]++;
    }
    dfs1(1,0);
    for (int i=1;i<=m;++i) {
        cin >> d[i].X >> d[i].Y;
        tmp[i] = d[i];
        mx[d[i].X]++, mx[d[i].Y]++, mx[LCA(d[i].X,d[i].Y)] -= 2;
    }
    dfs2(1);

    for (int c=0;c<n-1;++c) {
        int now = 0;
        for (int i=2;i<=n;++i) {
            if (!vis[i] && deg[i] == 1) {
                now = i;
                break;
            }
        }
        vis[now] = true;
        int tmpfa = 0;
        for (auto i:e[now]) {
            if (!vis[i]) {
                tmpfa = i;
                break;
            }
        }

        deg[tmpfa]--;
        int ta = 0, tb = 0;
        for (int i=1;i<=m;++i) {
            if ((tmp[i].X == now) ^ (tmp[i].Y == now)) {
                if (ta == 0) ta = i;
                else tb = i;
            }
        }

        if (!ta && !tb) continue;
        if (!tb) {
            if (tmp[ta].X == now) tmp[ta].X = tmpfa;
            else tmp[ta].Y = tmpfa;
            continue;
        }
        if (tmp[ta].X == now) {
            if (tmp[tb].X == now) {
                tmp[ta].X = tmp[tb].Y;
                col[tb] ^= 1;
            }
            else tmp[ta].X = tmp[tb].X;
        }
        else {
            if (tmp[tb].Y == now) {
                tmp[ta].Y = tmp[tb].X;
                col[tb] ^= 1;
            }
            else tmp[ta].Y = tmp[tb].Y;
        }
        pr[tb] = ta;
        tmp[tb].X = tmp[tb].Y;
        for (int i=1;i<=m;++i) {
            if ((tmp[i].X == now) ^ (tmp[i].Y == now)) {
                if (tmp[i].X == now) tmp[i].X = tmpfa;
                else tmp[i].Y = tmpfa;
            }
        }
    }
    for (int i=1;i<=m;++i) {
        if (pr[i]) col[i] ^= col[pr[i]];
    }
    
    cout << ans << endl;
    for (int i=1;i<=m;++i) {
        if (col[i]) swap(d[i].X,d[i].Y);
        cout << d[i].X << " " << d[i].Y << endl;
    }
}
