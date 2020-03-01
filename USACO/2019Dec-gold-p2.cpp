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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int d[MAXn];
vector<int> e[MAXn],tmpst,tg[MAXn];
vector<ii> stk[MAXn];
int in[MAXn],out[MAXn],t;
int pt[MAXn][2],color[MAXn];
int ok[MAXn];
bool anc(int u,int v){
    return in[u] <= in[v] && out[u] >= out[v];
}
void predfs(int x,int p){
    in[x] = ++t;
    for (auto i:e[x]) {
        if (i == p) continue;
        predfs(i,x);
    }
    out[x] = ++t;
}
void dfs(int x,int p){
    stk[d[x]].eb(x,SZ(tmpst));
    tmpst.eb(x);
    for (auto it:tg[x]) {
        if (SZ(stk[color[it]])) {
            ii cur = stk[color[it]].back();
            if (cur.X == x) ok[it] = 1;
            else {
                int lst = tmpst[cur.Y+1];
                if (pt[it][0] == x) swap(pt[it][0],pt[it][1]);
                if (!anc(lst,pt[it][0])) ok[it] = 1;
            }
        }
    }
    for (auto i:e[x]) {
        if (i == p) continue;
        dfs(i,x);
    }
    stk[d[x]].pob();
    tmpst.pob();
}
int main(){
    IOS();
    freopen("milkvisits.in","r",stdin);
    freopen("milkvisits.out","w",stdout);
    int n,m;
    cin >> n >> m;
    REP (i,n) cin >> d[i];
    REP (i,n-1) {
        int u,v;
        cin >> u >> v;
        u--, v--;
        e[u].eb(v);
        e[v].eb(u);
    }
    REP (i,m) {
        cin >> pt[i][0] >> pt[i][1] >> color[i];
        pt[i][0]--, pt[i][1]--;
        REP (j,2) tg[pt[i][j]].eb(i);
    }
    predfs(0,0);
    dfs(0,0);
    REP (i,m) cout << ok[i];
    cout << endl;
}
