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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll mod=MOD-1;
const ll INF=0x3f3f3f3f;

vector<ll> pr;
struct mat{
    ll m[3][3];
    void init() {
        REP (i,3) REP (j,3) {
            if (i == j) m[i][j] = 1;
            else m[i][j] = 0;
        }
    }
    mat operator * (const mat &a) {
        mat ret;
        REP (i,3) REP (j,3) ret.m[i][j] = 0;
        REP (i,3) REP (j,3) REP (k,3) {
            ret.m[i][j] = (ret.m[i][j] + m[i][k] * a.m[k][j] % mod) % mod;
        }
        return ret;
    }
} mm;
void mul(ll &a,ll b){
    a = (a*b)%MOD;
}
ll fpow(ll a,ll b){
    ll ret = 1;
    while (b) {
        if (b&1) mul(ret,a);
        mul(a,a);
        b >>= 1;
    }
    return ret;
}
mat mtfpow(mat a,ll b){
    mat ret;
    ret.init();
    while (b) {
        if (b&1) ret = ret * a;
        a = a * a;
        b >>= 1;
    }
    return ret;
}
void cal(ll x){
    for (ll i=2;i<=sqrt(x);i++) {
        if (x%i == 0) {
            pr.eb(i);
            while (x%i == 0) x /= i;
        }
    }
    if (x != 1) pr.eb(x);
}
ll gt(ll x,ll p){
    ll ret = 0;
    while (x % p == 0) {
        ret++;
        x /= p;
    }
    return ret;
}
int main(){
    IOS();
    ll n;
    cin >> n;
    ll f1,f2,f3,c;
    cin >> f1 >> f2 >> f3 >> c;
    debug(pr);

    REP (i,3) REP (j,3) {
        if (i == 0) mm.m[i][j] = 1;
        else if (i == j+1) mm.m[i][j] = 1;
        else mm.m[i][j] = 0;
    }
    mm = mtfpow(mm,n-3);
    REP (i,3) REP (j,3) debug(mm.m[i][j]);
    ll ans = 1;
    f1 = (f1*c)%MOD, f2 = f2*c%MOD*c%MOD, f3 = f3*c%MOD*c%MOD*c%MOD;
    cal(f1), cal(f2), cal(f3);
    sort(ALL(pr));
    pr.resize(unique(ALL(pr))-pr.begin());
    REP (i,SZ(pr)) {
        mat base;
        ll x = gt(f1,pr[i]), y = gt(f2,pr[i]), z = gt(f3,pr[i]);
        REP (j,3) REP (k,3) base.m[j][k] = 0;
        base.m[0][0] = z;
        base.m[1][0] = y;
        base.m[2][0] = x;
        mat tmp = mm * base;
        mul(ans,fpow(pr[i],tmp.m[0][0]));
    }
    cout << ans * fpow(fpow(c,n),MOD-2) % MOD << endl;
}
