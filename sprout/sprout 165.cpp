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

const ll MAXn=1e5+5;
const ll MOD=1000000007;
const ll INF=(ll)1e18;

ll n,m,cnt;
ll in[MAXn];
VI g[MAXn];
VI ans;
void init(){
	REP(i,MAXn)while(SZ(g[i])) g[i].clear();
	ans.clear();
	RST(in,0);
	cin>>n>>m;
	cnt=n;
	REP(i,m){
		ll a,b;
		cin>>a>>b;
		g[a].pb(b);
		in[b]++;
	}
	REP(i,n) sort(ALL(g[i]));
}

void build(){
	
}
priority_queue<ll,vector<ll>,greater<ll>> q;
void bfs(){
	while(SZ(q)){
		ll cur=q.top();
		q.pop();
		cnt--;
		debug(cur);
		ans.pb(cur);
		REP(i,SZ(g[cur])){
			ll x=g[cur][i];
			in[x]--;
			//debug(x,in[x]);
			if(in[x]==0) q.push(x);
		}
		/*
		queue<ll> tmp=q;
		while(SZ(tmp)){
			cout<<tmp.front()<<' ';
			tmp.pop();
		}
		*/
	}
}
void sol(){
	ll tmp;
	REP(i,n)if(in[i]==0) q.push(i);
	bfs();
	debug(cnt);
	if(cnt!=0) cout<<"QAQ";
	else REP(i,SZ(ans)){
		if(i==0) cout<<ans[i];
		else cout<<' '<<ans[i];
	}
	cout<<endl;
}

int main(){
	IOS();
	ll t;
	cin>>t;
	while(t--){
		init();
		sol();
	}
}

