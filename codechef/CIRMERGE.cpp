#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
#define REP(i,n) for(int i=0;i<n;i++)
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

const ll MAXn=4e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

ll dp[MAXn][MAXn],sum[MAXn][MAXn];
ll d[MAXn];
int main(){
    IOS();
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        REP (i,n) cin >> d[i];

        REP (i,n) REP (j,n) dp[i][j] = INF;
        REP (i,n) REP (j,n) {
            ll tmp = 0;
            for (ll k=i;k!=j;) {
                debug(k);
                tmp += d[k];
                k++;
                if (k >= n) k -= n;
            }
            tmp += d[j];
            sum[i][j] = tmp;
        }
        REP (i,n) dp[i][i] = 0;

        REP1 (len,n-1) REP (l,n) {
            ll r = l+len;
            if (r >= n) r -= n;
            ll tmp = INF;
            for (ll j=l;j!=r;) {
                ll nxt = j+1;
                if (nxt >= n) nxt -= n;
                tmp = min(tmp,sum[l][j] + sum[nxt][r] + dp[l][j] + dp[nxt][r]);
                j++;
                if (j >= n) j -= n;
            }
            ll pre = r-1;
            if (pre < 0) pre = n-1;
            tmp = min(tmp,sum[l][pre] + sum[r][r] + dp[l][pre] + dp[r][r]);
            dp[l][r] = tmp;
        }

        ll ans = INF;
        REP (l,n) {
            ll r = l+n-1;
            if (r >= n) r -= n;
            ans = min(ans,dp[l][r]);
        }
        cout << ans << endl;
    }
}