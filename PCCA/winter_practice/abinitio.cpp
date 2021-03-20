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

const ll MAXN=4e3+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int n,m,q;
short e[2][MAXN][MAXN];
int r,c;
pll gt(int x){
    ll ret = 0, cur = 1, cnt = 0;
    for (int i=0;i<n;++i) {
        if (i == x) continue;
        if (!c) {
            if (e[r][x][i] == 1) {
                cnt++;
                ret = (ret + i * cur) % MOD;
                cur = cur * 7 % MOD;
            }
        }
        else {
            if (e[r][x][i] == 0) {
                cnt++;
                ret = (ret + i * cur) % MOD;
                cur = cur * 7 % MOD;
            }
        }
    }
    return pll(cnt,ret);
}
void addedge(int x,int y){
    e[r][x][y] = 1, e[!r][y][x] = 1;
}
signed main(){
    IOS();
    cin >> n >> m >> q;
    for (int i=0;i<m;++i) {
        int u,v;
        cin >> u >> v;
        addedge(u,v);
    }
    while (q--) {
        debug("ALIVE");
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            if (c) {
                for (int i=0;i<n;++i) {
                    e[r][n][i] = 1, e[r][i][n] = 1;
                    e[!r][i][n] = 1, e[!r][n][i] = 1;
                }
            }
            n++;
        }
        else if (cmd == 2) {
            int u,v;
            cin >> u >> v;
            if (!c) addedge(u,v);
            else {
                e[r][u][v] = 0;
                e[!r][v][u] = 0;
            }
        }
        else if (cmd == 3) {
            int x;
            cin >> x;
            if (!c) {
                for (int i=0;i<n;++i) {
                    if (i == x) continue;
                    e[r][x][i] = 0, e[!r][i][x] = 0;
                    e[r][i][x] = 0, e[!r][x][i] = 0;
                }
            }
            else {
                for (int i=0;i<n;++i) {
                    if (i == x) continue;
                    e[r][x][i] = 1, e[!r][i][x] = 1;
                    e[r][i][x] = 1, e[!r][x][i] = 1;
                }
            }
        }
        else if (cmd == 4) {
            int u,v;
            cin >> u >> v;
            if (!c) {
                e[r][u][v] = 0;
                e[!r][v][u] = 0;
            }
            else {
                e[r][u][v] = 1;
                e[!r][v][u] = 1;
            }
        }
        else if (cmd == 5) {
            r = 1 - r;
        }
        else {
            c = 1 - c;
        }
    }

    cout << n << endl;
    for (int i=0;i<n;++i) {
        pll ans = gt(i);
        cout << ans.X << ' ' << ans.Y << endl;
    }
}

