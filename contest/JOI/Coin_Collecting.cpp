#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for (int i=n-1;i>=0;i--)
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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll cnt[MAXn][2];
int main(){
    IOS();
    ll n;
    cin >> n;
    ll ans = 0;
    REP (i,2*n) {
        ll x,y;
        cin >> x >> y;
        if (x < 1) {
            ans += 1-x;
            x = 1;
        }
        if (x > n) {
            ans += x-n;
            x = n;
        }
        y--;
        if (y < 0) {
            ans -= y;
            y = 0;
        }
        if (y > 1) {
            ans += y-1;
            y = 1;
        }
        cnt[x][y]++;
    }
    REP1 (i,n) {
        int Y[] = {0,1};
        if (cnt[i][0] < cnt[i][1]) swap(Y[0],Y[1]);
        ll tmp = 1-cnt[i][Y[0]];
        ans += abs(tmp);
        if (tmp < 0 && cnt[i][Y[1]] < 1) {
            ll tp = min(-tmp,1-cnt[i][Y[1]]);
            cnt[i][Y[1]] += tp;
            tmp += tp;
        }
        cnt[i+1][Y[0]] -= tmp;

        tmp = 1-cnt[i][Y[1]];
        ans += abs(tmp);
        cnt[i+1][Y[1]] -= tmp;
    }
    cout << ans << endl;
}
