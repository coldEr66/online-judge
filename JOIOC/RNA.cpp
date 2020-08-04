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

const ll MAXn=2e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

map<char,char> mp;
string s[MAXn],pre[MAXn],suf[MAXn];
int edg[MAXn][4],node;
int idx,in[MAXn],out[MAXn],rin[MAXn];
vector<int> dst[MAXn];
vector<ii> qr[MAXn];
int cnt[MAXn],ans[MAXn];
void gen(string &str){
    for (auto &c:str) c = mp[c];
}
int add(string str){
    int cur = 0;
    for (auto c:str) {
        int nxt = c-'0';
        if (edg[cur][nxt] == 0) edg[cur][nxt] = ++node;
        cur = edg[cur][nxt];
        cnt[cur]++;
    }
    return cur;
}
void dfs(int x){
    in[x] = idx++;
    rin[in[x]] = x;
    REP (i,4) if (edg[x][i]) dfs(edg[x][i]);
    out[x] = idx;
}
int gt(string str){
    int cur = 0;
    for (auto c:str) {
        cur = edg[cur][c-'0'];
        if (cur == 0) break;
    }
    return cur;
}
int main(){
    IOS();
    int n,q;
    cin >> n >> q;
    mp['A'] = '0', mp['G'] = '1', mp['C'] = '2', mp['U'] = '3';
    REP (i,n) {
        cin >> s[i];
        gen(s[i]);
        debug(s[i]);
        int cur = add(s[i]);
        dst[cur].eb(i);
        reverse(ALL(s[i]));
    }
    dfs(0);

    REP (i,q) {
        cin >> pre[i] >> suf[i];
        gen(pre[i]), gen(suf[i]);
        int cur = gt(pre[i]);
        if (cur) {
            qr[in[cur]].eb(-1,i);
            qr[out[cur]].eb(1,i);
            reverse(ALL(suf[i]));
        }
    }

    RST(edg,0), RST(cnt,0), node = 0;
    REP (i,idx+1) {
        for (auto Q:qr[i]) {
            int cur = gt(suf[Q.Y]);
            if (cur) ans[Q.Y] += Q.X * cnt[cur];
        }
        for (auto it:dst[rin[i]]) add(s[it]);
    }
    REP (i,q) cout << ans[i] << endl;
}
