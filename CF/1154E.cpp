#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
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

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int d[MAXn],pos[MAXn];
int dsu[MAXn];
int pre[MAXn],nxt[MAXn];
char ans[MAXn];
int fnd(int x){
    if (x == dsu[x]) return x;
    return dsu[x] = fnd(dsu[x]);
}
int main(){
    IOS();
    int n,k;
    cin >> n >> k;
    REP1 (i,n) {
        cin >> d[i];
        pos[d[i]] = i;
        dsu[i] = i;
        nxt[i] = i+1;
        pre[i] = i-1;
    }
    pre[0] = 0;
    nxt[n+1] = n+1;

    int cur = n;
    bool fg = 0;
    while (cur != 0) {
        int it = pos[cur];
        debug(it);
        int cnt = 0;
        int l = INF, r = 0;
        while (cnt != k+1) {
            if (it > n) break;
            ans[it] = (fg ?'2':'1');
            dsu[d[it]] = fnd(d[it]-1);
            r = max(r,it);
            it = nxt[it];
            debug(it);
            cnt++;
        }
        cnt = 0;
        it = pre[pos[cur]];
        while (cnt != k) {
            if (it <= 0) break;
            ans[it] = (fg ?'2':'1');
            dsu[d[it]] = fnd(d[it]-1);
            l = min(l,it);
            it = pre[it];
            debug(it);
            cnt++;
        }
        cur = fnd(cur-1);
        if (l == INF) l = 1;
        if (r == 0) r = n;
        pre[nxt[r]] = pre[l];
        nxt[pre[l]] = nxt[r];
        debug(l,r,pre[r+1],nxt[l-1]);
        fg = !fg;
    }
    REP1 (i,n) cout << ans[i];
    cout << endl;
}
