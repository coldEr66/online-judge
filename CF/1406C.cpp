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

int n;
vector<int> e[MAXn];
int sz[MAXn],dp[MAXn];
int leaf = -1,fa = -1;
void dfs(int x,int p){
    sz[x] = 1;
    for (auto i:e[x]) {
        if (i == p) continue;
        dfs(i,x);
        sz[x] += sz[i];
        dp[x] = max(dp[x],sz[i]);
    }
    if (x != p) dp[x] = max(dp[x],n-sz[x]);
}
void go(int x,int p){
    if (SZ(e[x]) == 1) leaf = x, fa = p;;
    for (auto i:e[x]) {
        if (i == p) continue;
        go(i,x);
    }
}
int main(){
    IOS();
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        leaf = -1, fa = -1;
        for (int i=0;i<n;++i) {
            e[i].clear();
            dp[i] = 0;
            sz[i] = 0;
        }
        for (int i=0;i<n-1;++i) {
            int u,v;
            cin >> u >> v;
            u--, v--;
            e[u].eb(v);
            e[v].eb(u);
        }

        dfs(0,0);
        int mn = *min_element(dp,dp+n);
        int root = -1, rt2 = -1;
        bool fg = true;
        for (int i=0;i<n;++i) {
            if (mn == dp[i]) {
                if (root == -1) {
                    root = i;
                }
                else {
                    rt2 = i;
                    fg = false;
                }
            }
        }
        debug(root,rt2);
        if (fg) {
            cout << 1 << ' ' << e[0][0]+1 << endl;
            cout << 1 << ' ' << e[0][0]+1 << endl;
        }
        else {
            go(root,rt2);
            cout << fa+1 << ' ' << leaf+1 << endl;
            cout << leaf+1 << ' ' <<  rt2+1 << endl;
        }
    }
}
