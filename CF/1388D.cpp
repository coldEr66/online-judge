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

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll a[MAXn],b[MAXn];
vector<int> e[MAXn],ansid;
ll ans;
bool vis[MAXn];
int in[MAXn],pos[MAXn];
int main(){
    IOS();
    int n;
    cin >> n;
    for (int i=0;i<n;++i) cin >> a[i];
    for (int i=0;i<n;++i) {
        cin >> b[i];
        if (b[i] == -1) continue;
        b[i]--;
        e[i].eb(b[i]);
        in[b[i]]++;
    }
    
    queue<int> q;
    for (int i=0;i<n;++i) {
        if (!in[i]) q.emplace(i);
    }
    vector<int> tmp,tp;
    while (SZ(q)) {
        int cur = q.front();
        q.pop();
        if (vis[cur]) continue;
        vis[cur] = true;
        tp.eb(cur);
        if (a[cur] > 0) {
            ans += a[cur];
            ansid.eb(cur);
            for (auto i:e[cur]) {
                a[i] += a[cur];
                if (!vis[i]) {
                    in[i]--;
                    if (!in[i]) q.emplace(i);
                }
            }
        }
        else {
            tmp.eb(cur);
            ans += a[cur];
            for (auto i:e[cur]) {
                if (!vis[i]) {
                    in[i]--;
                    if (!in[i]) q.emplace(i);
                }
            }
        }
    }
    for (int i=0;i<n;++i) pos[tp[i]] = i;
    sort(ALL(tmp),[&](const int x,const int y){
        return pos[x] > pos[y];
    });
    for (int i=0;i<SZ(tmp);++i) ansid.eb(tmp[i]);

    cout << ans << endl;
    for (int i=0;i<n;++i) cout << ansid[i]+1 << " \n"[i==n-1];
}
