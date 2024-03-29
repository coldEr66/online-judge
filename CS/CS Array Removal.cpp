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

ll n,tmp;
ll d[MAXn],ord[MAXn],fa[MAXn],sz[MAXn],sum[MAXn];
vector<ll> ans;
ll find(ll x){
	//debug(x);
	return x==fa[x] ?x:fa[x]=find(fa[x]);
}
void mer(ll x,ll y){
	//debug(x,y);
	ll a=find(x),b=find(y);
	//debug(a,b);
	if(sz[a]<sz[b]) swap(a,b);
	fa[b]=a;
	sz[a]+=sz[b];
	sum[a]+=sum[b];
	tmp=max(tmp,sum[a]);
	//debug(tmp);
}
void init(){
	cin>>n;
	REP(i,n) cin>>d[i];
	REP(i,n){
		cin>>ord[i];
		ord[i]--;
	}
	REP(i,n) fa[i]=-1;
}
bool in(ll pos){
	if(pos<0 || pos>=n) return false;
	return true;
}
void build(){
	
}

void sol(){
	for(int i=n-1;i>=0;i--){
		ll cur=ord[i];
		sz[cur]=1;
		fa[cur]=cur;
		sum[cur]=d[cur];
		tmp=max(tmp,sum[cur]);
		debug(tmp);
		if(in(cur+1) && fa[cur+1]!=-1) mer(cur,cur+1);
		if(in(cur-1) && fa[cur-1]!=-1) mer(cur,cur-1);
		ans.pb(tmp);
		debug("hi");
	}
	reverse(ALL(ans));
	REP(i,n) cout<<ans[i]<<endl;
}

int main(){
	IOS();
	init();
	build();
	sol();
	return 0;
}

