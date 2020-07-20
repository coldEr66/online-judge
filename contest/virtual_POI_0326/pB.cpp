#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RST(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define ALL(a) a.begin(),a.end()
#define eb emplace_back
#define SZ(a) int(a.size())
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"LINE %d: (%s) = ",__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0);
template<typename T> void _do(T &&_x){cerr << _x << endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr << _x << ", ";_do(_t...);}
#define IOS()
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(...)
#define endl '\n'
#endif

const ll MAXn=1e6+5;

int k[MAXn],fa[MAXn],mx;
int dep[MAXn],mxdep[MAXn];
int cnt[MAXn];
vector<int> e[MAXn];
vector<int> tmp;
void dfs(int x){
    debug(x);
    dep[x] = dep[fa[x]] + 1;
    cnt[dep[x]]++;
    mx = max(mx,dep[x]);
    for (auto i:e[x]) dfs(i);
}
int main(){
    IOS();
    int n,q;
    cin >> n >> q;
    REP (i,q) cin >> k[i];
    REP (i,n-1) {
        cin >> fa[i+1];
        fa[i+1]--;
        e[fa[i+1]].eb(i+1);
    }
    dfs(0);
    for (int i=mx-1;i>=1;i--) cnt[i] += cnt[i+1];


    REP (QQ,q) {

    }
}
