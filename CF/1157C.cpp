#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
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

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll d[MAXn],L[MAXn],R[MAXn];
int main(){
    IOS();
    ll n;
    cin >> n;
    REP (i,n) cin >> d[i];
    L[n-1] = 1;
    for (ll i=n-2;i>=0;i--) {
        if (d[i] < d[i+1]) L[i] = L[i+1] + 1;
        else L[i] = 1;
    }
    R[0] = 1;
    REP1 (i,n-1) {
        if (d[i] < d[i-1]) R[i] = R[i-1] + 1;
        else R[i] = 1;
    }
    pary(L,L+n);
    pary(R,R+n);

    ll l=0,r=n-1;
    ll cur = 0;
    string s = "";
    for (;l<r;) {
        debug(l,r,cur);
        if (d[l] == d[r]) {
            if (d[l] <= cur) break;
            if (min(L[l],r-l+1) > min(R[r],r-l+1)) {
                REP (i,min(L[l],r-l+1)) s += "L";
            }
            else {
                REP (i,min(R[r],r-l+1)) s += "R";
            }
            break;
        }
        else {
            if (d[l] < d[r]) {
                if (d[l] > cur) {
                    s += "L";
                    cur = d[l++];
                }
                else if (d[r] > cur) {
                    s += "R";
                    cur = d[r--];
                }
                else break;
            }
            else {
                if (d[r] > cur) {
                    s += "R";
                    cur = d[r--];
                }
                else if (d[l] > cur) {
                    s += "L";
                    cur = d[l++];
                }
                else break;
            }
        }
    }
    if (l == r && d[l] > cur) s += "L";
    cout << SZ(s) << endl;
    cout << s << endl;
}
