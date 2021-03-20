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

bool ans[MAXN];
int dsu[MAXN],sz[MAXN];
vector<int> e[MAXN];
int in[MAXN],out[MAXN],idx;
vector<pii> Q[MAXN];
int p[MAXN],ind[MAXN];
struct query{
    int t,x,y;
};
vector<query> v;
int fnd(int x){
    if (dsu[x] == x) return x;
    return dsu[x] = fnd(dsu[x]);
}
void mrg(int x,int y){
    x = fnd(x), y = fnd(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x,y);
    dsu[y] = x;
    sz[x] += sz[y];
}
void dfs(int x){
    in[x] = idx++;
    for (auto i:e[x]) dfs(i);
    out[x] = idx++;
}
bool anc(int x,int y){
    return in[x] >= in[y] && out[x] <= out[y];
}
signed main(){
    IOS();
    int n,q;
    cin >> n >> q;
    int qid = 0, pid = 0;
    for (int i=0;i<q;++i) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int x,y;
            cin >> x >> y;
            x--, y--;
            e[y].eb(x);
            ind[x]++;
            v.eb((query){1,x,y});
        }
        else if (cmd == 2) {
            int x;
            cin >> x;
            x--;
            p[pid++] = x;
            v.eb((query){2,x,0});
        }
        else {
            int x,y;
            cin >> x >> y;
            x--, y--;
            Q[y].eb(x,qid++);
            v.eb((query){3,x,y});
        }
    }

    for (int i=0;i<n;++i) {
        dsu[i] = i;
        sz[i] = 1;
        if (ind[i] == 0) dfs(i);
    }
    
    pid = 0;
    for (int i=0;i<q;++i) {
        if (v[i].t == 1) {
            mrg(v[i].x,v[i].y);
        }
        else if (v[i].t == 2) {
            int cur = v[i].x;
            for (auto qi:Q[pid]) {
                if (fnd(cur) != fnd(qi.X)) {
                    ans[qi.Y] = false;
                    continue;
                }
                if (anc(cur,qi.X)) ans[qi.Y] = true;
                else ans[qi.Y] = false;
            }
            pid++;
        }
    }
    for (int i=0;i<qid;++i) {
        cout << (ans[i] ?"YES":"NO") << endl;
    }
}
