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

const ll MAXN=2e3+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int n,m;
string s[MAXN];
int dis[MAXN][MAXN];
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
vector<pii> pos[30];
bitset<MAXN> inq[MAXN];
bool chk(int x,int y){
    return x < 0 || x >= n || y < 0 || y >= m;
}
bool isalp(char c){
    return c >= 'a' && c <= 'z';
}
signed main(){
    IOS();
    cin >> n >> m;
    for (int i=0;i<n;++i) cin >> s[i];
    RST(dis,INF);

    queue<pii> q;
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            if (s[i][j] == 'S') {
                q.emplace(i,j);
                dis[i][j] = 0;
                inq[i][j] = true;
            }
            if (isalp(s[i][j])) pos[s[i][j] - 'a'].eb(i,j);
        }
    }
    while (SZ(q)) {
        pii cur = q.front();
        q.pop();
        inq[cur.X][cur.Y] = false;
        if (s[cur.X][cur.Y] == 'G') {
            cout << dis[cur.X][cur.Y] << endl;
            return 0;
        }
        for (int i=0;i<4;++i) {
            int tx = cur.X + dx[i], ty = cur.Y + dy[i];
            if (chk(tx,ty) || s[tx][ty] == '#') continue;
            if (dis[tx][ty] > dis[cur.X][cur.Y] + 1 && !inq[tx][ty]) {
                dis[tx][ty] = dis[cur.X][cur.Y] + 1;
                q.emplace(tx,ty);
                inq[tx][ty] = true;
            }
        }
        char x = s[cur.X][cur.Y];
        if (isalp(x)) {
            while (SZ(pos[x-'a'])) {
                pii i = pos[x-'a'].back();
                pos[x-'a'].pop_back();
                if (dis[i.X][i.Y] > dis[cur.X][cur.Y] + 1 && !inq[i.X][i.Y]) {
                    dis[i.X][i.Y] = dis[cur.X][cur.Y] + 1;
                    q.emplace(i.X,i.Y);
                    inq[i.X][i.Y] = true;
                }
            }
        }
    }
    cout << -1 << endl;
}
