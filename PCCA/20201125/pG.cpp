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

map<string,int> mp;
vector<string> v;
int gt(string s){
    int ret = 0;
    for (int i=0;i<SZ(s);++i) {
        ret = ret * 10 + s[i] - '0';
    }
    return ret;
}
signed main(){
    IOS();
    string tmp;
    while (getline(cin,tmp)) {
        v.clear();
        if (tmp == "0") break;
        int sum = 0;
        bool eq = false;
        for (int i=0;i<SZ(tmp);++i) {
            if (tmp[i] == '=') eq = true;
        }
        debug(eq);
        if (eq) {
            string s = "";
            int i;
            for (i=0;tmp[i] != ' ';++i) {
                s += tmp[i];
            }
            i += 3;
            string t = "";
            for (;i < SZ(tmp);++i) {
                t += tmp[i];
            }
            mp[s] = gt(t);
        }
        else {
            for (int i=0;i<SZ(tmp);++i) {
                string s = "";
                int idx = i;
                while (idx < SZ(tmp) && tmp[idx] != ' ') {
                    s += tmp[idx];
                    idx++;
                }
                if (s[0] >= '1' && s[0] <= '9') {
                    sum += gt(s);
                }
                else {
                    if (mp.count(s)) sum += mp[s];
                    else v.eb(s);
                }
                i = idx + 2;
            }
            if (sum > 0) {
                cout << sum;
                if (SZ(v)) cout << " + ";
            }
            for (int i=0;i<SZ(v);++i) {
                cout << v[i];
                if (i != SZ(v)-1) cout << " + ";
                else cout << endl;
            }
            if (!SZ(v)) cout << endl;
        }
    }
}
