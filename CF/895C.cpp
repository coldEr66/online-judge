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

const ll MAXa=72;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int dp[MAXa][1<<19];
int mask[MAXa];
int cnt[MAXa][2];
vector<int> prime;
bool isp[MAXa];
ll add(ll a,ll b){
    ll ret = a + b;
    if (ret >= MOD) ret -= MOD;
    return ret;
}
ll mul(ll a,ll b){
    return a*b%MOD;
}
void build(){
    for (ll i=2;i<MAXa;i++) {
        if (!isp[i]) prime.eb(i);
        for (ll j=0;j<SZ(prime) && i*prime[j]<MAXa;j++) {
            isp[i*prime[j]] = true;
        }
    }
}
int main(){
    IOS();
    ll n;
    cin >> n;
    REP1 (i,MAXa-1) cnt[i][0] = 1;
    REP (i,n) {
        int x;
        cin >> x;
        int tmp = cnt[x][0];
        cnt[x][0] = add(cnt[x][0],cnt[x][1]);
        cnt[x][1] = add(cnt[x][1],tmp);
    }
    build();
    debug(prime);
    REP1 (i,MAXa-1) {
        int cur = i;
        REP (j,SZ(prime)) {
            int tmp = 0;
            if (cur % prime[j] == 0) {
                while (cur % prime[j] == 0) {
                    cur /= prime[j];
                    tmp++;
                }
                debug(i,tmp);
                if (tmp&1) mask[i] |= (1<<j);
            }
        }
    }
    dp[0][0] = 1;
    REP1 (i,MAXa-1) {
        REP (I,(1<<19)) {
            dp[i][I] = add(mul(dp[i-1][I],cnt[i][0]),mul(dp[i-1][I^mask[i]],cnt[i][1]));
        }
    }
    cout << add(dp[MAXa-1][0]-1,MOD) << endl;
}
