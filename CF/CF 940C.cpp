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

ll n;
ll d[MaxN];
string s;
void init(){
	cin>>n;
	REP(i,n) cin>>d[i];
	cin>>s;
}

void build(){
	
}
ii chk(ll i){
	ii ret;
	if(s[i-1]=='1' && s[i-2]=='1' && s[i-3]=='1' && s[i-4]=='1'){
		ret.F=1;
		ll mn=INF;
		for(int j=i;j>=i-4;j--) mn=min(mn,d[j]);
		ret.S=mn;
	}
	else if(s[i-1]=='0' && s[i-2]=='0' && s[i-3]=='0' && s[i-4]=='0'){
		ret.F=0;
		ll mx=-INF;
		for(int j=i;j>=i-4;j--) mx=max(mx,d[j]);
		ret.S=mx;
	}
	else ret.F=2;
	return ret;
}
ll l,r;
void sol(){
	for(int i=4;i<n;i++){
		ii cur=chk(i);
		if(cur.F==2) continue;
		else if(cur.F==1) r=min(r,cur.S-1);
		else l=max(l,cur.S-1);
	}
	cout<<l<<' '<<r<<endl;
}

int main(){
	IOS();
	init();
	build();
	sol();
	return 0;
}

