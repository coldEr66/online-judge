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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

vector<ll> pos,neg,d;
int main(){
    IOS();
    int t;
    cin >> t;
    while (t--) {
        pos.clear(), neg.clear();
        d.clear();
        ll n;
        cin >> n;
        bool zero = 0;
        for (int i=0;i<n;++i) {
            ll x;
            cin >> x;
            if (x == 0) zero = true;
            else if (x > 0) {
                pos.eb(x);
                d.eb(x);
            }
            else {
                neg.eb(x);
                d.eb(x);
            }
        }
        ll ans = -INF;
        sort(ALL(pos)), sort(ALL(neg));
        debug(pos,neg);
        sort(ALL(d));
        if (SZ(pos) >= 5) {
            ll ret = 1;
            for (int i=SZ(pos)-1;i>=SZ(pos)-5;i--) {
                ret *= pos[i];
            }
            ans = max(ans,ret);
        }
        if (SZ(pos) >= 3 && SZ(neg) >= 2) {
            ll ret = 1;
            for (int i=SZ(pos)-1;i>=SZ(pos)-3;i--) {
                ret *= pos[i];
            }
            ret *= neg[0];
            ret *= neg[1];
            ans = max(ans,ret);
        }
        if (SZ(pos) >= 1 && SZ(neg) >= 4) {
            ll ret = pos.back();
            for (int i=0;i<4;++i) ret *= neg[i];
            ans = max(ans,ret);
        }
        if (zero) ans = max(ans,0LL);
        debug(ans,d);
        for (int i=1;i<=5;i+=2) {
            ll ret = 1;
            if (SZ(neg) >= i && SZ(pos) >= 5-i) {
                for (int j=SZ(neg)-1;j>=SZ(neg)-i;j--) {
                    ret *= neg[j];
                }
                for (int j=0;j<5-i;++j) ret *= pos[j];
                ans = max(ans,ret);
            }
        }
        cout << ans << endl;
    }
}
