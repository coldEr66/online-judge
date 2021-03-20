#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
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

const ll MAXN=2e5+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;


int w[MAXN], bw[MAXN], p[MAXN], rp[MAXN];
vector<int> e[MAXN], v[MAXN];
bool vis[MAXN];
void dfs(int x, int idx) {
    v[idx].eb(x);
    vis[x] = true;
    for (auto i:e[x]) {
        if (vis[i]) continue;
        dfs(i,idx);
    }
}
signed main(){
    IOS();
    int n;
    cin >> n;
    for (int i=0;i<n;++i) {
        cin >> w[i];
    }
    for (int i=0;i<n;++i) {
        cin >> bw[i];
    }
    for (int i=0;i<n;++i) {
        cin >> p[i];
        p[i]--;
        e[p[i]].eb(i);
        e[i].eb(p[i]);
        rp[p[i]] = i;
    }
    int idx = 0;
    for (int i=0;i<n;++i) {
        if (!vis[i]) dfs(i, idx++);
    }
    debug(idx);
    
    vector<pii> ans;
    for (int i=0;i<idx;++i) {
        if (SZ(v[i]) == 1) continue;
        sort(ALL(v[i]),[&](const int a, const int b){
            return w[a] < w[b];
        });
        debug(v[i]);
        for (int j=0;j<SZ(v[i]);++j) {
            int cur = v[i][j];
            debug(cur);
            if (w[cur] <= bw[p[cur]]) return cout << -1 << endl,0;
        }
        for (int j=0;j<SZ(v[i])-1;++j) {
            int cur = v[i][j];
            ans.eb(cur, rp[cur]);
            rp[p[cur]] = rp[cur];
            swap(p[cur], p[rp[cur]]);
        }
    }
    cout << SZ(ans) << endl;
    for (int i=0;i<SZ(ans);++i) cout << ans[i].X + 1 << ' ' << ans[i].Y + 1 << endl;
}
