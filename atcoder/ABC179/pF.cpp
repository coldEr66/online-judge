#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
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
template<class T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll seg1[MAXn*2],seg2[MAXn*2];
void build(ll *zkw){
	for (int i=n-1; i>0; i--) {
		zkw[i] = min(zkw[i<<1],zkw[i<<1|1]);
	}
}

void modify(int l,int r, ll value, ll *zkw) {
    for (l += n, r += n; l < r;l>>=1, r>>=1) {
        if (l&1) zkw[l] = min(zkw[l],value),l++;
        if (r&1) r--,zkw[r] = min(zkw[r],value);
    }
}

int query(int p,ll *zkw) {
    ll res = INF;
    for (p += n; p > 0; p >>= 1) res = min(res,zkw[p]);
    return res;
}
int main(){
    IOS();
    cin >> n >> q;
    debug(n);
    for (int i=0;i<n;++i) seg1[i+n] = seg2[i+n] = n-1;
    build(seg1), build(seg2);
    ll ans = (n-2) * (n-2);
    for (int i=0;i<q;++i) {
        ll cmd,x;
        cin >> cmd >> x;
        x--;
        if (cmd == 1) {
            ll tmp = query(x,seg1);
            ans -= (tmp-1);
            modify(1,tmp+1,x,seg2);
        }
        else {
            ll tmp = query(x,seg2);
            ans -= (tmp - 1);
            modify(1,tmp+1,x,seg1);
        }
    }
    cout << ans << endl;
}
