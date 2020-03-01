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

const ll MAXn=2e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int p[MAXn],c[MAXn],out[MAXn],ok[MAXn];
int sz[MAXn];
int ans[MAXn];
vector<int> e[MAXn];
void dfs(int x){
    sz[x] = 1;
    for (auto i:e[x]) {
        dfs(i);
        sz[x] += sz[i];
    }
}
void gogo(int x){
    while (p[x] != -1) {
        if (c[x] > 0) c[x]--;
        x = p[x];
    }
    if (c[x] > 0) c[x]--;
}
int main(){
    IOS();
    int n;
    cin >> n;
    int root = -1;
    REP (i,n) {
        cin >> p[i] >> c[i];
        p[i]--;
        if (p[i] != -1) e[p[i]].eb(i);
        else {
            root = i;
        }
        out[p[i]]++;
    }
    dfs(root);
    pary(sz,sz+n);
    REP (i,n) {
        if (c[i] > sz[i]-1) return cout << "NO" << endl,0;
    }

    vector<int> leaf;
    REP (i,n) if (!out[i]) leaf.eb(i);
    int cnt = 0;
    int cur = 1;
    while (cnt < n) {
        vector<int> tmp;
        REP (j,n) {
            if (!ok[j] && c[j] == 0 && out[j] != 0) {
                tmp.eb(j);
            }
        }
        if (!SZ(tmp)) {
            tmp.eb(leaf.back());
            leaf.pob();
        }
        debug(tmp);
        REP (j,SZ(tmp)) {
            gogo(tmp[j]);
            ans[tmp[j]] = cur;
            ok[tmp[j]] = true;
            cnt++;
        }
        debug(cur);
        cur++;
    }
    cout << "YES" << endl;
    REP (i,n) cout << ans[i] << " \n"[i==n-1];
}
