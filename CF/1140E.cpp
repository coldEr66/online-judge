#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
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

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=998244353;
const ll INF=0x3f3f3f3f;

ll n,k;
ll d[MAXn];
ll dp[MAXn][2];
vector<ll> v[2];
ll add(ll x,ll y){
    ll ret = x + y;
    if (ret >= MOD) ret -= MOD;
    return ret;
}
ll mul(ll x,ll y){
    return (x*y)%MOD;
}
ll fpow(ll x,ll a){
    ll ret = 1, base = x;
    while (a) {
        if (a&1) ret = mul(ret,base);
        base = mul(base,base);
        a >>= 1;
    }
    return ret;
}
void build(){
    dp[0][0] = 0;
    dp[0][1] = 1;
    REP1 (i,n) {
        dp[i][0] = mul(dp[i-1][1],k-1);
        dp[i][1] = add(mul(dp[i-1][1],k-2),dp[i-1][0]);
    }
}
int main(){
    IOS();
    cin >> n >> k;
    REP (i,n) {
        cin >> d[i];
        v[i&1].eb(d[i]);
    }
    build();
    REP (I,2) REP (i,SZ(v[I])-1) if (v[I][i] != -1 && v[I][i] == v[I][i+1]) return cout << 0 << endl,0;
    ll ans = 1;
    REP (I,2) {
        REP (i,SZ(v[I])) {
            if (v[I][i] != -1) continue;
            ll idx = i;
            while (idx < SZ(v[I]) && v[I][idx] == v[I][i]) idx++;
            if (i == 0 && idx == SZ(v[I])) ans = mul(ans,mul(k,fpow(k-1,idx-i-1)));
            else if (i == 0 || idx == SZ(v[I])) ans = mul(ans,fpow(k-1,idx-i));
            else {
                if (v[I][i-1] == v[I][idx]) ans = mul(ans,dp[idx-i][0]);
                else ans = mul(ans,dp[idx-i][1]);
            }
            debug(i,idx);
            i = idx-1;
        }
    }
    cout << ans << endl;
}
