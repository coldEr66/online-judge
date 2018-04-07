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

const ll MaxN=1e3+5;
const ll MOD=1000000007;
const ll INF=(ll)1e18;

ll n,m;
ll g[MaxN][MaxN];
bool visited[MaxN][MaxN];
ll sz[MaxN*MaxN];
ll gp[MaxN][MaxN];
ll dx[]={1,0,0,-1};
ll dy[]={0,1,-1,0};
ll ans;
ll u=-1;
void init(){
	cin>>n>>m;
	REP(i,n)REP(j,m) cin>>g[i][j];
}
bool out(ll a,ll b){
	if(a<0||a>=n||b<0||b>=m) return false;
	return true;
}
void bfs(ll x,ll y){
	u++;
	debug(u); 
	queue<ii> q;
	q.push(MP(x,y));
	visited[x][y]=true;
	gp[x][y]=u;
	ll cnt=1;
	while(SZ(q)){
		ii cur=q.front();
		q.pop();
		REP(i,4){
			ll a=cur.F+dx[i];
			ll b=cur.S+dy[i];
			if(!out(a,b)) continue;
			if(visited[a][b]) continue;
			if(g[a][b]==0) continue;
			debug(a,b);
			cnt++;
			gp[a][b]=u;
			debug(u);
			visited[a][b]=true;
			q.push(MP(a,b));
		}
	}
	sz[u]=cnt;
	debug(sz[u],x,y);
}
void build(){
	REP(i,n)REP(j,m){
		if(visited[i][j]) continue;
		if(g[i][j]==0) continue;
		bfs(i,j);
	}
}
ll tmp;
void sol(){
	REP(i,n)REP(j,m){
		if(g[i][j]) continue;
		debug(i,j);
		tmp=1;
		set<int> st;
		REP(k,4){
			ll a=i+dx[k];
			ll b=j+dy[k];
			if(!out(a,b)) continue;
			if(g[a][b]==0) continue;
			st.insert(gp[a][b]);
			debug(a,b,gp[a][b]);
		}
		debug(st);
		for(set<int>::iterator it=st.begin();it!=st.end();it++) tmp+=sz[*it];
		debug(tmp);
		ans=max(ans,tmp);
	}
	pary(sz,sz+10);
	REP(i,n)REP(j,m){
		debug(gp[i][j]);
	}
	cout<<ans<<endl;
}

int main(){
	IOS();
	init();
	build();
	sol();
	return 0;
}

