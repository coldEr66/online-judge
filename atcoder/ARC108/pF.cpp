#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define X first
#define Y second
#define eb emplace_back
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"LINE %d: (%s) = ",__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<", ";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
template<typename It> ostream& _OUTC(ostream &_s,It _ita,It _itb)
{
    _s<<"{";
    for(It _it=_ita;_it!=_itb;_it++)
    {
        _s<<(_it==_ita?"":",")<<*_it;
    }
    _s<<"}";
    return _s;
}
template<typename _a> ostream &operator << (ostream &_s,vector<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#define IOS()
#else
#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // cold66
//}

const ll MAXN=2e5+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int n;
vector<int> e[MAXN],d0,d1;
bool ok[MAXN];
ll dep0[MAXN],dep1[MAXN];
ll p[MAXN];
ll add(ll a,ll b){
    ll ret = a + b;
    if (ret >= MOD) ret -= MOD;
    return ret;
}
ll mul(ll a,ll b){
    return a * b % MOD;
}
void build(){
    p[0] = 1;
    for (int i=1;i<=n;++i) {
        p[i] = mul(p[i-1], 2LL);
        d0.eb(i-1), d1.eb(i-1);
    }
}
void dfs(int x,int fa,ll *d) {
    if (x != fa) d[x] = d[fa] + 1;
    for (auto i:e[x]) {
        if (i == fa) continue;
        dfs(i,x,d);
    }
}
signed main(){
    IOS();
    cin >> n;
    build();
    for (int i=0;i<n-1;++i) {
        int u,v;
        cin >> u >> v;
        u--, v--;
        e[u].eb(v);
        e[v].eb(u);
    }
    dfs(0,0,dep0);

    int x = int(max_element(dep0,dep0+n) - dep0);
    for (int i=0;i<n;++i) dep0[i] = 0;
    dfs(x,x,dep0);
    int y = int(max_element(dep0,dep0+n) - dep0);
    ll D = dep0[y];
    dfs(y,y,dep1);
    sort(ALL(d0),[&](const int a,const int b){
        return dep0[a] > dep0[b];
    });
    sort(ALL(d1),[&](const int a,const int b){
        return dep1[a] > dep1[b];
    });
    debug(D, d0, d1);

    ll curd = 0;
    ll ans = 0;
    ok[x] = ok[y] = true;
    ans = add(ans, mul(p[n-1], D));
    ll it0 = 0, it1 = 0;
    for (int i=0;i<n-2;++i) {
        while (it0 < SZ(d0) && ok[d0[it0]]) it0++;
        while (it1 < SZ(d1) && ok[d1[it1]]) it1++;
        
        int cur0 = d0[it0], cur1 = d1[it1];
        if (dep0[cur0] >= dep1[cur1]) {
            ans = add(ans, mul(p[n-2-i], max(dep0[cur0], curd)));
            curd = max(curd, dep1[cur0]);
            ok[cur0] = true;
        }
        else {
            ans = add(ans, mul(p[n-2-i], max(dep1[cur1], curd)));
            curd = max(curd, dep0[cur1]);
            ok[cur1] = true;
        }
    }
    ans = add(ans, mul(2LL, curd));
    cout << ans << endl;
}
