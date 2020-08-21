#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RST(i,n) memset(i,n,sizeof i)
#define ALL(a) a.begin(),a.end()
#define SZ(a) (int)a.size()
#define eb emplace_back
#define X first
#define Y second
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T> void _do(T &&_x){cerr << _x << endl;}
template<typename T,typename ...S> void _do(T &&_x,S && ..._t){cerr << _x << ", ";_do(_t...);}
#define IOS()
#else
#define debug(...)
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif

const ll MAXn=100005;
const ll INF=0x3f3f3f3f3f3f3f3f;
int pw(int x){return x*x;}
int id[15],p[15];
vector<int> v;
int main(){
    IOS();
    for (int i=1;i<=11;i++) {
        id[i] = i;
        p[i] = i;
        v.eb(i);
    }
    int ans = 0;
    vector<int> cur;
    ll cnt = 0;
    do {
        cnt++;
        int tmp = 0;
        for (int i=0;i<11;i++) {
            tmp += pw(abs(i+1-v[i]));
        }
        if (ans < tmp) {
            ans = tmp;
            cur = v;
        }
    }while(next_permutation(ALL(v)));
    for (int i=0;i<11;i++) cout << cur[i] << " \n"[i==10];
    cout << ans << endl;
    cout << cnt << endl;
}
