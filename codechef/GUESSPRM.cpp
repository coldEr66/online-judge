#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
#define REP(i,n) for(int i=0;i<n;i++)
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
// #define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // cold66
//}
template<class T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int main(){
    IOS();
    ll t;
    cin >> t;
    while (t--) {
        cout << 1 << ' ' << 100000 << endl;
        ll tmp;
        cin >> tmp;
        ll cur = 100000LL * 100000LL - tmp;
        vector<ll> dt;
        for (ll i=2;i<=MAXn;i++) {
            if (cur % i == 0) dt.eb(i);
            while (cur % i == 0) cur /= i;
        }
        if (cur > 1) dt.eb(cur);

        ll ans = -1;
        debug(dt);
        for (ll i=1;i*i<=1e9;i++) {
            map<ll,ll> cnt;
            bool ok = true;
            REP (j,SZ(dt)) {
                ll tp = i*i%dt[j];
                if (cnt[tp] > 0) {
                    ok = false;
                    break;
                }
                cnt[tp]++;
            }
            if (ok) {
                cout << 1 << ' ' << i << endl;
                ans = i;
                break;
            }
        }
        debug(ans);

        cin >> tmp;
        REP (i,SZ(dt)) if (ans * ans % dt[i] == tmp) {
            cout << 2 << ' ' << dt[i] << endl;
            break;
        }
        string s;
        cin >> s;
        if (s[0] == 'N') return 0;
    }
}
