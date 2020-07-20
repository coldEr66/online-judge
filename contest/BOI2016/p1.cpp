#include <bits/stdc++.h>
#pragma GCC optimize ("unroll-loops")
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,n) for(int i=1;i<=n;++i)
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define eb emplace_back
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"LINE %d: (%s) = ",__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T> void _do(T &&_x){cerr << _x << endl;}
template<typename T,typename ...S> void _do(T &&_x,S && ..._t){cerr << _x << ", ";_do(_t...);}
#define IOS()
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(...)
#define endl '\n'
#endif

const int MAXn=5e3+5;
const int INF=0x3f3f3f3f;

queue<int> q;
int sz[MAXn],tmp,dis[MAXn];
vector<int> e[MAXn],child[MAXn];
void dfs(int x){
    sz[x] = 1;
    for (auto i:child[x]) {
        dfs(i);
        sz[x] += sz[i];
    }
    tmp += sz[x];
}
int main(){
    IOS();
    int n;
    cin >> n;
    REP (i,n) {
        int k;
        cin >> k;
        REP (j,k) {
            int v;
            cin >> v;
            --v;
            e[v].eb(i);
        }
    }
    int ans = INF;
    int cnt;
    REP (i,n) {
        cnt = 0, tmp = 0;
        REP (j,n) {
            dis[j] = INF;
            child[j].clear();
        }
        q.emplace(i);
        dis[i] = 0;
        while (SZ(q)) {
            int cur = q.front();
            q.pop();
            ++cnt;
            for (auto it:e[cur]) {
                if (dis[it] > dis[cur] + 1) {
                    dis[it] = dis[cur] + 1;
                    q.emplace(it);
                    child[cur].eb(it);
                }
            }
        }
        dfs(i);
        if (cnt == n) ans = min(ans,tmp);
    }
    cout << ans << endl;
}
