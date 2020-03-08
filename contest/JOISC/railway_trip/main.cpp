#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
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

int l[MAXn][MAXlg],r[MAXn][MAXlg];
int d[MAXn];
int main(){
    IOS();
    int n,k,q;
    cin >> n >> k >> q;
    REP (i,n) cin >> d[i];
    vector<int> stk;
    REP (i,n) {
        if (!i) {
            l[i][0] = 0;
            stk.eb(0);
        }
        else {
            while (SZ(stk) && d[stk.back()] < d[i]) stk.pob();
            if (!SZ(stk)) l[i][0] = 0;
            else l[i][0] = stk.back();
            stk.eb(i);
        }
    }
    vector<int>().swap(stk);
    for (int i=n-1;i>=0;i--) {
        if (i == n-1) {
            r[i][0] = n-1;
            stk.eb(n-1);
        }
        else {
            while (SZ(stk) && d[stk.back()] < d[i]) stk.pob();
            if (!SZ(stk)) r[i][0] = n-1;
            else r[i][0] = stk.back();
            stk.eb(i);
        }
    }
    REP1 (j,MAXlg-1) {
        REP (i,n) {
            l[i][j] = min(l[l[i][j-1]][j-1],l[r[i][j-1]][j-1]);
            r[i][j] = max(r[l[i][j-1]][j-1],r[r[i][j-1]][j-1]);
        }
    }
    while (q--) {
        int x,y;
        cin >> x >> y;
        x--, y--;
        if (x > y) swap(x,y);
        int L = x, R = x;
        int ans = 0;
        for (int i=MAXlg-1;i>=0;i--) {
            int tl = min(l[L][i],l[R][i]);
            int tr = max(r[L][i],r[R][i]);
            if (tr < y) {
                L = tl, R = tr;
                ans += (1<<i);
            }
        }
        x = R;
        L = R = y;
        for (int i=MAXlg-1;i>=0;i--) {
            int tl = min(l[L][i],l[R][i]);
            int tr = max(r[L][i],r[R][i]);
            if (tl > x) {
                L = tl, R = tr;
                ans += (1<<i);
            }
        }
        debug(x,L,R);
        cout << ans << endl;
    }
}
