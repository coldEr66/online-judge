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

const ll MAXn=6005,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int n;
int d[MAXn];
int dp[MAXn][MAXn];
int nxt[MAXn][MAXn];
vector<int> th[MAXn],pos[MAXn];
vector<int> tmp;
int id[MAXn];
int ans;
int chk(int x,int y,int z){
    return (tmp[x] == tmp[y] && tmp[x] == tmp[z]);
}
void upd(int x,int y,int val) {
    dp[x][y] = max(dp[x][y],val);
}
void mod(int x,int y,int v,int w,int z){
    upd(x,v,dp[x][y] + chk(y,w,z));
    upd(x,w,dp[x][y] + chk(y,v,z));
    upd(x,z,dp[x][y] + chk(y,v,w));
    upd(y,v,dp[x][y] + chk(x,w,z));
    upd(y,w,dp[x][y] + chk(x,v,z));
    upd(y,z,dp[x][y] + chk(x,v,w));
    upd(v,w,dp[x][y] + chk(x,y,z));
    upd(v,z,dp[x][y] + chk(x,y,w));
    upd(w,z,dp[x][y] + chk(x,y,v));
    upd(x,y,dp[x][y] + chk(v,w,z));
}
void cal(int x,int y){
    debug(x,y,id[y]);
    if (id[y] == n-1) {
        ans = max(ans,dp[x][y] + chk(x,y,3*n-1));
        return;
    }
    int cur = id[y] + 1;
    mod(x,y,th[cur][0],th[cur][1],th[cur][2]);

    int tx = nxt[tmp[x]][cur], ty = nxt[tmp[y]][cur];
    int idtx = (tx == -1 ?INF:id[tx]);
    int idty = (ty == -1 ?INF:id[ty]);
    cur = min(idtx,idty);
    debug(cur);
    if (cur != INF) {
        if (cur == n) {
            ans = max(ans,dp[x][y] + chk(x,y,3*n-1));
        }
        else {
            mod(x,y,th[cur][0],th[cur][1],th[cur][2]);
        }
    }
}
int main(){
    IOS();
    cin >> n;
    for (int i=0;i<3*n;++i) cin >> d[i];
    
    int cnt = 0, tt = 1;
    tmp.eb(d[0]), tmp.eb(d[1]);
    for (int i=2;i<3*n-1;i+=3) {
        if (d[i] == d[i+1] && d[i] == d[i+2]) {
            cnt++;
        }
        else {
            tt++;
            for (int j=i;j<i+3;++j) {
                tmp.eb(d[j]);
            }
        }
    }
    tmp.eb(d[3*n-1]);
    n = tt;
    debug(n);
    if (n == 1) {
        if (tmp[0] == tmp[1] && tmp[0] == tmp[2]) {
            cout << cnt + 1 << endl;
        }
        else cout << cnt << endl;
        return 0;
    }
    id[0] = id[1] = 0;
    for (int i=2;i<3*n;++i) {
        id[i] = (i+1) / 3;
        th[id[i]].eb(i);
    }
    for (int i=2;i<3*n;++i) {
        pos[tmp[i]].eb(i);
    }
    for (int i=0;i<3*n;++i) {
        for (int j=0;j<3*n;++j) {
            dp[i][j] = -1;
            nxt[i][j] = -1;
        }
    }
    for (int i=1;i<MAXn;++i) {
        if (SZ(pos[i]) == 0) continue;
        for (auto it:pos[i]) {
            debug(it);
            int cur = id[it];
            while (cur != -1 && nxt[i][cur] == -1) {
                nxt[i][cur] = it;
                debug(i,cur,nxt[i][cur],it);
                cur--;
            }
        }
    }

    dp[0][1] = 0;
    for (int i=1;i<3*n;++i) {
        for (int j=0;j<i;++j) {
            if (dp[j][i] != -1) {
                cal(j,i);
            }
        }
    }
    cout << ans + cnt << endl;
}
