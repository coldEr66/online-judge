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

const ll MAXn=2e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll n,k;
ll d[MAXn][MAXn];
ii lstc[MAXn],lstr[MAXn];
bool okc[MAXn],okr[MAXn];
ll ans[MAXn][MAXn];
int main(){
    IOS();
    cin >> n >> k;
    REP (i,n) REP (j,n) {
        char c;
        cin >> c;
        if (c == 'B') d[i][j] = 1;
        else d[i][j] = 0;
    }
    REP (i,n) {
        lstc[i] = ii(n,-1);
        bool fg = true;
        REP (j,n) {
            if (d[i][j] == 1) {
                fg = false;
                lstc[i].X = min(lstc[i].X,j);
                lstc[i].Y = max(lstc[i].Y,j);
            }
        }
        if (fg) okc[i] = true;
    }
    pary(okc,okc+n);
    pary(lstc,lstc+n);
    REP (j,n-k+1) {
        ll cur = 0;
        REP (i,k) {
            if (okc[i]) {
                continue;
            }
            if (lstc[i].X >= j && lstc[i].Y <= j+k-1) cur++;
            debug(i,cur);
        }
        debug(0,j,cur);
        ans[0][j] = cur;
        for (ll i=k;i<n;i++) {
            if (!okc[i-k] && lstc[i-k].X >= j && lstc[i-k].Y <= j+k-1) cur--;
            if (okc[i]);
            else if (lstc[i].X >= j && lstc[i].Y <= j+k-1) cur++;
            ans[i-k+1][j] = cur;
            debug(i-k+1,j,cur);
        }
    }
    REP (j,n) {
        lstr[j] = ii(n,-1);
        bool fg = true;
        REP (i,n) {
            if (d[i][j] == 1) {
                fg = false;
                lstr[j].X = min(lstr[j].X,i);
                lstr[j].Y = max(lstr[j].Y,i);
            }
        }
        if (fg) okr[j] = true;
    }
    ll cnt = 0;
    REP (i,n-k+1) {
        ll cur = 0;
        REP (j,k) {
            if (okr[j]) continue;
            if (lstr[j].X >= i && lstr[j].Y <= i+k-1) cur++;
        }
        debug(ans[i][0]);
        ans[i][0] += cur;
        cnt = max(cnt,ans[i][0]);
        for (ll j=k;j<n;j++) {
            if (!okr[j-k] && lstr[j-k].X >= i && lstr[j-k].Y <= i+k-1) cur--;
            if (okr[j]);
            else if (lstr[j].X >= i && lstr[j].Y <= i+k-1) cur++;
            debug(i,j-k+1,ans[i][j-k+1],cur);
            debug(lstr[j-k],j-k);
            debug(cur);
            ans[i][j-k+1] += cur;
            cnt = max(cnt,ans[i][j-k+1]);
        }
    }
    debug(cnt);
    REP (i,n) cnt += okr[i] + okc[i];
    cout << cnt << endl;
}
