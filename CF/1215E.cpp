#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
#define REP(i,n) for(ll i=0;i<n;i++)
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

const ll MAXn=4e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll MAXm=21;

ll dp[(1LL<<MAXm)];
ll cnt[MAXm][MAXm];
vector<ll> v[MAXm];
int main(){
    IOS();
    ll n;
    cin >> n;
    REP (i,n) {
        ll x;
        cin >> x;
        x--;
        v[x].eb(i);
    }
    REP (i,20) REP (j,20) {
        if (i == j) continue;
        if (SZ(v[i]) == 0 || SZ(v[j]) == 0) continue;
        ll idx = 0;
        REP (k,SZ(v[i])) {
            while (idx < SZ(v[j])-1 && v[j][idx+1] < v[i][k]) idx++;
            if (v[i][k] > v[j][idx]) cnt[j][i] += idx+1;
        }
    }

    REP (i,(1LL<<MAXm)) dp[i] = INF;
    dp[0] = 0;
    REP (I,(1LL<<MAXm)) {
        vector<ll> one;
        REP (i,MAXm) if (I & (1<<i)) one.eb(i);
        REP (i,MAXm) {
            if (I & (1<<i)) continue;
            ll sum = 0;
            REP (j,SZ(one)) sum += cnt[i][one[j]];
            ll nxtI = I | (1<<i);
            dp[nxtI] = min(dp[nxtI],dp[I] + sum);
        }
    }
    cout << dp[(1LL<<20)-1] << endl;
}
