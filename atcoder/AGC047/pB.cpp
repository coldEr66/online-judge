#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
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

const ll MAXN=3e6+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int idx = 0;
int trie[MAXN][26];
ll dp[MAXN][26],fg[MAXN][26];
string s[MAXN];
vector<int> stk;
int lst[26];
int ok[MAXN];
map<string,int> mp;
int id(char c){
    return c - 'a';
}
void ins(int cur,int add){
    for (auto it:stk) dp[cur][it] += add;
}
void add(int cur,int i,int j){
    ins(cur,-1);
    if (j != 0) {
        if (ok[j-1]) {
            stk.eb(id(s[i][j-1]));
        }
    } 
    if (j == SZ(s[i])) {
        ins(cur,1);
        return;
    }
    int nxt = id(s[i][j]);
    if (!trie[cur][nxt]) {
        idx++;
        trie[cur][nxt] = idx;
    }
    if (ok[j]) fg[trie[cur][nxt]][nxt]++;
    add(trie[cur][nxt],i,j+1);
    ins(cur,1);
}
ll cal(int num){
    int cur = 0;
    for (int i=0;i<SZ(s[num])-1;++i) {
        cur = trie[cur][id(s[num][i])];
    }
    ll ret = dp[cur][id(s[num].back())] - fg[cur][id(s[num].back())];
    return ret;
}
signed main(){
    IOS();
    int n;
    cin >> n;
    for (int i=0;i<n;++i) {
        stk.clear();
        for (int j=0;j<26;++j) {
            if (lst[j] == -1) continue;
            ok[lst[j]] = 0;
        }
        cin >> s[i];
        reverse(ALL(s[i]));
        mp[s[i]]++;
        RST(lst,-1);
        for (int j=0;j<SZ(s[i]);++j) {
            if (lst[id(s[i][j])] != -1) {
                ok[lst[id(s[i][j])]] = 0;
            }
            ok[j] = 1;
            lst[id(s[i][j])] = j;
        }
        add(0,i,0);
    }
    ll ans = 0;
    for (int i=0;i<n;++i) {
        ans += cal(i);
    }
    debug(ans);
    for (auto i:mp) ans -= i.Y * (i.Y-1) / 2;
    cout << ans - n << endl;
}
