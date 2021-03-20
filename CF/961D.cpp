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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

pll operator - (const pll a,const pll b){return pii(a.X-b.X,a.Y-b.Y);}
ll operator ^ (const pll a,const pll b){return a.X * b.Y - a.Y * b.X;}
pll d[MAXn];
bitset<MAXn> bs;
signed main(){
    IOS();
    int n;
    cin >> n;
    for (int i=0;i<n;++i) {
        cin >> d[i].X >> d[i].Y;
    }
    if (n <= 3) return cout << "YES" << endl,0;
    bool ok = false;
    for (int i=0;i<3;++i) {
        for (int j=i+1;j<3;++j) {
            bs.reset();
            pii tmp = d[i] - d[j];
            for (int p=0;p<n;++p) {
                pii pi = d[i] - d[p];
                if ((pi ^ tmp) == 0) bs[p] = 1;
            }
            vector<pii> v;
            for (int p=0;p<n;++p) {
                if (!bs[p]) v.eb(d[p]);
            }
            if (SZ(v) <= 1) ok = true;
            else {
                bool tpok = true;
                pii ttp = v[0] - v[1];
                for (int p=2;p<SZ(v);++p) {
                    pii tttp = v[p] - v[0];
                    if ((ttp ^ tttp) != 0) {
                        tpok = false;
                        break;
                    }
                }
                if (tpok) ok = true;
            }
        }
    }
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}
