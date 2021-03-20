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

const ll MAXN=2e5+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;
const double eps = 1e-6;

using pdd = pair<long double,long double>;
pdd operator + (const pdd &a, const pdd &b){
    return pdd(a.X + b.X, a.Y + b.Y);
}
pdd operator - (const pdd &a, const pdd &b){
    return pdd(a.X - b.X, a.Y - b.Y);
}
pdd operator / (const pdd &a, const int &b){
    return pdd(a.X/b, a.Y/b);
}
pdd dp[MAXN], sum[MAXN];
bool ok[MAXN];
int main(){
    IOS();
    int n,m,k;
    cin >> n >> m >> k;
    for (int i=0;i<k;++i) {
        int x;
        cin >> x;
        ok[x] = true;
    }

    for (int i=n-1;i>=0;--i) {
        if (ok[i]) dp[i] = pdd(1.0,0.0);
        else dp[i] = (sum[i+1] - sum[i+m+1]) / m + pdd(0.0,1.0);
        sum[i] = sum[i+1] + dp[i];
    }
    if (fabs(1 - dp[0].X) < eps) cout << -1 << endl;
    else cout << fixed << setprecision(4) << dp[0].Y / (1.0 - dp[0].X) << endl;
}
