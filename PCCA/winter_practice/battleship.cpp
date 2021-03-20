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

const ll MAXN=35,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

string g1[MAXN], g2[MAXN];
int c1, c2, win;
bool fg;
void chk(){
    if (c1 == 0 && c2 == 0) {
        win = -1;
        fg = true;
    }
    else if (c1 == 0) {
        win = 1;
        fg = true;
    }
    else if (c2 == 0) {
        win = 0;
        fg = true;
    }
}
signed main(){
    IOS();
    int t;
    cin >> t;
    while (t--) {
        int n,m,k;
        cin >> n >> m >> k;
        c1 = 0, c2 = 0;
        for (int i=0;i<m;++i) {
            cin >> g1[i];
            for (int j=0;j<n;++j) 
                if (g1[i][j] == '#') c1++;
        }
        for (int i=0;i<m;++i) {
            cin >> g2[i];
            for (int j=0;j<n;++j)
                if (g2[i][j] == '#') c2++;
        }
        bool turn = 0;
        fg = false;
        win = -1;
        for (int i=0;i<k;++i) {
            debug(c1,c2);
            int x,y;
            cin >> x >> y;
            y = m-y-1;
            if (fg) continue;
            if (!turn) {
                if (g2[y][x] == '#') {
                    g2[y][x] = '_';
                    c2--;
                    if (c2 == 0) turn = !turn;
                }
                else {
                    turn = !turn;
                }
            }
            else {
                if (g1[y][x] == '#') {
                    g1[y][x] = '_';
                    c1--;
                    if (c1 == 0) {
                        turn = !turn;
                        chk();
                    }
                }
                else {
                    turn = !turn;
                    chk();
                }
            }
        }
        if (!fg) chk();
        if (win == -1) cout << "draw" << endl;
        else if (win == 0) cout << "player one wins" << endl;
        else cout << "player two wins" << endl;
    }
}
