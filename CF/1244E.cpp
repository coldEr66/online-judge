#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for (int i=n-1;i>=0;i--)
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

ii d[MAXn];
deque<ii> dq;
int main(){
    IOS();
    ll n,k;
    cin >> n >> k;
    REP (i,n) {
        cin >> d[i].X;
        d[i].Y = 1;
    }
    sort(d,d+n);
    REP (i,n-1) {
        if (d[i].X == d[i+1].X) {
            d[i+1].Y += d[i].Y;
        }
        else {
            dq.eb(d[i]);
        }
    }
    dq.eb(d[n-1]);
    ll cnt = 0;
    while (1) {
        if (SZ(dq) == 1) break;
        if (dq.front().Y < dq.back().Y) {
            ii cur = dq.front();
            dq.pop_front();
            debug(cur);
            ll diff = dq.front().X - cur.X;
            if (cnt + diff * cur.Y <= k) {
                cnt += diff * cur.Y;
                dq.front().Y += cur.Y;
            }
            else {
                ll tmp = k - cnt;
                tmp /= cur.Y;
                debug(tmp);
                cur.X += tmp;
                dq.emplace_front(cur);
                break;
            }
        }
        else {
            ii cur = dq.back();
            dq.pop_back();
            debug(cur);
            ll diff = cur.X - dq.back().X;
            if (cnt + diff * cur.Y <= k) {
                cnt += diff * cur.Y;
                dq.back().Y += cur.Y;
            }
            else {
                ll tmp = k - cnt;
                tmp /= cur.Y;
                debug(tmp,cur);
                cur.X -= tmp;
                dq.eb(cur);
                break;
            }
        }
    }
    debug(dq.back(),dq.front());
    cout << dq.back().X - dq.front().X << endl;
}
