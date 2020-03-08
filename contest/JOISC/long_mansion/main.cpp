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
#define SZ(a) (ll)a.size()
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

const ll MAXn=5e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int n;
int c[MAXn];
vector<int> key[MAXn];
int ld[MAXn],rd[MAXn];
int L[MAXn],R[MAXn];
bool lchk(int x){
    return L[x] > 0 && rd[L[x]-1] != n && rd[L[x]-1] <= R[x];
}
bool rchk(int x){
    return R[x] < n-1 && ld[R[x]] != -1 && ld[R[x]] >= L[x];
}
int main(){
    IOS();
    cin >> n;
    REP (i,n-1) cin >> c[i];
    REP (i,n) {
        int x;
        cin >> x;
        REP (j,x) {
            int type;
            cin >> type;
            key[type].eb(i);
        }
    }

    REP (i,n-1) {
        if (!SZ(key[c[i]])) {
            ld[i] = -1;
            rd[i] = n;
            continue;
        }
        int it = (int)(upper_bound(ALL(key[c[i]]),i) - key[c[i]].begin());
        if (it == 0) {
            ld[i] = -1;
            rd[i] = key[c[i]][it];
        }
        else if (it == SZ(key[c[i]])) {
            ld[i] = key[c[i]].back();
            rd[i] = n;
        }
        else {
            ld[i] = key[c[i]][it-1];
            rd[i] = key[c[i]][it];
        }
    }
    pary(ld,ld+n);
    pary(rd,rd+n);
    REP (i,n) {
        L[i] = R[i] = i;
        while (1) {
            if (lchk(i)) {
                R[i] = max(R[i],R[L[i]-1]);
                L[i] = min(L[i],L[L[i]-1]);
            }
            else if (rchk(i)) {
                R[i]++;
            }
            else break;
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x,y;
        cin >> x >> y;
        x--, y--;
        if (L[x] <= y && y <= R[x]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
