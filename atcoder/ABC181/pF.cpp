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

const ll MAXN=1e2+7,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;
const double eps = 1e-6;

int x[MAXN], y[MAXN];
int n, dsu[MAXN], sz[MAXN];
int fnd(int v){
    if (dsu[v] == v) return dsu[v];
    return dsu[v] = fnd(dsu[v]);
}
void mrg(int i,int j){
    i = fnd(i), j = fnd(j);
    if (i == j) return;
    if (sz[i] < sz[j]) swap(i,j);
    dsu[j] = i;
    sz[i] += sz[j];
}
int sq(int v){return v * v;}
double dis(int i,int j){
    return sq(x[i] - x[j]) + sq(y[i] - y[j]);
}
bool chk(double r){
    for (int i=0;i<=n+1;++i) {
        dsu[i] = i;
        sz[i] = 1;
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            if (dis(i,j) < 4 * r * r) mrg(i,j);
        }
        if (abs(y[i] - 100) < 2 * r) mrg(0,i);
        if (abs(y[i] + 100) < 2 * r) mrg(n+1,i);
    }
    if (fnd(0) == fnd(n+1)) return false;
    return true;
}
signed main(){
    IOS();
    cin >> n;
    for (int i=1;i<=n;++i) {
        cin >> x[i] >> y[i];
    }
    double l = 0.0, r = 100.0;
    while (r-l > eps) {
        double mid = (l+r)/2.0;
        if (chk(mid)) l = mid;
        else r = mid;
    }
    cout << fixed << setprecision(6) << r << endl;
}
