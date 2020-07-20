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

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=1e9;

vector<ii> e[MAXn];
vector<ii> ne[MAXn];
int d[MAXn];
int col[MAXn];
int w[MAXn];
int chk[MAXn];
vector<ii> edg;
void dfs(int x,int p){
    for (auto i:ne[x]) {
        int to = i.X;
        if (to == p) continue;
        col[to] = !col[x];
        dfs(to,x);
    }
}
int main(){
    IOS();
    int n,m;
    cin >> n >> m;
    REP (i,n) cin >> d[i];
    REP (i,m) {
        int u,v;
        cin >> u >> v;
        u--, v--;
        e[u].eb(v,i);
        e[v].eb(u,i);
    }
    REP (i,m) w[i] = INF;
    REP (i,n) {
        bool fg = false;
        sort(ALL(e[i]));
        for (auto it:e[i]) {
            int to = it.X;
            if (d[i] >= d[to]) fg = true;
        }
        if (!fg) return cout << -1 << endl,0;
        int cur = -1, curid = -1;
        for (auto it:e[i]) {
            int to = it.X, id = it.Y;
            if (cur == -1) {
                cur = to, curid = id;
            }
            else if (d[cur] > d[to]) {
                cur = to, curid = id;
            }
        }
        w[curid] = d[i];
        ne[i].eb(cur,d[i]);
        ne[cur].eb(i,d[i]);
    }
    REP (i,n) {
        sort(ALL(ne[i]));
        debug(ne[i]);
    }
    RST(col,-1);
    REP (i,n) {
        if (col[i] == -1) {
            col[i] = 0;
            dfs(i,i);
        }
    }
    REP (i,m) if (w[i] == -1) w[i] = INF;
    REP (i,n) {
        if (col[i] == 0) cout << 'W';
        else cout << 'B';
    }
    cout << endl;
    REP (i,m) cout << w[i] << endl;
}
