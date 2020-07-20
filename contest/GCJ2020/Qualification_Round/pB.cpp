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

const ll MAXn=1e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int cnt;
int l[MAXn],r[MAXn];
vector<ii> v,tmp;
int main(){
    IOS();
    int t;
    cin >> t;
    while (t--) {
        cnt++;
        RST(l,0), RST(r,0);
        string s;
        cin >> s;
        int n = SZ(s);
        bool fg = true;
        REP (i,n) if (s[i] != '0') {
            fg = false;
            break;
        }
        if (fg) {
            cout << "Case #" << cnt << ": " << s << endl;
            continue;
        }
        s = ' ' + s;
        v.eb(1,n);
        REP (c,10) {
            char cur = char(c + '0');
            for (auto seg:v) {
                int lst = seg.X;
                while (lst <= seg.Y && s[lst] == cur) lst++;
                int rst = seg.Y;
                while (rst >= lst && s[rst] == cur) rst--;
                debug(lst,rst);
                int lb = lst;
                for (int i=lst;i<=rst;i++) {
                    if (s[i] == cur) {
                        l[lb-1]++, r[i-1]++;
                        tmp.eb(lb,i-1);
                        debug(lb,i-1);
                        int idx = i;
                        while (idx <= rst && s[idx] == s[i]) idx++;
                        lb = idx;
                        i = idx-1;
                    }
                }
                if (lb <= rst) {
                    l[lb-1]++, r[rst]++;
                    tmp.eb(lb,rst);
                    debug(lb,rst);
                }
            }
            v = tmp;
            vector<ii>().swap(tmp);
        }
        string ans = "";
        REP (i,n+1) {
            if (i) ans += s[i];
            REP (j,r[i]) ans += ')';
            REP (j,l[i]) ans += '(';
        }
        cout << "Case #" << cnt << ": " << ans << endl;
    }
}
