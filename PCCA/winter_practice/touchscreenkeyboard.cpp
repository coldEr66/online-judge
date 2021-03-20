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

const ll MAXN=1e5+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;


string mp[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
int dis[27][27];
void addedge(char a,char b){
    int u = a - 'a', v = b - 'a';
    dis[u][v] = dis[v][u] = 1;
}
void build(){
    for (int i=0;i<26;++i) for (int j=0;j<26;++j) {
        if (i == j) dis[i][j] = 0;
        else dis[i][j] = INF;
    }
    for (int i=0;i<3;++i) {
        for (int j=0;j<SZ(mp[i])-1;++j) {
            addedge(mp[i][j], mp[i][j+1]);            
        }
    }
    for (int i=0;i<SZ(mp[0]);++i) {
        if (i < SZ(mp[1])) {
            addedge(mp[0][i], mp[1][i]);
            if (i < SZ(mp[2])) {
                addedge(mp[1][i], mp[2][i]);
            }
        }
    }
    for (int k=0;k<26;++k) {
        for (int i=0;i<26;++i) {
            for (int j=0;j<26;++j) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}
signed main(){
    IOS();
    build();
    int t;
    cin >> t;
    while (t--) {
        string s;
        int l;
        cin >> s >> l;
        vector<pair<int, string>> v;
        while (l--) {
            string cur;
            cin >> cur;
            int ans = 0;
            for (int i=0;i<SZ(cur);++i) {
                ans += dis[s[i]-'a'][cur[i]-'a'];
            }
            v.eb(ans, cur);
        }
        sort(ALL(v));
        for (int i=0;i<SZ(v);++i) {
            cout << v[i].Y << ' ' << v[i].X << endl;
        }
    }
}
