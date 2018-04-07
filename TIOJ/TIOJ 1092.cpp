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
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
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

const ll MaxN=1e4+5;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll out[MaxN];
vector<ll> graph[MaxN];
bool dp[MaxN];
string NAME[2]={"Moumou","Mimi"};
queue<ll> q;

string f(string s,bool fg){
	if(fg) return s;
	else{
		if(s==NAME[0]) return NAME[1];
		return NAME[0];
	}
}

int main(){
	IOS();
	ll n,m;
	string name;
	while(cin>>n>>m){
		if(n==0&&m==0) break;
		REP1(i,n)while(SZ(graph[i])) graph[i].pob();
		RST(out,0);
		RST(dp,0);
		REP(i,m){
			ll a,b;
			cin>>a>>b;
			out[a]++;
			graph[b].pb(a);
		}
		REP1(i,n) dp[i]=true;
		cin>>name;
		q.push(n);
		while(SZ(q)){
			ll cur=q.front();
			q.pop();
			if(dp[cur]==true){
				REP(i,SZ(graph[cur])){
					dp[graph[cur][i]]=false;
					out[graph[cur][i]]--;
					if(out[graph[cur][i]]==0) q.push(graph[cur][i]);
				}
			}
			else{
				REP(i,SZ(graph[cur])){
					out[graph[cur][i]]--;
					if(out[graph[cur][i]]==0) q.push(graph[cur][i]);
				}
			}
		}
		pary(dp+1,dp+n+1);
		debug(NAME[0]);
		string ans=f(name,dp[1]);
		cout<<ans<<endl;
	}
}

