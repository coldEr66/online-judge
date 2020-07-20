#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define X first
#define Y second
#define eb emplace_back
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"LINE %d: (%s) = ",__LINE__,#__VA_ARGS__);\
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

const ll MAXn=1e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

vector<int> e[MAXn];
vector<ii> edg;
ll mxdep[MAXn];
ll dfs(int x,int p,int d){
    ll ret = d;
    ll child = 0;
    for (auto i:e[x]) {
        if (i == p) continue;
        child++;
        ll tmp = dfs(i,x,d+1);
        ret = max(ret,tmp);
    }
    mxdep[d] = max(mxdep[d],child);
    return ret;
}
int main(){
    IOS();
    int n;
    cin >> n;
    REP (i,n-1) {
        int u,v;
        cin >> u >> v;
        u--, v--;
        e[u].eb(v);
        e[v].eb(u);
        edg.eb(u,v);
    }
    pair<ll,ll> ans = ii(INF,-1);
    REP (i,n) {
        RST(mxdep,0);
        ll dep = dfs(i,i,1);
        debug(dep);
        pary(mxdep,mxdep+n);
        ll cur = 1;
        REP1 (j,n) if (mxdep[j] > 0) cur *= mxdep[j];
        debug(i,cur);
        if (ans.X > dep) ans = ii(dep,cur);
        else if (ans.X == dep && ans.Y > cur) {
            ans = ii(dep,cur);
        }
    }
    REP (i,n-1) {
        RST(mxdep,0);
        int u = edg[i].X, v = edg[i].Y;
        ll dep1 = dfs(u,v,1);
        ll dep2 = dfs(v,u,1);
        pary(mxdep,mxdep+n);
        ll dep = max(dep1,dep2);
        debug(dep1,dep2,dep,u,v);
        ll cur = 2;
        REP1 (j,n) if (mxdep[j] > 0) cur *= mxdep[j];
        debug(i,cur);
        if (ans.X > dep) ans = ii(dep,cur);
        else if (ans.X == dep && ans.Y > cur) {
            ans = ii(dep,cur);
        }
    }
    cout << ans.X << ' ' << ans.Y << endl;
}