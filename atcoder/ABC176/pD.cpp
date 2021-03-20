#include <bits/stdc++.h>
#pragma GCC optimize ("unroll-loops")
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

const ll MAXn=1005,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int n,m;
string s[MAXn];
int dis[MAXn][MAXn];
bool vis[MAXn][MAXn];
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
bool chk(int x,int y){
    if (x < 0 || x >= n || y < 0 || y >= m) return true;
    if (s[x][y] == '#') return true;
    return false;
}
int main(){
    IOS();
    cin >> n >> m;
    int stx,sty;
    cin >> stx >> sty;
    stx--, sty--;
    int dstx,dsty;
    cin >> dstx >> dsty;
    dstx--, dsty--;
    for (int i=0;i<n;++i) cin >> s[i];
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            dis[i][j] = INF;
        }
    }

    deque<ii> q;
    dis[stx][sty] = 0;
    q.eb(stx,sty);
    while (SZ(q)) {
        ii cur = q.front();
        q.pop_front();
        if (vis[cur.X][cur.Y]) continue;
        debug(cur);
        debug(dis[cur.X][cur.Y]);
        vis[cur.X][cur.Y] = true;
        for (int tp=0;tp<4;tp++) {
            int tx = cur.X + dx[tp], ty = cur.Y + dy[tp];
            if (chk(tx,ty) || vis[tx][ty]) continue;
            if (dis[tx][ty] > dis[cur.X][cur.Y]) {
                dis[tx][ty] = dis[cur.X][cur.Y];
                q.emplace_front(tx,ty);
            }
        }

        for (int i=-2;i<=2;++i) {
            for (int j=-2;j<=2;++j) {
                int tx = cur.X + i, ty = cur.Y + j;
                if (chk(tx,ty) || vis[tx][ty]) continue;
                if (dis[tx][ty] > dis[cur.X][cur.Y] + 1) {
                    dis[tx][ty] = dis[cur.X][cur.Y] + 1;
                    q.emplace_back(tx,ty);
                }
            }
        }
    }
    if (dis[dstx][dsty] == INF) cout << -1 << endl;
    else cout << dis[dstx][dsty] << endl;
}

