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

const ll MAXN=11,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

string g[MAXN];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
void chr(int &d) {
    d = (d + 1) % 4;
}
void chl(int &d) {
    d = (d + 3) % 4;
}
bool chk(int x, int y){
    return x < 0 || x >= 8 || y < 0 || y >= 8;
}
signed main(){
    IOS();
    pii dia;
    for (int i=0;i<8;++i) {
        cin >> g[i];
        for (int j=0;j<8;++j) {
            if (g[i][j] == 'D') dia = pii(i,j);
        }
    }     
    string s;
    cin >> s;
    int dir = 0, fg = true;
    pii loc = pii(7,0);
    for (int i=0;i<SZ(s);++i) {
        debug(loc);
        if (s[i] == 'F') {
            g[loc.X][loc.Y] = '.';
            loc.X += dx[dir], loc.Y += dy[dir];
            if (chk(loc.X, loc.Y) || g[loc.X][loc.Y] == 'I' || g[loc.X][loc.Y] == 'C') {
                fg = false;
                break;
            }
            g[loc.X][loc.Y] = 'T';
        }
        else if (s[i] == 'R') {
            chr(dir);
        }
        else if (s[i] == 'L') {
            chl(dir);
        }
        else if (s[i] == 'X') {
            int tx = loc.X + dx[dir], ty = loc.Y + dy[dir];
            if (chk(tx, ty) || g[tx][ty] != 'I') {
                fg = false;
                break;
            }
            g[tx][ty] = '.';
        }
        else {
            fg = false;
            break;
        }
    }
    if (!fg || loc != dia) cout << "Bug!" << endl; 
    else cout << "Diamond!" << endl;
}
