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
#define SZ(a) (ll)a.size()
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
const int INF=0x3f3f3f3f;
const int tt = 1000000;

struct edg{
    int u,v,f,c;
    bool operator < (const edg &a) const {
        return f > a.f;
    }
};
int n,m;
vector<ii> e[MAXn];
vector<edg> E;
int gtc(){
    int dis[MAXn];
    RST(dis,INF);
    dis[0] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.emplace(0,0);
    while (SZ(pq)) {
        ll t = pq.top().Y, tmpdis = pq.top().X;
        pq.pop();
        if (dis[t] != tmpdis) continue;
        for (ii it:e[t]) {
            if (dis[it.X] > dis[t] + it.Y) {
                dis[it.X] = dis[t] + it.Y;
                pq.emplace(dis[it.X],it.X);
            }
        }
    }
    debug(dis[n-1]);
    return dis[n-1];
}
int main(){
    IOS();
    freopen("pump.in","r",stdin);
    freopen("pump.out","w",stdout);
    cin >> n >> m;
    REP (i,m) {
        int u,v;
        cin >> u >> v;
        u--, v--;
        int c,f;
        cin >> c >> f;
        E.eb((edg){u,v,f,c});
    }
    sort(ALL(E));
    int ans = 0;
    REP (i,m) {
        int idx = i;
        int curf = E[i].f;
        while (idx < m && E[idx].f == curf) {
            int u = E[idx].u, v = E[idx].v, c = E[idx].c;
            e[u].eb(v,c);
            e[v].eb(u,c);
            idx++;
        }
        ans = max(ans,tt * curf / gtc());
        i = idx-1;
    }
    cout << ans << endl;
}
