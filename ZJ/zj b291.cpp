#include<iostream>                    
#include<iomanip>                    
#include<cstdio>                    
#include<cstring>                    
#include<string>                    
#include<set>                    
#include<map>                    
#include<vector>                    
#include<algorithm>                    
#include<sstream>                   
#include <queue>               
#include<cmath>      
#include <ctype.h>     
#include <numeric>
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
const ll INF=ll(1e15);

ll n;
map<string,ll> m,cnt[MaxN];
vector<string> v,ans;
vector<VI> k;
ll u,l;

void init(){
	cin>>n;
	string s,t;
	ll x;
	while(n--){
		cin>>s>>x>>t;
		if(!m.count(t)){
			m[t]=u++;
			VI tmp;
			tmp.resize(1000);
			fill(ALL(tmp),0);
			k.pb(tmp);
			v.pb(t);
		}
		if(!cnt[m[t]].count(s)){
			cnt[m[t]][s]=l++;
			ans.pb(s);
		}
		k[m[t]][cnt[m[t]][s]]+=x;
	}
}

void build(){
	
}

void sol(){
	REP(i,u){
		cout<<v[i]<<" : ";
		bool ok=false;
		REP(j,l){
			if(k[i][j]){
				debug(i,j,ans,v);
				if(ok) cout<<", ";
				cout<<ans[j]<<' '<<k[i][j];
				ok=true;
			}
		}
		cout<<endl;
	}
	debug(ans);
}

int main(){
	IOS();
	init();
	build();
	sol();
	return 0;
}

