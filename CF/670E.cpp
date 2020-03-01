#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (ll)a.size()
#define ALL(a) a.begin(),a.end()
#define eb emplace_back
#define X first
#define Y second
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S>void _do(T &&_x,S &&..._t){cerr<<_x<<", ";_do(_t...);}
#define IOS()
#else
#define debug(...)
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif

const ll MAXn=5e5+5;

int pp[MAXn];
int main(){
    IOS();
    int n,m,p;
    cin >> n >> m >> p;
    string s;
    cin >> s;
    string cmd;
    cin >> cmd;

    vector<int> stk;
    REP (i,n) {
        if (s[i] == '(') stk.eb(i);
        else {
            int cur = stk.back();
            stk.pop_back();
            pp[cur] = i;
            pp[i] = cur;
            debug(i,cur);
        }
    }
    set<int> st;
    REP (i,n) st.insert(i);

    p--;
    REP (i,m) {
        if (cmd[i] == 'L') {
            auto it = st.lower_bound(p);
            it--;
            p = *it;
        }
        else if (cmd[i] == 'R') {
            auto it = st.upper_bound(p);
            p = *it;
        }
        else {
            int l = pp[p];
            if (l > p) swap(l,p);
            while (1) {
                auto it = st.lower_bound(l);
                if (it == st.end()) break;
                if (*it <= p) {
                    l = *it;
                    st.erase(it);
                }
                else break;
            }
            auto it = st.lower_bound(max(l,p));
            if (it == st.end()) it--;
            p = *it;
        }
    }
    string ans = "";
    for (auto i:st) ans += s[i];
    cout << ans << endl;
}
