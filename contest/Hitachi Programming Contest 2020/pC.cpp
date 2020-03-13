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

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

vector<int> e[MAXn];
int p[MAXn];
int ok[MAXn];
vector<int> a,b;
void dfs(int x,int par,bool col){
    if (!col) a.eb(x);
    else b.eb(x);
    for (auto i:e[x]) {
        if (i == par) continue;
        dfs(i,x,!col);
    }
}
int main(){
    IOS();
    int n;
    cin >> n;
    REP (i,n-1) {
        int u,v;
        cin >> u >> v;
        e[u].eb(v);
        e[v].eb(u);
    }
    dfs(1,1,0);
    if (SZ(a) > SZ(b)) swap(a,b);
    int t1 = n/3, t2 = n/3;
    if (n % 3 == 1) t1++;
    if (n % 3 == 2) t1++, t2++;
    if (t1 <= SZ(a) && t2 <= SZ(b)) {
        REP (i,t1) ok[a[i]] = 1;
        REP (i,t2) ok[b[i]] = 2;
    }
    else {
        REP (i,t1) ok[b[i]] = 1;
        for (int i=t1;i<t1+t2;i++) ok[b[i]] = 2;
    }
    int c0 = 3, c1 = 1, c2 = 2;
    REP1 (i,n) {
        if (ok[i] == 0) {
            p[i] = c0;
            c0 += 3;
        }
        else if (ok[i] == 1) {
            p[i] = c1;
            c1 += 3;
        }
        else {
            p[i] = c2;
            c2 += 3;
        }
    }
    REP1 (i,n) cout << p[i] << " \n"[i==n];
}
