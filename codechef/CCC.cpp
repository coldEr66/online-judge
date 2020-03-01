#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define X first
#define Y second
#define mkp make_pair
#define pb push_back
#define eb emplace_back
#define pob pop_back
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
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
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

const ll MAXn=1e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

ll n,z;
ll d[MAXn];
ll dp[MAXn][MAXn];
lf gt(ll x,ll y,ll t){
    if (d[x] == d[y]) {
        if (dp[x][t] < dp[y][t]) return (lf)INF;
        return (lf)-INF;
    }
    lf ret = lf(lf((dp[x][t]-d[x]*(n+1))-(dp[y][t]-d[y]*(n+1)))/lf(d[x]-d[y]));
    debug(ret);
    return ret;
}
int main(){
    IOS();
    ll t;
    cin >> t;
    while (t--) {
        cin >> n >> z;
        REP1 (i,n) cin >> d[i];
        sort(d+1,d+n+1);

        deque<ll> dq;
        REP1 (i,n) dp[i][0] = INF;
        REP (i,n+1) for (ll j=i+1;j<=n;j++) dp[i][j] = INF;
        dp[0][0] = 0;

        REP1 (j,z) {
            dq.clear();
            REP (i,j) if (dp[i][j-1] != INF) dq.eb(i);
            for (ll i=j;i<=n;i++) {
                debug(SZ(dq));
                while (SZ(dq) > 1) {
                    ll cur = dq.front();
                    dq.pop_front();
                    // debug(gt(cur,dq.front(),j-1));
                    if (gt(cur,dq.front(),j-1) > d[i]) {
                        dq.emplace_front(cur);
                        break;
                    }
                }
                ll bst = dq.front();
                dp[i][j] = dp[bst][j-1] + (d[i]-d[bst]) * (n-i+1);
                debug(bst,dp[i][j],i,j,SZ(dq));

                while (SZ(dq) > 1) {
                    ll cur = dq.back();
                    dq.pop_back();
                    if (gt(dq.back(),cur,j-1) < gt(cur,i,j-1)) {
                        dq.eb(cur);
                        break;
                    }
                }
                dq.eb(i);
            }
        }

        ll ans = INF;
        for (ll i=z;i<=n;i++) ans = min(ans,dp[i][z]);
        assert(ans <= 1e18);
        cout << ans << endl;
    }
}
