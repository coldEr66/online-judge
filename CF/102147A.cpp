#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
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

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

vector<ll> d[MAXn];
ll cmx[MAXn],rmx[MAXn];
ll r[MAXn],c[MAXn];
int main(){
    IOS();
    ll n,m,q;
    cin >> n >> m >> q;
    REP (i,n) REP (j,m) {
        ll x;
        cin >> x;
        d[i].eb(x);
    }
    REP (i,n) REP (j,m) {
        rmx[i] = max(rmx[i],d[i][j]);
        cmx[j] = max(cmx[j],d[i][j]);
    }
    pary(rmx,rmx+n);
    pary(cmx,cmx+m);
    RST(r,-1);
    RST(c,-1);
    ll cnt = 0;
    REP (i,n) REP (j,m) if (rmx[i] == cmx[j] && rmx[i] == d[i][j]) {
        cnt++;
        r[i] = j;
        c[j] = i;
    }

    while (q--) {
        ll x,y,v;
        cin >> x >> y >> v;
        x--,y--;
        if (d[x][y] == rmx[x] && d[x][y] == cmx[y]);
        else {
            if (v > rmx[x] && v > cmx[y]) {
                if (r[x] != -1 && c[y] != -1) cnt--;
                else if (r[x] != -1 || c[y] != -1);
                else cnt++;
                ll a = r[x], b = c[y];
                if (a != -1) c[a] = -1;
                if (b != -1) r[b] = -1;
                r[x] = y;
                c[y] = x;
            }
            else if (v > rmx[x]) {
                if (r[x] != -1) {
                    cnt--;
                }
                ll a = r[x];
                if (a != -1) c[a] = -1;
                r[x] = -1;
            }
            else if (v > cmx[y]) {
                if (c[y] != -1) {
                    cnt--;
                }
                ll a = c[y];
                if (a != -1) r[a] = -1;
                c[y] = -1;
            }
        }
        d[x][y] = v;
        rmx[x] = max(rmx[x],v);
        cmx[y] = max(cmx[y],v);
        cout << cnt << endl;
        pary(r,r+n);
        pary(c,c+m);
    }
}
/*
2 3 10000
1 4 3
6 5 2
2 2 9
1 3 5
2 2 10
2 3 7
2 2 11
1 1 7
*/
