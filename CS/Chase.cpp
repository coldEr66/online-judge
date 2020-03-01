#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
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

int n,v;
ll up[MAXn][105],dn[MAXn][105];
vector<int> e[MAXn];
ll d[MAXn];
ll N[MAXn];
ll ans;
ii upp[105][2],dnn[105][2];
void dfs(int x,int p){
    up[x][0] = 0;
    for (auto i:e[x]) {
        if (i == p) continue;
        dfs(i,x);
    }
    if (x != p) {
        for (auto i:e[x]) {
            if (i == p) continue;
            REP1 (j,v) {
                up[x][j] = max(up[x][j],max(up[i][j],up[i][j-1] + N[x] - d[p]));
            }
        }
    }
    REP (i,v+1) dn[x][i] = (!i ?0:N[x]);
    REP (i,v+1) {
        upp[i][0] = upp[i][1] = ii(0,-1);
        dnn[i][0] = dnn[i][1] = ii((!i ?0:N[x]),x);
    }
    for (auto i:e[x]) {
        if (i == p) continue;
        REP1 (j,v) {
            if (upp[j][0].X <= up[i][j]) {
                upp[j][1] = upp[j][0];
                upp[j][0] = ii(up[i][j],i);
            }
            else if (upp[j][1].X < up[i][j]) {
                upp[j][1] = ii(up[i][j],i);
            }

            dn[x][j] = max(dn[x][j],max(dn[i][j],dn[i][j-1] + N[x] - d[i]));
            ll lst = dn[i][j];
            if (j) lst = max(lst,dn[i][j-1] + N[x] - d[i]);
            if (dnn[j][0].X <= lst) {
                dnn[j][1] = dnn[j][0];
                dnn[j][0] = ii(lst,i);
            }
            else if (dnn[j][1].X < lst) {
                dnn[j][1] = ii(lst,i);
            }
        }
    }

    REP (i,v+1) {
        if (upp[i][0].Y != dnn[v-i][0].Y) {
            ans = max(ans,upp[i][0].X + dnn[v-i][0].X);
        }
        else {
            ans = max(ans,upp[i][1].X + dnn[v-i][0].X);
            ans = max(ans,upp[i][0].X + dnn[v-i][1].X);
        }
    }
}
int main(){
    IOS();
    cin >> n >> v;
    REP (i,n) cin >> d[i];
    REP (i,n-1) {
        int a,b;
        cin >> a >> b;
        a--, b--;
        e[a].eb(b);
        e[b].eb(a);
        N[a] += d[b];
        N[b] += d[a];
    }

    dfs(0,0);
    cout << ans << endl;
}
