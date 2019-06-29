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

const ll MAXn=11,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll A[MAXn][MAXn],B[MAXn][MAXn];
ll e[MAXn];
bitset<MAXn> vis;
vector<ll> cycle,stk;
ll l[MAXn],r[MAXn];
ll st;
ll ta,tb;
ll cal(ll x,ll y){
    if ((x+1)%3 == y) return -1;
    else if ((y+1)%3 == x) return 1;
    return 0;
}
void go(ll x){
    if (vis[x]) {
        st = x;
        while (SZ(stk) && stk.back() != st) {
            cycle.eb(stk.back());
            stk.pob();
        }
        assert(SZ(stk));
        cycle.eb(stk.back());
        stk.pob();
        return;
    }
    vis[x] = true;
    stk.eb(x);
    go(e[x]);
}
int main(){
    IOS();
    ll k,a,b;
    cin >> k >> a >> b;
    a--, b--;
    REP (i,3) REP (j,3) {
        cin >> A[i][j];
        A[i][j]--;
    }
    REP (i,3) REP (j,3) {
        cin >> B[i][j];
        B[i][j]--;
    }

    REP (i,9) {
        ll alice = i/3, bob = i%3;
        e[i] = A[alice][bob]*3 + B[alice][bob];
    }
    ll root = a*3 + b;
    go(root);
    ll cur = root;
    ll ans1 = 0, ans2 = 0;
    while (cur != st) {
        if (!k) break;
        ll tmp = cal(cur/3,cur%3);
        debug(tmp,cur);
        if (tmp == 1) ans1++;
        else if (tmp == -1) ans2++;
        k--;
        cur = e[cur];
    }
    for (auto i:cycle) {
        if (cal(i/3,i%3) == 1) ta++;
        else if (cal(i/3,i%3) == -1) tb++;
    }
    debug(ta,tb);
    ll cnt = k/SZ(cycle);
    k -= cnt*SZ(cycle);
    debug(ta,tb,cycle);
    ans1 += cnt*ta;
    ans2 += cnt*tb;
    debug(ans1,ans2,k);
    for (ll i=SZ(cycle)-1;i>=0;i--,k--) {
        if (!k) break;
        ll tmp = cal(cycle[i]/3,cycle[i]%3);
        if (tmp == 1) ans1++;
        else if (tmp == -1) ans2++;
    }
    cout << ans1 << ' ' << ans2 << endl;
}
