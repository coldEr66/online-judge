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

const ll MAXN=1e5+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

vector<pii> e[MAXN];
int mpv[MAXN],mpe[MAXN],id;
vector<int> p;
void dfs(int x,int fa){
    mpv[x] = id++;
    for (auto i:e[x]) {
        int to = i.X, eid = i.Y;
        if (to == fa) continue;
        dfs(to,x);
        mpe[eid] = mpv[to];
    }
}
int gt(int a){
    return int(upper_bound(ALL(p),a) - p.begin() - 1);
}
signed main(){
    IOS();
    int n,q;
    cin >> n;
    for (int i=0;i<n-1;++i) {
        int u,v;
        cin >> u >> v;
        u--, v--;
        e[u].eb(v,i);
        e[v].eb(u,i);
    }
    cin >> q;
    int root = 0;
    for (int i=0;i<n;++i) {
        if (SZ(e[root]) < SZ(e[i])) root = i;
    }
    mpv[root] = id++;
    for (auto i:e[root]) {
        int to = i.X, eid = i.Y;
        dfs(to,root);
        p.eb(mpv[to]);
        mpe[eid] = mpv[to];
    }
    set<int> st;
    st.insert(INF);
    while (q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int x;
            cin >> x;
            x--;
            x = mpe[x];
            st.erase(x);
        }
        else if (cmd == 2) {
            int x;
            cin >> x;
            x--;
            x = mpe[x];
            st.insert(x);
        }
        else {
            int a,b;
            cin >> a >> b;
            a--, b--;
            a = mpv[a], b = mpv[b];
            if (a > b) swap(a,b);
            if (a == b) {
                cout << 0 << endl;
                continue;
            }
            if (a == 0) {
                int it = gt(b);
                auto tmp = st.lower_bound(p[it]);
                if (*tmp <= b) cout << -1 << endl;
                else cout << b - p[it] + 1 << endl;
            }
            else {
                int it1 = gt(a);
                int it2 = gt(b);
                int same = (it1 == it2);
                if (same) {
                    auto it = st.upper_bound(a);
                    if (*it <= b) cout << -1 << endl;
                    else cout << b-a << endl;
                }
                else {
                    auto t1 = st.lower_bound(p[it1]), t2 = st.lower_bound(p[it2]);
                    if (*t1 <= a || *t2 <= b) cout << -1 << endl;
                    else cout << a - p[it1] + 1 + b - p[it2] + 1 << endl;
                }
            }
        }
    }
}
