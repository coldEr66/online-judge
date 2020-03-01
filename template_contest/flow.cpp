#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define RREP(i,n) for (ll i=n-1;i>=0;i--)
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define X first
#define Y second
#define mkp make_pair
#define pb push_back
#define eb emplace_back
#define pob pop_back
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<", ";_do(_t...);}
#define IOS()
#else
#define debug(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif

const ll MAXn=2e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const int INF=0x3f3f3f3f;

struct edge{
    int to,cap,rev;
};
vector<edge> E[MAXn];
int n;
int it[MAXn],lev[MAXn];
void addedge(int from,int to,int cap) {
    E[from].eb((edge){to,cap,SZ(E[to])});
    E[to].eb((edge){from,0,SZ(E[from])-1});
}
void BFS(){
    queue<int> q;
    q.push(0);
    RST(lev,-1);
    lev[0] = 0;
    while (SZ(q)) {
        int cur = q.front();
        q.pop();
        for (auto i:E[cur]) {
            if (i.cap > 0 && lev[i.to] < 0) {
                lev[i.to] = lev[cur] + 1;
                q.push(i.to);
            }
        }
    }
}
int dfs(int v,int f){
    if (v == n-1) return f;
    for (int &i=it[v];i<SZ(E[v]);i++) {
        edge &cur = E[v][i];
        if (cur.cap > 0 && lev[cur.to] > lev[v]) {
            int d = dfs(cur.to,min(f,cur.cap));
            if (d) {
                cur.cap -= d;
                E[cur.to][cur.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
int Dinic(){
    int flow = 0;
    for (;;) {
        BFS();
        if (lev[n-1] < 0) return flow;
        RST(it,0);
        int tmp;
        while ((tmp = dfs(0,INF))) flow += tmp;
    }
}
int main(){
    IOS();
    int t;
    cin >> t;
    while (t--) {
        REP (i,MAXn) E[i].clear();
        cin >> n;
        REP (i,n-1) {
            int k;
            cin >> k;
            REP (j,k) {
                int nd;
                cin >> nd;
                nd--;
                if (i == 0 || nd == n-1) {
                    addedge(i,nd,1);
                }
                else {
                    addedge(i,nd,INF);
                }
            }
        }
        int ans = Dinic();
        cout << ans << endl;
    }
}
