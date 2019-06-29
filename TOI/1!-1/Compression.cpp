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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

string s;
ll n,l;
ll x,y,u,v,b;
ll cur;
bool chk(ll r1,ll c1,ll r2,ll c2){
    if (r1 > u || r2 < x || c1 > v || c2 < y) return false;
    return true;
}
string add(ll r1,ll c1,ll r2,ll c2,char color){
    debug(r1,c1,r2,c2);
    if (r1 >= x && c1 >= y && r2 <= u && c2 <= v) {
        debug(r1,c1,r2,c2);
        debug("HI");
        string ret = "";
        ret += char(b+'0');
        return ret;
    }
    if (!chk(r1,c1,r2,c2)) {
        debug("ALIVE");
        // debug(r1,c1,r2,c2);
        string ret = "";
        ret += color;
        return ret;
    }
    // debug("ADD");
    string ret = "";
    ret += '2';
    ll r = (r1+r2)>>1, c = (c1+c2)>>1;
    // debug(r,c);
    REP (i,4) {
        if (i == 0) ret += add(r1,c1,r,c,color);
        if (i == 1) ret += add(r1,c+1,r,c2,color);
        if (i == 2) ret += add(r+1,c1,r2,c,color);
        if (i == 3) ret += add(r+1,c+1,r2,c2,color);
    }
    bool ok = false;
    debug(ret);
    REP1 (i,4) {
        if (ret[i] == '2') {
            ok = true;
            break;
        }
        else if (ret[i] != ret[1]) {
            ok = true;
            break;
        }
    }
    debug(ret);
    if (ok) return ret;
    string tmp = "";
    tmp += ret[1];
    return tmp;
}
string dfs(ll len,ll r1,ll c1,ll r2,ll c2){
    debug(r1,c1,r2,c2);
    // if (len == 1 && chk(r1,c1,r2,c2)) {
    //     debug("GO");
    //     char tmp = char(b+'0');
    //     string ret = "";
    //     ret += tmp;
    //     cur++;
    //     return ret;
    // }
    // else if (len == 1) {
    //     string ret = "";
    //     ret += s[cur++];
    //     return ret;
    // }
    string ret = "";
    if (s[cur] == '2') {
        ret += '2';
        cur++;
        ll r = (r1+r2)>>1, c = (c1+c2)>>1;
        debug(r,c);
        REP (i,4) {
            if (i == 0) ret += dfs(len/2,r1,c1,r,c);
            if (i == 1) ret += dfs(len/2,r1,c+1,r,c2);
            if (i == 2) ret += dfs(len/2,r+1,c1,r2,c);
            if (i == 3) ret += dfs(len/2,r+1,c+1,r2,c2);
        }
        bool ok = false;
        debug(ret);
        REP1 (i,4) {
            if (ret[i] == '2') {
                ok = true;
                break;
            }
            else if (ret[i] != ret[1]) {
                ok = true;
                break;
            }
        }
        debug(ret);
        if (ok) return ret;
        string tmp = "";
        tmp += ret[1];
        return tmp;
        // debug(ret);
    }
    if (chk(r1,c1,r2,c2)) {
        debug("INS",r1,c1,r2,c2);
        ret += add(r1,c1,r2,c2,s[cur]);
        debug(ret,"ALLY");
        cur++;
        return ret;
    }
    ret += s[cur++];
    // debug(ret);
    return ret;
}
int main(){
    IOS();
    cin >> n >> l;
    cin >> s;
    cin >> x >> y >> u >> v >> b;
    string ans = dfs(n,0,0,n-1,n-1);
    debug(cur);
    cout << ans << endl;
}
