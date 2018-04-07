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

ll n,m,x;
vector<ii> g[MaxN];
void init(){
	cin>>n>>m>>x;
	REP(i,m){
		ll a,b,w;
		cin>>a>>b>>w;
		a--,b--;
		g[a].pb(MP(b,w));
		g[b].pb(MP(a,w));
	}
}
bool visited[MaxN];
ll bfs(ll mx){
	REP(i,n) visited[i]=false;
	queue<ll> q;
	ll ret=0;
	REP(i,n){
		if(visited[i]) continue;
		q.push(i);
		visited[i]=true; 
		ll cnt=1;
		while(SZ(q)){
			ll now=q.front();
			q.pop();
			REP(j,SZ(g[now])){
				ii u=g[now][j];
				if(u.S>mx) continue;
				if(visited[u.F]) continue;
				visited[u.F]=true;
				q.push(u.F);
				cnt++;
			}
		}
		ret+=cnt*(cnt-1)/2;
		debug(ret,cnt);
	}
	return ret;
}
void build(){
	
}

void sol(){
	ll a=bfs(x);
	ll b=bfs(x-1);
	ll ans=a-b;
	cout<<ans<<endl;
}

int main(){
	IOS();
	init();
	build();
	sol();
	return 0;
}

