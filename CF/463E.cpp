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

const ll MAXn=2e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int n,q;
vector<int> prime[MAXn],e[MAXn];
int ans[MAXn],id[MAXn];
int w[MAXn];
vector<int> pr;
bitset<MAXn> ok;
void prime_sieve(){
    for (int i=2;i<MAXn;i++) {
        if (!ok[i]) pr.eb(i);
        for (int j=0;pr[j]*i<MAXn;j++) {
            ok[pr[j]*i] = true;
            if (i%pr[j] == 0) break;
        }
    }
}
void dfs(int x,int p){
    vector<int> tmp;
    int tp = w[x];
    ans[x] = 0;
    REP (i,SZ(pr)) {
        if (pr[i] > sqrt(w[x])+5) break;
        if (tp%pr[i] == 0) {
            if (SZ(prime[pr[i]])) {
                int y = prime[pr[i]].back();
                if (id[y] > id[ans[x]]) ans[x] = y;
            }
            tmp.eb(pr[i]);
            prime[pr[i]].eb(x);
        }
        while (tp%pr[i] == 0) tp /= pr[i];
        if (tp == 1) break;
    }
    if (tp != 1) {
        if (SZ(prime[tp])) {
            int y = prime[tp].back();
            if (id[y] > id[ans[x]]) ans[x] = y;
        }
        tmp.eb(tp);
        prime[tp].eb(x);
    }
    for (auto i:e[x]) {
        if (i == p) continue;
        id[i] = id[x]+1;
        dfs(i,x);
    }
    REP (i,SZ(tmp)) prime[tmp[i]].pob();
}
int main(){
    IOS();
    prime_sieve();
    cin >> n >> q;
    REP1 (i,n) cin >> w[i];
    REP (i,n-1) {
        int u,v;
        cin >> u >> v;
        e[u].eb(v);
        e[v].eb(u);
    }
    id[1] = 1;
    dfs(1,1);
    while (q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int x;
            cin >> x;
            if (ans[x] > 0) cout << ans[x] << endl;
            else cout << -1 << endl;
        }
        else {
            int v,W;
            cin >> v >> W;
            w[v] = W;
            dfs(1,1);
        }
    }
}
