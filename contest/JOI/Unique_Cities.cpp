#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
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
    fprintf(stderr,"LINE: %d (%s) = ",__LINE__,#__VA_ARGS__);\
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
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int c[MAXn];
vector<int> e[MAXn];
int son[MAXn],dep[MAXn],mx[MAXn];
vector<int> stk;
int ans[MAXn],cnt;
int col[MAXn];
void gtDia(int x,int p){
    dep[x] = dep[p] + 1;
    for (auto i:e[x]) {
        if (i == p) continue;
        gtDia(i,x);
    }
}
void stk_push(int x){
    col[c[x]]++;
    cnt += (col[c[x]] == 1);
    stk.eb(x);
}
void stk_pop(){
    int cur = stk.back();
    stk.pop_back();
    col[c[cur]]--;
    cnt -= (col[c[cur]] == 0);
    debug(cnt,stk);
}
void dfs1(int x,int p){
    dep[x] = dep[p] + 1;
    son[x] = mx[x] = 0;
    for (auto i:e[x]) {
        if (i == p) continue;
        dfs1(i,x);
        if (mx[i] > mx[son[x]]) son[x] = i;
    }
    mx[x] = mx[son[x]] + 1;
}
void dfs2(int x,int p){
    if (!son[x]) {
        ans[x] = max(ans[x],cnt);
        return;
    }
    int mxdep = 0;
    for (auto i:e[x]) {
        if (i == p || i == son[x]) continue;
        mxdep = max(mxdep,mx[i]);
    }
    while (SZ(stk) && dep[stk.back()] >= dep[x] - mxdep) stk_pop();
    stk_push(x);
    dfs2(son[x],x);

    for (auto i:e[x]) {
        if (i == p || i == son[x]) continue;
        while (SZ(stk) && dep[stk.back()] >= dep[x] - mx[son[x]]) stk_pop();
        stk_push(x);
        dfs2(i,x);
    }
    while (SZ(stk) && dep[stk.back()] >= dep[x] - mx[son[x]]) stk_pop();
    ans[x] = max(ans[x],cnt);
}
int main(){
    IOS();
    int n,m;
    cin >> n >> m;
    REP (i,n-1) {
        int u,v;
        cin >> u >> v;
        e[u].eb(v);
        e[v].eb(u);
    }
    REP1 (i,n) cin >> c[i];

    gtDia(1,1);
    int S = 0,T = 0;
    REP1 (i,n) {
        if (S == 0) S = i;
        else if (dep[S] < dep[i]) S = i;
    }
    gtDia(S,S);
    REP1 (i,n) {
        if (T == 0) T = i;
        else if (dep[T] < dep[i]) T = i;
    }
    debug(S,T);

    dfs1(S,S);
    dfs2(S,S);
    pary(son+1,son+n+1);
    dfs1(T,T);
    dfs2(T,T);
    pary(son+1,son+n+1);

    REP1 (i,n) cout << ans[i] << endl;
}
