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
template<class T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }

const ll MAXN=2e5+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

vector<int> dia,e[MAXN];
int len;
int dep[MAXN],fa[MAXN];
bool ok[MAXN];
vector<pair<pii,int>> ans;
ll cost;
void dfs(int x,int p){
    if (x != p) dep[x] = dep[p] + 1;
    fa[x] = p;
    for (auto i:e[x]) {
        if (i == p) continue;
        dfs(i,x);
    }
}
void gogo(int x,int p,ll d,int r){
    if (x != p) {
        debug(x,p,d,r);
        ans.eb(pii(x,r),x);
        cost += d;
    }
    for (auto i:e[x]) {
        if (i == p || ok[i]) continue;
        gogo(i,x,d+1,r);
    }
}
signed main(){
    IOS();
    ll n;
    cin >> n;
    for (int i=0;i<n-1;++i) {
        int u,v;
        cin >> u >> v;
        u--, v--;
        e[u].eb(v);
        e[v].eb(u);
    }
    dfs(0,0);
    int root = max_element(dep,dep+n) - dep;
    len = dep[root];
    memset(dep,0,sizeof dep);
    memset(fa,-1,sizeof fa);
    dfs(root,root);

    {
        int cur = max_element(dep,dep+n) - dep;
        for (;cur != root;cur = fa[cur]) {
            dia.eb(cur);
        }
        dia.eb(root);
        debug(dia);
    }

    int cenid = SZ(dia) / 2;
    int l,r;
    l = r = cenid;
    for (int i=0;i<SZ(dia)-1;++i) {
        ok[dia[i]] = true;
        if (i&1) {
            ++r;
            debug(dia[l],dia[r]);
            ans.eb(pii(dia[l],dia[r]),dia[r]);
        }
        else {
            --l;
            debug(dia[l],dia[r]);
            ans.eb(pii(dia[l],dia[r]),dia[l]);
        }
        ll tmp = dep[dia[l]] - dep[dia[r]];
        cost += tmp;
    }
    ok[dia.back()] = true;

    for (int i=0;i<SZ(dia);++i) {
        int cur = dia[i];
        int R = (i < cenid ?dia.back():dia[0]);
        int tlen = (i < cenid ?dep[cur]-dep[dia.back()]:dep[dia[0]]-dep[cur]);
        gogo(cur,cur,tlen,R);
    }

    cout << cost << endl;
    for (int i=SZ(ans)-1;i>=0;--i) {
        cout << ans[i].X.X + 1 << ' ' << ans[i].X.Y + 1 << ' ' << ans[i].Y + 1 << endl;
    }
}
