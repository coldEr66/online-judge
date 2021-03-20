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

const ll MAXN=3e5+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

vector<int> e[MAXN],tree[MAXN];
int dfn[MAXN],low[MAXN],idx;
vector<int> stk;
int bcc_id[MAXN],bcc,dep[MAXN];
void dfs(int x,int p){
    low[x] = dfn[x] = ++idx;
    stk.eb(x);
    for (auto i:e[x]) {
        if (i == p) continue;
        if (!dfn[i]) {
            dfs(i,x);
            low[x] = min(low[x],low[i]);
        }
        else {
            low[x] = min(low[x],dfn[i]);
        }
    }
    if (dfn[x] == low[x]) {
        int cur;
        do {
            cur = stk.back();
            bcc_id[cur] = bcc;
            stk.pop_back();
        } while (cur != x);
        bcc++;
    }
}
void gogo(int x,int p) {
    if (x != p) dep[x] = dep[p] + 1;
    for (auto i:tree[x]) {
        if (i == p) continue;
        gogo(i,x);
    }
}
signed main(){
    IOS();
    int n,m;
    cin >> n >> m;
    for (int i=0;i<m;++i) {
        int u,v;
        cin >> u >> v;
        u--, v--;
        e[u].eb(v);
        e[v].eb(u);
    }
    dfs(0,0);
    for (int i=0;i<n;++i) {
        for (auto it:e[i]) {
            if (bcc_id[i] != bcc_id[it]) {
                tree[bcc_id[i]].eb(bcc_id[it]);
            }
        }
    }
    gogo(0,0);
    int root = int(max_element(dep,dep + bcc) - dep);
    memset(dep,0,sizeof dep);
    gogo(root,root);
    cout << *max_element(dep,dep+bcc) << endl;
}
