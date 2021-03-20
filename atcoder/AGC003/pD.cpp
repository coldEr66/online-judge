#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (ll)a.size()
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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll d[MAXn];
bool isp[MAXn];
vector<ll> prime;
ll mul[MAXn],dv[MAXn];
map<ll,ll> mp1,mp2,vis;
map<ll,ll> pr;
set<ll> st;
void build_prime(){
    for (ll i=2;i<MAXn;++i) {
        if (!isp[i]) {
            prime.eb(i);
            st.insert(i * i);
        }
        for (ll j=0;j<SZ(prime) && prime[j] * i < MAXn;++j) {
            isp[prime[j] * i] = true;
            if (i % prime[j] == 0) break;
        }
    }
}
ll cb(ll x){
    return x * x * x;
}
ll sq(ll x){
    return x * x;
}
int main(){
    IOS();
    build_prime();
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i=0;i<n;++i) {
        cin >> d[i];
        ll cur1 = 1, cur2 = 1;
        for (ll j=0;j<SZ(prime) && prime[j] < 2200;++j) {
            if (d[i] % prime[j] == 0) {
                ll tmp = cb(prime[j]);
                while (d[i] % tmp == 0) d[i] /= tmp;
                ll cnt1 = 1;
                while (d[i] % prime[j] == 0) {
                    d[i] /= prime[j];
                    cnt1 *= prime[j];
                    tmp /= prime[j];
                }
                if (tmp == cb(prime[j])) tmp = 1;
                cur1 *= cnt1, cur2 *= tmp;
            }
        }
        if (d[i] == 1 && cur1 == 1 && cur2 == 1) {
            ans = 1;
            continue;
        }
        dv[i] = cur1 * d[i];
        mul[i] = cur2;
        if (st.count(d[i])) {
            mul[i] *= (ll)sqrt(d[i]);
        }
        else {
            mul[i] *= sq(d[i]);
        }
        debug(dv[i],mul[i],i);
        mp1[dv[i]]++;
        mp2[mul[i]]++;
        pr[dv[i]] = mul[i];
    }
    debug(ans);
    
    for (auto i:mp1) {
        ll cur = i.X;
        debug(cur,i.Y);
        if (vis[cur]) continue;
        ans += max(mp1[cur],mp2[cur]);
        vis[cur] = vis[pr[cur]] = true;
    }
    cout << ans << endl;
}
