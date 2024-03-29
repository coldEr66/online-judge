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
#define F first
#define S second
#define pb push_back
#define pob pop_back
#define MP make_pair
#define VI vector<int>
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.F<<","<<_p.S<<")";}
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

const ll MAXn=200005;
const ll MOD=1000000007;
const ll INF=(ll)1e18;

vector<ll> v[2];
vector<ll> ans;
set<ll> st;

int main(){
	IOS();
	string s;
	cin>>s;
	ll n=SZ(s);
	REP(i,n){
		if(s[i]=='0') v[0].pb(i+1);
		if(s[i]=='1') v[1].pb(i+1);
	}
	REP1(i,n) st.insert(i);
	REP(i,n-1)if(s[i]=='1' && s[i+1]=='1') return cout<<-1<<endl,0;
	reverse(ALL(v[0]));
	reverse(ALL(v[1]));
	if(s[0]=='1' || s[n-1]=='1') return cout<<-1<<endl,0;
	bool c=true;
	ll tmp=0,f,u;
	while(SZ(v[0])){
		f=v[0].back();
		u=v[1].back();
		if(c){
			while(SZ(v[0]) && v[0].back()<tmp){
				v[0].pob();
				if(!SZ(v[0]))
				f=v[0].back();
			}
			ans.pb(f);
			st.erase(f);
			v[0].pob();
			tmp=f;
		}
		else if(!c && SZ(v[1])){
			ans.pb(u);
			v[1].pob();
			tmp=u;
			st.erase(u);
			if(!SZ(v[1])){
				ans.pb(u+1);
				st.erase(u+1);
				break;
			}
		}
		c=!c;
	}
	cout<<SZ(st)+1<<endl;
	cout<<SZ(ans);
	REP(i,SZ(ans)) cout<<' '<<ans[i];
	cout<<endl;
	for(auto it:st) cout<<1<<' '<<it<<endl;
}

