#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
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

int a[MAXn],b[MAXn],c[MAXn];
// int lstart[MAXn],rstart[MAXn];
int l[MAXn],r[MAXn];
int llst[MAXn],rlst[MAXn];
vector<int> pos[MAXn];
int ida[MAXn],idb[MAXn];
int main(){
    IOS();
    int n,k;
    cin >> n >> k;
    REP (i,n) {
        cin >> c[i];
        // lstart[i] = rstart[i] = i;
        pos[c[i]].eb(i);
    }
    int M,L;
    cin >> M >> L;
    RST(ida,-1), RST(idb,1);
    REP (i,M) {
        cin >> a[i];
        ida[a[i]] = i;
    }
    REP (i,L) {
        cin >> b[i];
        idb[b[i]] = i;
    }
    // if (m > 1) {
    //     int cur = n;
    //     for (int i=n-1;i>=0;i--) {
    //         if (c[i] == a[0]) cur = i;
    //         else lstart[i] = cur;
    //     }
    // }
    // if (l > 1) {
    //     int cur = -1;
    //     REP (i,n) {
    //         if (c[i] == b[l-2]) cur = i;
    //         else rstart[i] = cur;
    //     }
    // }
    RST(llst,-1);
    REP (i,n) {
        int id = ida[c[i]];
        if (id == -1) continue;
        if (id == M-1) {
            l[i] = i;
            continue;
        }
        int cur = *upper_bound(ALL(pos[a[id+1]]),i);
        l[i] = cur;
        llst[cur] = i;
    }
    for (int i=n-1;i>=0;i--) {
        if (llst[i] != -1) {
            l[llst[i]] = l[i];
        }
    }
    REP (i,n) rlst[i] = n;
    REP (i,n) {
        int id = idb[c[i]];
        if (id == -1) continue;
        if (id == L-1) continue;
    }
}
