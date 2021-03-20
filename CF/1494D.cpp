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

const ll MAXN=505,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int d[MAXN][MAXN];
int tt;
vector<pii> edge;
int ans[MAXN * 2];
void gogo(vector<int> &idx, int p = -1){
    if (SZ(idx) == 1) {
        int cur = idx[0];
        ans[cur] = d[cur][cur];
        edge.eb(cur, p);
        return;
    }

    int mx = 0;
    for (auto i:idx) {
        for (auto j:idx) {
            mx = max(mx, d[i][j]);
        }
    }
    int cur = tt;
    ans[tt++] = mx;
    if (p != -1) edge.eb(cur, p);
    vector<vector<int>> nxt;
    for (auto i:idx) {
        bool fg = false;
        for (auto &it:nxt) {
            if (d[i][it[0]] != mx) {
                fg = true;
                it.eb(i);
                break;
            }
        }
        if (!fg) {
            vector<int> tmp = {i};
            nxt.eb(tmp);
        }
    }

    for (auto it:nxt) {
        gogo(it, cur);
    }
}
signed main(){
    IOS();
    int n;
    cin >> n;
    vector<int> idx;
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            cin >> d[i][j];
        }
        idx.eb(i);
    }

    tt = n;
    gogo(idx);
    
    cout << tt << endl;
    for (int i=0;i<tt;++i) {
        cout << ans[i] << " \n"[i==tt-1];
    }
    cout << max_element(ans,ans+tt) - ans + 1 << endl;
    for (int i=0;i<tt-1;++i) {
        cout << edge[i].X + 1 << ' ' << edge[i].Y + 1 << endl;
    }
}
