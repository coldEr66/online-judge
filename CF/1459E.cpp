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

const ll MAXN=1e3+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int d[3][MAXN*MAXN];
int ans[MAXN][MAXN];
int zero[3], dir[3];
signed main(){
    IOS();
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        int idx = 0;
        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                int x;
                cin >> x;
                x--;
                d[0][idx] = i, d[1][idx] = j, d[2][idx++] = x;
            }
        }
        for (int i=0;i<3;++i) {
            dir[i] = i;
            zero[i] = 0;
        }
        string s;
        cin >> s;
        for (int i=0;i<m;++i) {
            if (s[i] == 'R') {
                zero[dir[1]]++;
                if (zero[dir[1]] >= n) zero[dir[1]] -= n;
            }
            if (s[i] == 'L') {
                zero[dir[1]]--;
                if (zero[dir[1]] < 0) zero[dir[1]] += n;
            }
            if (s[i] == 'D') {
                zero[dir[0]]++;
                if (zero[dir[0]] >= n) zero[dir[0]] -= n;
            }
            if (s[i] == 'U') {
                zero[dir[0]]--;
                if (zero[dir[0]] < 0) zero[dir[0]] += n;
            }
            if (s[i] == 'I') {
                swap(dir[1], dir[2]);
            }
            if (s[i] == 'C') {
                swap(dir[0], dir[2]);
            }
        }
        int vx = dir[0], vy = dir[1], vz = dir[2];
        for (int i=0;i<idx;++i) {
            d[vx][i] += zero[vx];
            d[vy][i] += zero[vy];
            d[vz][i] += zero[vz];
            d[vx][i] %= n;
            d[vy][i] %= n;
            d[vz][i] %= n;
            ans[d[vx][i]][d[vy][i]] = d[vz][i];
        }
        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                cout << ans[i][j] + 1 << " \n"[j==n-1];
            }
        }
        cout << endl;
    }
}
