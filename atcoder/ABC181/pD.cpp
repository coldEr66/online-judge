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

int cnt[11];
string s;
bool chk(int x){
    int ct = 0;
    vector<int> tmp(11,0);
    while (x) {
        ct++;
        tmp[x % 10]++;
        x /= 10;
    }
    
    if (ct != 3 || tmp[0] != 0) return false;
    bool fg = true;
    for (int i=1;i<=9;++i) {
        if (cnt[i] < tmp[i]) fg = false;
    }
    return fg;
}
signed main(){
    IOS();
    cin >> s;
    for (int i=0;i<SZ(s);++i) {
        cnt[s[i] - '0']++;
    }
    if (SZ(s) <= 3) {
        sort(ALL(s));
        do {
            int cur = stoi(s);
            if (cur % 8 == 0) return cout << "Yes" << endl,0;
        } while (next_permutation(ALL(s)));
        return cout << "No" << endl,0;
    }
    for (int i=8;i<=992;i+=8) {
        if (chk(i)) return cout << "Yes" << endl,0;
    }
    cout << "No" << endl;
}
