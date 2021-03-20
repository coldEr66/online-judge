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

struct M{
    ll mat[3][3];
    M operator * (const M &a) const {
        M ret;
        for (int i=0;i<3;++i) for (int j=0;j<3;++j) {
            ret.mat[i][j] = 0;
            for (int k=0;k<3;++k) {
                ret.mat[i][j] += mat[i][k] * a.mat[k][j];
            }
        }
        return ret;
    }
};
pll d[MAXN];
M m[4];
M mm[MAXN]; 
signed main(){
    IOS();
    ll n;
    cin >> n;
    for (int i=0;i<n;++i) {
        cin >> d[i].X >> d[i].Y;
    }

    for (int i=0;i<3;++i) for (int j=0;j<3;++j) {
        for (int k=0;k<4;++k) {
            m[k].mat[i][j] = 0;
            if (i == 2 && j == 2) m[k].mat[i][j] = 1;
        }
    }
    int op;
    cin >> op;
    m[0].mat[0][1] = 1, m[0].mat[1][0] = -1;
    m[1].mat[0][1] = -1, m[1].mat[1][0] = 1;
    m[2].mat[0][0] = -1, m[2].mat[1][1] = 1;
    m[3].mat[0][0] = 1, m[3].mat[1][1] = -1;
    for (int i=0;i<3;++i) {
        for (int j=0;j<3;++j) {
            if (i == j) mm[0].mat[i][j] = 1;
            else mm[0].mat[i][j] = 0;
        }
    }
    for (int i=1;i<=op;++i) {
        int cmd;
        cin >> cmd;
        for (int j=0;j<3;++j) for (int k=0;k<3;++k) {
            mm[i].mat[j][k] = 0;
        }
        if (cmd == 1) {
            mm[i] = m[0] * mm[i-1];
        }
        else if (cmd == 2) {
            mm[i] = m[1] * mm[i-1];
        }
        else if (cmd == 3) {
            ll p;
            cin >> p;
            m[2].mat[0][2] = 2 * p;
            mm[i] = m[2] * mm[i-1];
        }
        else {
            ll p;
            cin >> p;
            m[3].mat[1][2] = 2 * p;
            mm[i] = m[3] * mm[i-1];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int a,b;
        cin >> a >> b;
        M cur;
        for (int i=0;i<3;++i) for (int j=0;j<3;++j) {
            cur.mat[i][j] = 0;
        }
        cur.mat[0][0] = d[b-1].X, cur.mat[1][0] = d[b-1].Y, cur.mat[2][0] = 1;
        cur = mm[a] * cur;
        cout << cur.mat[0][0] << ' ' << cur.mat[1][0] << endl;
    }
}
