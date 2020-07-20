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

const ll MAXn=505,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int n;
int c[MAXn][MAXn];
int in[MAXn][MAXn];
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
bool chk(int x,int y){
    return x < 0 || x >= n || y < 0 || y >= n;
}
void dfs(int x,int y){
    int tmp = c[x][y] + in[x][y];
    REP (i,4) {
        int tx = x + dx[i], ty = y + dy[i];
        if (chk(tx,ty)) continue;
        if (c[tx][ty] > tmp) {
             c[tx][ty] = tmp;
             dfs(tx,ty);
        }
    }
}
int main(){
    IOS();
    cin >> n;
    REP (i,n) REP (j,n) {
        c[i][j] = min({i,j,n-i-1,n-j-1});
        in[i][j] = 1;
        debug(i,j,c[i][j]);
    }
    int ans = 0;
    REP (i,n*n) {
        int cur;
        cin >> cur;
        cur--;
        int x = cur/n, y = cur%n;
        ans += c[x][y];
        in[x][y] = 0;
        dfs(x,y);
        debug(ans);
    }
    cout << ans << endl;
}
