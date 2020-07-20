#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
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

const ll MAXn=5e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

vector<ii> e[MAXn];
int w[MAXn];
vector<iii> need;
bool fg;
bool dfs(int x,int p,int tg,int k){
    if (x == tg) return 1;
    int ret = 0;
    for (auto i:e[x]) {
        if (i.X == p) continue;
        bool tmp = dfs(i.X,x,tg,k);
        ret |= tmp;
        if (tmp) {
            int id = i.Y;
            if (w[id] <= k) {
                w[id] = k;
                fg = 1;
            }
        }
    }
    return ret;
}
int main(){
    IOS();
    int n;
    cin >> n;
    REP (i,n-1) {
        int u,v;
        cin >> u >> v;
        u--, v--;
        e[u].eb(v,i);
        e[v].eb(u,i);
        w[i] = 1;
    }
    int m;
    cin >> m;
    REP (i,m) {
        int u,v,k;
        cin >> u >> v >> k;
        u--, v--;
        need.eb(k,ii(u,v));
    }
    sort(ALL(need),greater<iii>());

    REP (i,m) {
        int u = need[i].Y.X, v = need[i].Y.Y;
        fg = 0;
        dfs(u,u,v,need[i].X);
        if (!fg) {
            return cout << -1 << endl,0;
        }
    }
    REP (i,n-1) cout << w[i] << " \n"[i==n-2];
}
