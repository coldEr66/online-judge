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
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // cold66
//}
template<class T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

const ll MAXn=5e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ii d[MAXn];
ll bs[MAXn][MAXlg];
ll nxt[MAXn];
int main(){
    IOS();
    ll n,q;
    cin >> n >> q;
    REP (i,n) cin >> d[i].X >> d[i].Y;
    sort(d,d+n);

    ll lst = 0;
    ii mx = ii(0,-1);
    REP (i,MAXn) {
        while (lst < n && d[lst].X == i) {
            mx = max(mx,ii(d[lst].Y,lst));
            lst++;
        }
        if (mx.X <= i) nxt[i] = -1;
        else nxt[i] = mx.Y;
    }

    REP (i,n) bs[i][0] = nxt[d[i].Y];

    REP1 (j,MAXlg-1) {
        REP (i,n) {
            if (bs[i][j-1] == -1) bs[i][j] = -1;
            else bs[i][j] = bs[bs[i][j-1]][j-1];
        }
    }

    while (q--) {
        ll x,y;
        cin >> x >> y;
        ll cur = nxt[x];
        if (cur == -1) {
            cout << -1 << endl;
            continue;
        }

        ll ans = 1;
        for (ll i=MAXlg-1;i>=0;i--) {
            ll tp = bs[cur][i];
            if (tp == -1) continue;
            if (d[tp].Y < y) {
                ans += (1<<i);
                cur = tp;
            }
        }

        if (d[cur].Y >= y) cout << ans << endl;
        else if (bs[cur][0] == -1) cout << -1 << endl;
        else cout << ans+1 << endl;
    }
}
