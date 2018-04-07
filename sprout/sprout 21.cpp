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

ll a[MaxN],b[MaxN];
bool ok[MaxN];
ll n,m;
void init(){
	cin>>n>>m;
	REP1(i,n){
		a[i]=i-1;
		b[i]=i+1;
	}
	a[1]=-1;
	b[n]=-1;
}

void build(){

}

void sol(){
	while(m--){
		ll x,y;
		cin>>x>>y;
		if(x==0){
			if(a[y]!=-1) b[a[y]]=b[y];
			if(b[y]!=-1) a[b[y]]=a[y];
			a[y]=b[y]=-1;
			ok[y]=true;
		}
		else{
			ll tmp1=a[y],tmp2=b[y];
			if(tmp1!=-1) b[y]=tmp1;
			if(tmp1!=-1){
				a[y]=a[tmp1];
				if(a[tmp1]!=-1) b[a[tmp1]]=y;
			}
			if(tmp1!=-1) a[tmp1]=y;
			if(tmp1!=-1) b[tmp1]=tmp2;
			if(tmp1!=-1 && tmp2!=-1) a[tmp2]=tmp1;
		}
	}
	ll tmp=1;
	pary(ok+1,ok+n+1);
	pary(a+1,a+n+1);
	pary(b+1,b+n+1);
	while(ok[tmp]) tmp++;
	for(int i=a[tmp];i!=-1;i=a[i]) tmp=i;
	cout<<tmp<<' ';
	for(int i=b[tmp];i!=-1;i=b[i]) cout<<i<<' ';
	cout<<endl;
}

int main(){
	IOS();
	init();
	build();
	sol();
	return 0;
}

