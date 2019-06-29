#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (int)a.size()
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

const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

vector<pair<string,ll> > v,a[MAXn],b[MAXn][5];
string vw = "aeiou";
bitset<MAXn> ok;
vector<string> d,dt;
ll gt(char c) {
    REP (i,5) if (c == vw[i]) return i;
    return -1;
}
int main(){
    IOS();
    ll n;
    cin >> n;
    REP (i,n) {
        string s;
        cin >> s;
        v.eb(s,i);
    }

    REP (i,n) {
        ll cnt = 0, lst = -1;
        REP (j,SZ(v[i].X)) {
            ll tmp = gt(v[i].X[j]);
            if (tmp == -1) continue;
            cnt++, lst = tmp;
        }
        a[cnt].eb(v[i]);
        b[cnt][lst].eb(v[i]);
    }
    ll A = 0, B = 0;
    REP (i,MAXn) {
        A += SZ(a[i])/2;
        REP (j,5) B += SZ(b[i][j])/2;
    }

    debug(A,B);
    ll ans = min(A/2,B);
    cout << ans << endl;
    ll cnt = 0;
    REP (i,MAXn) {
        REP (j,5) {
            if (SZ(b[i][j]) >= 2) {
                for (ll k=0;k+1<SZ(b[i][j]);k+=2) {
                    if (cnt == ans) break;
                    dt.eb(b[i][j][k].X);
                    dt.eb(b[i][j][k+1].X);
                    ok[b[i][j][k].Y] = true;
                    ok[b[i][j][k+1].Y] = true;
                    cnt++;
                }
            }
        }
    }

    REP (i,MAXn) {
        ll tmp = 0;
        string ss = "";
        REP (j,SZ(a[i])) {
            if (!ok[a[i][j].Y]) {
                if (tmp == 0) {
                    ss = a[i][j].X;
                    tmp++;
                }
                else {
                    tmp = 0;
                    d.eb(ss);
                    d.eb(a[i][j].X);
                }
            }
        }
    }
    debug(d,dt,SZ(d),SZ(dt));
    REP (i,2*ans) {
        cout << d[i] << ' ' << dt[i] << endl;
    }
}
