#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"#%d (%s) = ",__LINE__,#__VA_ARGS__),_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif


const int maxn = 3e5+5;
const ll inf = 0x3f3f3f3f3f3f3f3f;

ll n,p;
string s;
ll gt(ll x,ll y){
    ll ret = 0;
    for (int i=x;i<=y;i++) {
        ret = ret * 10 % p;
        ret = (ret + s[i]-'0')%p;
    }
    return ret;
}
int main(){
    IOS();
    cin >> n >> p;
    cin >> s;
    ll ans = 0;
    for (int i=0;i<n;i++) for (int j=i;j<n;j++) {
        if (gt(i,j) == 0) ans++;
    }
    cout << ans << endl;
}
