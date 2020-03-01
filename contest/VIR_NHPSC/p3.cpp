#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RST(i,n) memset(i,n,sizeof i)
#define ALL(a) a.begin(),a.end()
#define SZ(a) (int)a.size()
#define X first
#define Y second
#define eb emplace_back
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T> void _do(T && _x){cerr << _x << endl;}
template<typename T,typename ...S> void _do(T &&_x,S && ..._t){cerr << _x << ", ";_do(_t...);}
#define IOS()
#else
#define debug(...)
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#endif

const ll MAXn = 5e5+5;

int n,q;
vector<pair<ii,int> > a,b;
int ans[MAXn];
int dsu[MAXn],sz[MAXn];
int fnd(int x){
    if (dsu[x] == x) return x;
    return dsu[x] = fnd(dsu[x]);
}
void mrg(int x,int y){
    x = fnd(x), y = fnd(y);
    if (sz[x] < sz[y]) swap(x,y);
    dsu[y] = x;
    sz[x] += sz[y];
}
void go (int x) {
    REP1 (i,n) {
        dsu[i] = i;
        sz[i] = 1;
    }
    int msk = 1<<x;
    int lst = -1;
    int idx = 0;
    ii block = ii(-1,-1);
    REP (i,q) {
        if (b[i].Y & msk) {
            int cur = b[i].X.Y;
            debug(cur);
            while (idx < q && a[idx].X.X <= cur) {
                debug(x,idx);
                if ((a[idx].Y & msk) != 0) {
                    idx++;
                    continue;
                }
                else {
                    if (block.X == -1) {
                        block = ii(a[idx].X.X-1,a[idx].X.Y);
                    }
                    else if (block.Y >= a[idx].X.X-1) {
                        block.Y = max(block.Y,a[idx].X.Y);
                    }
                    else {
                        block = ii(a[idx].X.X-1,a[idx].X.Y);
                    }
                    if (cur > block.X && cur <= block.Y) {
                        cur = block.X;
                        break;
                    }
                    idx++;
                }
            }
            assert(cur >= b[i].X.X);
            if (lst < b[i].X.X) {
                debug(cur);
                ans[cur] |= msk;
                lst = cur;
            }
            debug(lst,b[i].X.X,cur);
        }
    }
}
int main(){
    IOS();
    cin >> n >> q;
    REP (i,q) {
        int l,r,w;
        cin >> l >> r >> w;
        a.eb(ii(l,r),w);
        b.eb(ii(l,r),w);
    }
    sort(ALL(a),[&](const pair<ii,int> x,const pair<ii,int> y){
        return x.X.X < y.X.X;
    });
    sort(ALL(b),[&](const pair<ii,int> x,const pair<ii,int> y){
        return x.X.Y < y.X.Y;
    });
    REP (i,q) debug(a[i].X.X,a[i].X.Y,a[i].Y);
    REP (i,q) debug(b[i].X.X,b[i].X.Y,b[i].Y);
    REP (i,30) go(i);
    REP1 (i,n) cout << ans[i] << " \n"[i==n];
}
