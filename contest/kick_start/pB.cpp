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

const ll MAXn=255,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll n,m,c = 1;
ll dis[MAXn][MAXn];
char d[MAXn][MAXn];
ll dx[] = {1,0,0,-1};
ll dy[] = {0,1,-1,0};
bool chk(ll x,ll y){
    return x < 0 || x >= n || y < 0 || y >= m;
}
ll BFS(){
    queue<ii> q;
    REP (i,n) REP (j,m) if (d[i][j] == '1') {
        q.push(ii(i,j));
        dis[i][j] = 0;
    }
    ll ret = 0;
    while (SZ(q)) {
        ii cur = q.front();
        q.pop();
        REP (i,4) {
            ll tx = cur.X + dx[i], ty = cur.Y + dy[i];
            if (chk(tx,ty)) continue;
            if (dis[tx][ty] != INF) continue;
            dis[tx][ty] = dis[cur.X][cur.Y] + 1;
            ret = max(ret,dis[tx][ty]);
            q.push(ii(tx,ty));
        }
    }
    return ret;
}
ll cal(ii a,ii b){
    return abs(a.X-b.X) + abs(a.Y-b.Y);
}
int main(){
    IOS();
    ll t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        REP (i,n) REP (j,m) cin >> d[i][j];
        REP (i,n) REP (j,m) dis[i][j] = INF;
        ll mx = BFS();
        debug(mx);
        vector<ii> v;
        if (mx == 0) {
            cout << "Case #" << c++ << ": ";
            cout << 0 << endl;
            continue;
        }
        REP (i,n) REP (j,m) if (dis[i][j] == mx) v.eb(i,j);
        ll ans = mx;
        if (SZ(v) == 1) {
            ll tmp = 0;
            debug(v[0]);
            REP (i,n) REP (j,m) {
                if (d[i][j] == '1') continue;
                tmp = max(tmp,min(cal(v[0],ii(i,j)),dis[i][j]));
            }
            ans = min(ans,tmp);
        }
        else {
            REP (i,SZ(v)) {
                ll tmp = 0;
                for (ll j=i+1;j<SZ(v);j++) {
                    tmp = max(tmp,min(cal(v[i],v[j]),mx));
                }
                ans = min(ans,tmp);
            }
        }
        cout << "Case #" << c++ << ": ";
        cout << ans << endl;
    }
}
