#include <bits/stdc++.h>
#include <atcoder/convolution>
#include <atcoder/modint>
using namespace atcoder;
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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

using mint = modint998244353;
using poly = vector<mint>;

int cnt[MAXn];
mint fac[MAXn],inv[MAXn];
mint p[MAXn];
mint p2 = mint(1) / mint(2);
mint C(int n,int k){
    return fac[n] * inv[n-k] * inv[k];
}
mint gtp(int x){
    return fac[x] * p[x/2] * inv[x/2];
}
int main(){
    IOS();
    int n;
    cin >> n;
    fac[0] = 1;
    p[0] = 1;
    for (int i=1;i<MAXn;++i) {
        fac[i] = fac[i-1] * i;
        p[i] = p[i-1] * p2;
    }
    inv[MAXn-1] = mint(1) / fac[MAXn-1];
    for (int i=MAXn-2;i>=0;i--) {
        inv[i] = inv[i+1] * mint(i+1);
    }
    for (int i=0;i<2*n;++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    struct cmp {
        bool operator () (const poly &a,const poly &b){
            return SZ(a) > SZ(b);
        }
    };
    priority_queue<poly,vector<poly>,cmp> pq;
    for (int i=1;i<MAXn;++i) {
        if (cnt[i] == 0) continue;
        poly tmp = {1};
        for (int j=1;j * 2 <= cnt[i];++j) {
            tmp.eb(C(cnt[i],2*j) * gtp(2*j));
        }
        pq.emplace(tmp);
    }
    while (SZ(pq) > 1) {
        poly a = pq.top();
        pq.pop();
        poly b = pq.top();
        pq.pop();
        poly c = convolution(a,b);
        pq.emplace(c);
    }
    poly ans = pq.top();
    mint tt = 0;
    for (int i=0,sign=1;i<SZ(ans);++i,sign*=-1) {
        tt = tt + sign * ans[i] * gtp(2 * (n-i));
    }
    cout << tt.val()  << endl;
}
