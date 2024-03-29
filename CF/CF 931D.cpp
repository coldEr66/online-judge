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

template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

const ll MAXn=1e5+5;
const ll MOD=1000000007;
const ll INF=(ll)1e18;

vector<ll> g[MAXn];
ll dis[MAXn];
ll ans[MAXn];

int main(){
	IOS();
	ll n;
	ll cnt=0;
	cin>>n;
	REP(i,MAXn) dis[i]=INF;
	for(int i=2;i<=n;i++){
		ll x;
		cin>>x;
		g[x].pb(i);
	}
	debug("OK");
	queue<ll> q;
	q.push(1LL);
	dis[1]=0;
	while(SZ(q)){
		ll cur=q.front();
		q.pop();
		for(auto it:g[cur]){
			if(dis[cur]+1<dis[it]){
				dis[it]=dis[cur]+1;
				q.push(it);
			}
		}
	}
	debug("hi");
	ll r=-INF;
	REP(i,MAXn){
		if(dis[i]!=INF){
			r=max(r,dis[i]);
		}
	}
	debug("TEST");
	REP(i,MAXn){
		if(dis[i]!=INF){
			ans[dis[i]]++;
			ans[dis[i]]%=2;
		}
	}
	debug("a");
	REP(i,r+1){
		if(ans[i]&1) cnt++;
	}
	debug("ok");
	cout<<cnt<<endl;
}

