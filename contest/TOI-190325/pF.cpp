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

const ll MAXn=1e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

typedef pair<ll,ii> iii;
ll n,m;
ll d[MAXn][MAXn];
ll dis[MAXn][MAXn];
bool vis[MAXn][MAXn];
ll dx[] = {1,0,0,-1};
ll dy[] = {0,1,-1,0};
bool chk(ll x,ll y){
    return x < 0 || x >= n || y < 0 || y >= m;
}
int main(){
    IOS();
    ll t;
    cin >> t;
    while (t--) {
        RST(vis,0);
        cin >> n >> m;
        REP (i,n) REP (j,m) dis[i][j] = INF;
        REP (i,n) REP (j,m) cin >> d[i][j];
        priority_queue<iii,vector<iii>,greater<iii> > pq;
        pq.emplace(d[0][0],ii(0,0));
        dis[0][0] = d[0][0];
        REP (i,n*m) {
            ii tp = {-1,-1};
            while (SZ(pq) && vis[tp.X = pq.top().Y.X][tp.Y = pq.top().Y.Y]) pq.pop();
            if (tp.X == -1) continue;
            debug(tp,dis[tp.X][tp.Y]);
            vis[tp.X][tp.Y] = true;
            REP (k,4) {
                ll tx = tp.X + dx[k], ty = tp.Y+dy[k];
                if (chk(tx,ty) || vis[tx][ty] || dis[tx][ty] != INF) continue;
                if (tp == ii(0,2)) debug(tx,ty);
                dis[tx][ty] = dis[tp.X][tp.Y] + d[tx][ty];
                debug(dis[tx][ty],d[tx][ty],tx,ty);
                pq.emplace(dis[tx][ty],ii(tx,ty));
            }
        }
        cout << dis[n-1][m-1] << endl;
    }
}
