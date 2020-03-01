#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
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

const ll MAXn=21,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int dp[1<<MAXn];
int d[1<<MAXn][MAXn];
int cnt[MAXn][MAXn];
int cbit[1<<MAXn];
int lbit[1<<MAXn];
int main(){
    IOS();
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    int U = (1<<m)-1;
    REP (i,n-1) {
        cnt[s[i]-'a'][s[i+1]-'a']++;
        cnt[s[i+1]-'a'][s[i]-'a']++;
    }

    REP1 (I,U) {
        REP (i,m) if (I & (1<<i)) {
            lbit[I] = i;
            break;
        }
    }
    REP1 (I,U) {
        cbit[I] = cbit[I&(I-1)] + 1;
        REP (i,m) {
            int it = lbit[I];
            d[I][i] = d[I ^ (1<<it)][i] + cnt[i][it];
        }
    }

    REP (i,U+1) dp[i] = INF;
    dp[0] = 0;
    REP (I,U+1) {
        REP (i,m) {
            if (I & (1<<i)) continue;
            int J = I | (1<<i);
            int pos = cbit[I];
            debug(I,pos);
            dp[J] = min(dp[J],dp[I] + pos * (d[I][i] - d[U ^ J][i]));
        }
    }
    cout << dp[U] << endl;
}
