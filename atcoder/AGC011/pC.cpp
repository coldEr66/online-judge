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

ll cnt[3];
int col[MAXn];
vector<int> e[MAXn];
bool fg;
ll sq(ll x){
    return x * x;
}
void dfs(int x,int c){
    col[x] = c;
    for (auto i:e[x]) {
        if (col[i] != -1) {
            if ((col[i] ^ col[x]) == 0) fg = false;
        }
        else dfs(i,c^1);
    }
}
int main(){
    IOS();
    int n,m;
    cin >> n >> m;
    REP (i,m) {
        int u,v;
        cin >> u >> v;
        u--, v--;
        e[u].eb(v);
        e[v].eb(u);
    }
    REP (i,n) if (SZ(e[i]) == 0) cnt[0]++;
    RST(col,-1);
    REP (i,n) {
        if (SZ(e[i]) != 0) {
            if (col[i] == -1) {
                fg = true;
                dfs(i,0);
                if (fg) cnt[1]++;
                else cnt[2]++;
            }
        }
    }
    ll ans = 2 * cnt[0] * n - sq(cnt[0]) + 2 * sq(cnt[1]) + 2 * cnt[1] * cnt[2] + sq(cnt[2]);
    cout << ans << endl;
}
