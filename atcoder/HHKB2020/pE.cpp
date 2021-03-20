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
template<class T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }

const ll MAXn=2e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

string s[MAXn];
int l[MAXn][MAXn],r[MAXn][MAXn],u[MAXn][MAXn],d[MAXn][MAXn];
ll add(ll a,ll b){
    ll ret = a + b;
    if (ret >= MOD) ret -= MOD;
    return ret;
}
ll sub(ll a,ll b){
    ll ret = a - b;
    if (ret < 0) ret += MOD;
    return ret;
}
ll mul(ll a,ll b){
    return a * b % MOD;
}
ll fpow(ll a,ll b){
    ll ret = 1;
    while (b) {
        if (b&1) ret = mul(ret,a);
        a = mul(a,a);
        b >>= 1;
    }
    return ret;
}
int main(){
    IOS();
    int n,m;
    cin >> n >> m;
    for (int i=0;i<n;++i) cin >> s[i];
    
    ll k = 0;
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            if (s[i][j] == '#') continue;
            k++;
            if (!i && !j) l[i][j] = d[i][j] = 1;
            else if (!i) {
                d[i][j] = 1;
                l[i][j] = l[i][j-1] + 1;
            }
            else if (!j) {
                l[i][j] = 1;
                d[i][j] = d[i-1][j]+1;
            }
            else {
                l[i][j] = l[i][j-1] + 1, d[i][j] = d[i-1][j] + 1;
            }
        }
    }
    for (int i=n-1;i>=0;--i) {
        for (int j=m-1;j>=0;--j) {
            if (s[i][j] == '#') continue;
            if (i == n-1 && j == m-1) r[i][j] = u[i][j] = 1;
            else if (i == n-1) {
                u[i][j] = 1;
                r[i][j] = r[i][j+1] + 1;
            }
            else if (j == m-1) {
                u[i][j] = u[i+1][j]+1;
                r[i][j] = 1;
            }
            else {
                r[i][j] = r[i][j+1]+1;
                u[i][j] = u[i+1][j]+1;
            }
        }
    }
    ll ans = 0;
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            if (s[i][j] == '#') continue;
            ll tmp = l[i][j]+r[i][j]+u[i][j]+d[i][j] - 3;
            debug(tmp);
            ans = add(ans,mul(sub(fpow(2,tmp),1),fpow(2,k-tmp)));
        }
    }
    cout << ans << endl;
}
