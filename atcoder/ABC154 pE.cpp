#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for (int i=n-1;i>=0;i--)
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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int gt(int k){
    int ret = 1;
    REP (i,k) ret *= 9;
    return ret;
}
int C(int n,int m){
    int ret = 1;
    REP (i,m) ret *= (n-i);
    REP (i,m) ret /= (i+1);
    debug(n,m,ret);
    return ret;
}
int main(){
    IOS();
    string s;
    cin >> s;
    int k;
    cin >> k;
    if (SZ(s) < k) return cout << 0 << endl,0;
    int tp = s[0] - '0';
    int ans = 0;
    ans += C(SZ(s)-1,k) * gt(k);
    ans += (tp-1) * C(SZ(s)-1,k-1) * gt(k-1);
    debug(ans);
    if (k == 1) ans++;
    else if (k == 2) {
        int idx = SZ(s);
        REP1 (i,SZ(s)-1) {
            if (s[i] != '0') {
                idx = i;
                break;
            }
        }
        if (idx != SZ(s)) {
            int len = SZ(s) - idx - 1;
            ans += C(len,1) * gt(1);
            ans += (s[idx]-'0');
        }
    }
    else {
        ii idx = ii(SZ(s)-1,SZ(s));
        REP1 (i,SZ(s)-1) {
            if (s[i] != '0') {
                if (idx.X == SZ(s)-1) {
                    idx.X = i;
                }
                else if (idx.Y == SZ(s)) {
                    idx.Y = i;
                    break;
                }
            }
        }
        debug(idx);
        if (idx.X != SZ(s)-1) {
            int len = SZ(s) - idx.X - 1;
            if (len >= 2) ans += C(len,2) * gt(2);
            ans += (s[idx.X]-'0'-1) * C(len,1) * gt(1);
            if (idx.Y != SZ(s)) {
                int len1 = SZ(s) - idx.Y - 1;
                if (len1 >= 1) ans += C(len1,1) * gt(1);
                ans += (s[idx.Y] - '0');
            }
        }
    }
    cout << ans << endl;
}
