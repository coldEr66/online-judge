#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define X first
#define Y second
#define mkp make_pair
#define pb push_back
#define eb emplace_back
#define pob pop_back
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
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
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

ll d[MAXn];
int main(){
    IOS();
    ll t;
    cin >> t;
    while (t--) {
        ll n,f;
        cin >> n;
        REP (i,n-1) cin >> d[i];
        cin >> f;

        ll pos = -1, ans = INF;
        REP (i,n-1) {
            if (d[i] > f) continue;
            ll llst = i-1, rlst = n-2;
            ll llen = 1, rlen = 1;
            ll lc = i, rc = n-i-1;
            ll tmp = 0;

            while (1) {
                if (lc > 0) {
                    if (lc&1 && llst >= 0) tmp += d[llst];
                    else if (!(lc&1)) llst -= llen;
                    lc = (lc+1)>>1;
                    llen <<= 1;
                }
                if (lc == 0 && rc == 1) break;
                if (rc >= 1) {
                    if (rc&1 && lc > 0) lc--;
                    else if (rc&1 && lc == 0 && rlst >= 0) tmp += d[rlst];
                    if (!(rc&1)) rlst -= rlen;
                    rc = (rc+1)>>1;
                    rlen <<= 1;
                }
                if (lc == 0 && rc == 1) break;
            }
            debug(tmp,i);

            if (tmp + f < ans) {
                pos = i+1;
                ans = tmp + f;
            }
        }
        if (pos == -1) cout << "impossible" << endl;
        else {
            cout << "possible" << endl;
            cout << pos << ' ' << ans << endl;
        }
    }
}
