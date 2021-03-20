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

const ll MAXN=19,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

bool ok[1<<MAXN];
int dp[1<<MAXN];
bitset<MAXN> bs[MAXN];
signed main(){
    IOS();
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) bs[i][i] = 1;
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        a--, b--;
        bs[a][b] = 1;
        bs[b][a] = 1;
    }
    for (int I = 0; I < (1<<n); ++I) {
        dp[I] = INF;
        bitset<MAXN> tmp;
        for (int i = 0; i < n; ++i) {
            if ((1<<i) & I) tmp[i] = 1;
        }
        ok[I] = 1;
        for (int i = 0; i < n; ++i) {
            if ((1<<i) & I) {
                ok[I] &= ((tmp & bs[i]) == tmp);
            }
        }
    }
    dp[0] = 0;
    for (int I = 1; I < (1<<n); ++I) {
        for (int J = I; J; J = (J-1) & I) {
            if (ok[J]) {
                dp[I] = min(dp[I], dp[I^J] + 1);
            }
        }
    }
    cout << dp[(1<<n)-1] << endl;
}
