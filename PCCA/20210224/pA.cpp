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

ll dep[MAXN], anc[MAXN][MAXlg];
vector<int> e[MAXN];
void dfs(int x,int p){
    if (x != p) dep[x] = dep[p] + 1;
    anc[x][0] = p;
    for (int i=1;(1<<i) < MAXN;++i) {
        anc[x][i] = anc[anc[x][i-1]][i-1];
    }

    for (auto i:e[x]) {
        if (i == p) continue;
        dfs(i,x);
    }
}
int gtlca(int x,int y){
    if (dep[x] < dep[y]) swap(x,y);
    for (int i=MAXlg-1;i>=0;--i) {
        if (((dep[x] - dep[y])>>i)&1) {
            x = anc[x][i];
        }
    }
    if (x == y) return x;
    for (int i=MAXlg-1;i>=0;--i) {
        if (anc[x][i] != anc[y][i]) {
            x = anc[x][i], y = anc[y][i];
        }
    }
    return anc[x][0];
}
signed main(){
    IOS();
    int n,q;
    cin >> n >> q;
    for (int i=0;i<n-1;++i) {
        int u,v;
        cin >> u >> v;
        u--, v--;
        e[u].eb(v);
        e[v].eb(u);
    }
    dfs(0,0);
    while (q--) {
        int r,p;;
        cin >> r >> p;
        r--, p--;
        int lca = gtlca(r,p);
        debug(r,p,lca);
        ll dis = dep[r] + dep[p] - 2 * dep[lca];
        cout << n - dis - 1 + (dis + 1) * (dis + 2) / 2 << endl;
    }
}
