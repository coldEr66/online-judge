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

const ll MAXn=18,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int a[MAXn],b[MAXn];
int dp[1<<MAXn][MAXn];
int gt(int pos,int go){
    if ((pos-go)&1) return b[pos];
    return a[pos];
}
int main(){
    IOS();
    int n;
    cin >> n;
    REP (i,n) cin >> a[i];
    REP (i,n) cin >> b[i];
    RST(dp,INF);
    REP (mask,1<<n) {
        int cnt = __builtin_popcount(mask);
        debug(cnt,mask);
        if (!cnt) {
            REP (i,n) dp[1<<i][i] = 0;
            continue;
        }
        REP (i,n) {
            if (mask & (1<<i)) continue;
            REP (j,n) {
                if (dp[mask][j] == INF) continue;
                int iv = gt(i,cnt);
                int jv = gt(j,cnt-1);
                if (iv >= jv) {
                    int cost = 0;
                    for (int k=i+1;k<n;k++) if (mask & (1<<k)) cost++;
                    dp[mask|(1<<i)][i] = min(dp[mask|(1<<i)][i],dp[mask][j] + cost);
                }
            }
        }
    }
    int ans = INF;
    REP (i,n) ans = min(ans,dp[(1<<n)-1][i]);
    if (ans >= INF) cout << -1 << endl;
    else cout << ans << endl;
}
