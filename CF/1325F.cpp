#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

vector<int> e[MAXn];
vector<int> cycle;
bool choose[MAXn],vis[MAXn],ok[MAXn];
int dep[MAXn],fa[MAXn];
int sq;
void dfs(int x,int p){
    dep[x] = dep[p] + 1;
    fa[x] = p;
    vis[x] = true;
    int cnt = 0, tg = -1;
    for (auto i:e[x]) {
        if (vis[i]) {
            cnt++;
            if (tg == -1 || dep[i] < dep[tg]) tg = i;
        }
    }
    if (!SZ(cycle) && cnt >= sq-1) {
        int cur = x;
        while (cur != tg) {
            cycle.eb(cur);
            cur = fa[cur];
        }
        cycle.eb(tg);
    }
    if (cnt < sq-1 && ok[x]) {
        choose[x] = true;
    }
    for (auto i:e[x]) {
        if (vis[i]) continue;
        dfs(i,x);
        if (choose[i]) choose[x] = false;
    }
    if (choose[x]) {
        for (auto i:e[x]) {
            ok[i] = choose[i] = false;
        }
    }
}
int main(){
    IOS();
    int n,m;
    cin >> n >> m;
    for (int i=0;i<m;++i) {
        int u,v;
        cin >> u >> v;
        e[u].eb(v);
        e[v].eb(u);
    }

    while (sq * sq < n) sq++;
    RST(ok,1);
    dfs(1,1);
    if (SZ(cycle)) {
        cout << 2 << endl;
        cout << SZ(cycle) << endl;
        for (int i=0;i<SZ(cycle);++i) {
            cout << cycle[i] << " \n"[i==SZ(cycle)-1];
        }
    }
    else {
        cout << 1 << endl;
        for (int i=1;i<=n && sq;++i) {
            if (choose[i]) {
                cout << i << " \n"[sq == 1];
                sq--;
            }
        }
    }
}
