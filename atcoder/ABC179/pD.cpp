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

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=998244353;
const ll INF=0x3f3f3f3f;

ll dp[MAXn],sum[MAXn];
ii d[MAXn];
ll add(ll x,ll y){
    ll ret = x + y;
    if (ret >= MOD) ret -= MOD;
    return ret;
}
ll sub(ll a,ll b){
    ll ret = a - b;
    if (ret < 0) ret += MOD;
    return ret;
}
int main(){
    IOS();
    ll n,k;
    cin >> n >> k;
    for (int i=0;i<k;++i) {
        cin >> d[i].X >> d[i].Y;
    }
    sort(d,d+k);
    
    dp[1] = 1;
    sum[1] = 1;
    for (int i=2;i<=n;++i) sum[i] = 1;
    for (ll i=2;i<=n;++i) {
        for (ll j=0;j<k;++j) {
            debug(i);
            ll r = i-d[j].X, l = max(0LL,i-d[j].Y-1);
            if (r < 0) break;
            debug(l,r);
            dp[i] = add(dp[i],sub(sum[r],sum[l]));
        }
        sum[i] = add(sum[i-1],dp[i]);
    }
    cout << dp[n] << endl;
}
