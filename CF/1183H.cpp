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

const ll MAXn=1e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=1e12+5;

ll dp[MAXn][MAXn];
ll t[MAXn][30];
vector<ll> v;
int main(){
    IOS();
    ll n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    RST(t,-1);
    REP1 (i,n) REP (j,26) {
        if (s[i-1] == 'a'+j) t[i][j] = i-1;
        else t[i][j] = t[i-1][j];
    }
    REP (i,n) dp[i][1] = 1;
    REP1 (i,n-1) for (ll j=2;j<=i+1;j++) {
        ll tmp = 0;
        REP (c,26) {
            if (t[i][c] != -1) tmp = min(INF,tmp+dp[t[i][c]][j-1]);
        }
        dp[i][j] = tmp;
    }

    REP1 (j,n) {
        ll tmp = 0;
        REP (c,26) {
            if (t[n][c] != -1) tmp = min(INF,tmp+dp[t[n][c]][j]);
        }
        v.eb(tmp);
    }

    ll ans = 0;
    for (ll i=n-1;i>=0;i--) {
        if (k - v[i] >= 0) {
            ans += v[i] * (n-i-1);
            k -= v[i];
        }
        else {
            ans += k * (n-i-1);
            k = 0;
            break;
        }
    }
    
    if (k == 1) cout << ans + n << endl;
    else if (k) cout << -1 << endl;
    else cout << ans << endl;
}
