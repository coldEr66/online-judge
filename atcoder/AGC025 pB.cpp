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

const ll MAXn=3e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=998244353;
const ll INF=0x3f3f3f3f;

ll fac[MAXn],inv[MAXn];
ll add(ll a,ll b){
    ll ret = a+b;
    if (ret >= MOD) ret -= MOD;
    return ret;
}
ll mul(ll a,ll b){
    return a*b%MOD;
}
ll inverse(ll a){
    if (a == 1) return a;
    return mul((MOD - MOD/a),inverse(MOD%a));
}
ll C(ll a,ll b){
    return mul(mul(fac[a],inv[b]),inv[a-b]);
}
int main(){
    IOS();
    ll n,a,b,k;
    cin >> n >> a >> b >> k;
    fac[0] = inv[0] = 1;
    REP1 (i,MAXn-1) {
        fac[i] = mul(fac[i-1],i);
        inv[i] = inverse(fac[i]);
    }
    ll ans = 0;
    REP (i,MAXn*3) {
        ll tmp = k - i * a;
        if (tmp < 0 || i > n) break;
        if (tmp % b != 0) continue;
        ll j = tmp / b;
        if (j > n) continue;
        ans = add(ans,mul(C(n,i),C(n,j)));
    }
    cout << ans << endl;
}
