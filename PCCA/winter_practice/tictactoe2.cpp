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


int dp[MAXN], thr[11];
int tic[11]; // 0: .  1: X  2: O
int d[8][3] =  {{0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6}};
bool chk(){
    for (int i=0;i<8;++i) {
        bool ok = true;
        for (int j=0;j<2;++j) {
            if (tic[d[i][j]] != tic[d[i][j+1]]) ok = false;
        }
        if (ok && tic[d[i][0]] != 0) return false; 
    }
    return true;
}
int trans(){
    int ret = 0;
    for (int i=0;i<9;++i) {
        ret += tic[i] * thr[i];
    }
    return ret;
}
void gogo(int cur, bool turn = 0){
    if (dp[cur]) return;
    dp[cur] = true;
    for (int i=0;i<9;++i) {
        if (tic[i] == 0) {
            int op;
            if (!turn) op = 1;
            else op = 2;
            tic[i] = op;
            int nxt = trans();
            if (chk()) gogo(nxt, !turn);
            else dp[nxt] = true;
            tic[i] = 0;
        }
    }
}
void build(){
    thr[0] = 1;
    for (int i=1;i<9;++i) thr[i] = thr[i-1] * 3;
    gogo(0);
}
signed main(){
    IOS();
    build();
    int q;
    cin >> q;
    while (q--) {
        int val = 0;
        for (int i=0;i<9;++i) {
            char c;
            cin >> c;
            int cur;
            if (c == '.') cur = 0;
            else if (c == 'X') cur = 1;
            else cur = 2;
            val += thr[i] * cur;
        }
        if (dp[val]) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
