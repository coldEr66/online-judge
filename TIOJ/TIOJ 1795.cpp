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

const ll MaxN=1e5+5;
const ll MOD=1000000007;
const ll INF=ll(1e15);

struct Edge{
	ll a,b,w;
} e[MaxN*3];

bool operator<(Edge a,Edge b){
	return a.w<b.w;
}
bool operator>(Edge a,Edge b){
	return a.w>b.w;
}

ll d[MaxN];
ll sz[MaxN];

ll find(ll x){
	return x==d[x] ?x:d[x]=find(d[x]);
}

void mer(ll x,ll y){
	if(x<y) swap(x,y);
	sz[find(x)]+=sz[find(y)];
	sz[find(y)]=0;
	d[find(y)]=find(x);
}

int main(){
	IOS();
	ll n,m,k;
	cin>>n>>m>>k;
	ll chk=0;
	REP(i,m){
		cin>>e[i].a>>e[i].b>>e[i].w;
		e[i].a--;
		e[i].b--;
		if(e[i].w==1) chk++;
	}
	if(chk<k){
		cout<<"NIE"<<endl;
		return 0;
	}
	REP(i,n){
		d[i]=i;
		sz[i]=1;
	}
	sort(e,e+m);
	REP(i,m) debug(e[i].w);
	ll mn=0;
	for(int i=0,j=0;i<n&&j<m;j++){
		if(find(e[j].a)==find(e[j].b)) continue;
		mer(e[j].a,e[j].b);
		mn+=e[j].w;
		i++;
	}
	sort(e,e+m,greater<Edge>());
	REP(i,m) debug(e[i].w);
	REP(i,n){
		d[i]=i;
		sz[i]=1;
	}
	ll mx=0;
	for(int i=0,j=0;i<n&&j<m;j++){
		if(find(e[j].a)==find(e[j].b)) continue;
		mer(e[j].a,e[j].b);
		mx+=e[j].w;
		i++;
	}
	debug(mn,mx);
	pary(sz,sz+n);
	if(sz[find(0)]!=n){
		cout<<"NIE"<<endl;
		return 0;
	}
	debug("tree");
	if(k>=mn&&k<=mx) cout<<"TAK"<<endl;
	else cout<<"NIE"<<endl;
}

