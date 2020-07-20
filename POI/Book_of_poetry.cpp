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

const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int n,s;
int d[MAXn];
vector<int> v,box[MAXn];
set<ii> st;
vector<int> pans;
int cur,ans;
void gogo(int x){
    st.erase(ii(SZ(box[x]),x));
    pans.eb(box[x].back());
    box[x].pop_back();
    if (SZ(box[x])) st.insert(ii(SZ(box[x]),x));
    cur += x;
    if (cur >= s) cur -= s;
    if (cur == s-1) cur = 0;
}
int main(){
    IOS();
    cin >> n >> s;
    REP (i,n) {
        cin >> d[i];
        d[i]++;
        d[i] %= s;
        box[d[i]].eb(i);
    }
    REP (i,s+1) {
        if (SZ(box[i])) st.insert(ii(SZ(box[i]),i));
    }
    REP (i,n-1) {
        int num = s-1-cur;
        if (SZ(box[num]) == n-i) {
            gogo(num);
            ans++;
        }
        else {
            auto it = st.rbegin();
            if (it->Y == num) it++;
            gogo(it->Y);
        }
    }
    debug(SZ(st));
    gogo(st.begin()->Y);
    cout << ans << endl;
    REP (i,n) cout << pans[i]+1 << " \n"[i==n-1];
}
