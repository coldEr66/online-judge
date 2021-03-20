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

const ll MAXN=1<<19,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;
const ll R = 2;
const ll P = 2e5+3;

struct FFT {
    using lf = complex<double>;
    const double PI = acos(-1);
    lf w[MAXN]; // MAXN must be 2^k
    void init() {
        for (int i=0;i<MAXN;++i) {
            double arg = 2 * PI * i / MAXN;
            w[i] = lf(cos(arg),sin(arg));
        }
    }
    void rev_bit(lf *a,int n) {
        int i=0;
        for (int j=1;j<n-1;++j) {
            for (int k = n>>1;(i ^= k) < k;k >>= 1);
            if (j < i) swap(a[i],a[j]);
        }
    }
    void trans(lf *a,int n,bool inv = false) {
        rev_bit(a,n);
        for (int len = 2;len <= n;len <<= 1) {
            int dx = MAXN/len, dl = len>>1;
            for (int i=0;i<n;i+=len) {
                for (int j=i, x=0;j<i+dl;++j, x+=dx) {
                    lf tmp = a[j + dl] * w[x];
                    a[j + dl] = a[j] - tmp;
                    a[j] += tmp;
                }
            }
        }
        if (inv) {
            reverse(a+1,a+n);
            for (int i=0;i<n;++i) a[i] /= n;
        }
    }
} fft;
ll pr[MAXN],mp[MAXN];
complex<double> a[MAXN];
signed main(){
    IOS();
    ll n;
    cin >> n;
    ll cur = 1;
    ll ans = 0;
    for (int i=0;i<P-1;++i) {
        pr[i] = cur;
        mp[cur] = i;
        cur = cur * R % P;
    }
    for (int i=0;i<n;++i) {
        ll x;
        cin >> x;
        if (x) {
            a[mp[x]] = a[mp[x]] + 1.;
            ans -= x * x % P;
        }
    }
    fft.init();
    fft.trans(a,MAXN);
    for (int i=0;i<MAXN;++i) a[i] *= a[i];
    fft.trans(a,MAXN,1);
    for (int i=0;i<MAXN;++i) {
        double tmp = a[i].real() + 0.5;
        ans += (ll)tmp * pr[i % (P-1)];
    }
    cout << ans / 2 << endl;
}
