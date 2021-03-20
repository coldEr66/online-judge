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

const ll MAXn=5e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

vector<int> bg[MAXn],wg[MAXn];
int d[MAXn],b[MAXn],w[MAXn];
int main(){
    IOS();
    int n,m;
    cin >> n >> m;
    for (int i=0;i<m;++i) {
        int u,v;
        cin >> u >> v;
        u-- ,v--;
        int t;
        cin >> t;
        if (!t) bg[v].eb(u);
        else wg[v].eb(u);
    }
    for (int i=0;i<n;++i) d[i] = b[i] = w[i] = n;
    d[n-1] = b[n-1] = w[n-1] = 0;
    queue<int> q;
    q.emplace(n-1);
    while (SZ(q)) {
        int cur = q.front();
        q.pop();
        for (auto i:bg[cur]) {
            if (b[i] < n) continue;
            b[i] = d[cur] + 1;
            if (max(b[i],w[i]) < n) {
                d[i] = max(b[i],w[i]);
                q.emplace(i);
            }
        }
        for (auto i:wg[cur]) {
            if (w[i] < n) continue;
            w[i] = d[cur] + 1;
            if (max(b[i],w[i]) < n) {
                d[i] = max(b[i],w[i]);
                q.emplace(i);
            }
        }
    }

    if (d[0] == n) cout << -1 << endl;
    else cout << d[0] << endl;
    for (int i=0;i<n;++i) {
        if (b[i] > w[i]) cout << 0;
        else cout << 1;
    }
    cout << endl;
}
