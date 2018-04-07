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

const ll MaxN=1e5+5;
const ll MOD=1000000007;
const ll INF=(ll)1e18;

ll n,k;
vector<ii> g[MaxN];
ll cnt[MaxN];
void init(){
	cin>>n>>k;
	REP(i,n-1){
		ll a,b,w;
		cin>>a>>b>>w;
		a--,b--;
		g[a].pb(MP(b,w));
		g[b].pb(MP(a,w));
	}
}
bool visited[MaxN];
ll sz[MaxN];
VI tr;
void dfs(ll x,bool t){
	visited[x]=true;
	sz[x]=1;
	REP(i,SZ(g[x])){
		ii cur=g[x][i];
		if(visited[cur.F]) continue;
		dfs(cur.F,t && (cur.S==0));
		sz[x]+=sz[cur.F];
		if(cur.S==1 && t) tr.pb(sz[cur.F]);
	}
}
void build(){

}

void sol(){
	dfs(0,true);
	sort(ALL(tr),greater<int>());
	ll cnt=0;
	ll ans=0;
	REP(i,SZ(tr)){
		if(ans>=n-k) break;
		ans+=tr[i];
		cnt++;
	}
	if(ans>=n-k) cout<<cnt<<endl;
	else cout<<-1<<endl;
}

int main(){
	IOS();
	init();
	build();
	sol();
	return 0;
}

