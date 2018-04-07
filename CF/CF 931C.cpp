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

template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

const ll MAXn=1e5+5;
const ll MOD=1000000007;
const ll INF=(ll)1e18;

ll d[MAXn];
ll ans[MAXn];
ii cnt[4];
int main(){
	IOS();
	ll n,mn=INF,mx=-INF;
	cin>>n;
	REP(i,n){
		cin>>d[i];
		ans[i]=d[i];
		mn=min(mn,d[i]);
		mx=max(mx,d[i]);
	}
	debug(mn,mx);
	cnt[0]=MP(0,mn);
	cnt[1]=MP(0,mn+1);
	cnt[2]=MP(0,mx);
	REP(i,n){
		if(d[i]==cnt[0].S) cnt[0].F++;
		else if(d[i]==cnt[1].S) cnt[1].F++;
		else cnt[2].F++; 
	}
	ll c[3];
	c[0]=cnt[0].F;
	c[1]=cnt[1].F;
	c[2]=cnt[2].F;
	ll numx,numn;
	numx=numn=min(cnt[0].F,cnt[2].F);
	debug(numx,numn);
	debug(numx,cnt[1].F);
	ll num;
	if(cnt[1].F&1) num=cnt[1].F-1;
	if(numx*2>cnt[1].F && cnt[0].F>0 && cnt[2].F>0){
		REP(i,n){
			if(ans[i]==cnt[0].S && numn){
				ans[i]=cnt[1].S;
				numn--;
				cnt[0].F--,cnt[1].F++;
			}
			else if(ans[i]==cnt[2].S && numx){
				ans[i]=cnt[1].S;
				numx--;
				cnt[2].F--;
				cnt[1].F++;
			}
		}
	}
	else if(numx*2<=cnt[1].F && cnt[0].F>0 && cnt[2].F>0){
		bool c=true;
		REP(i,n){
			if(ans[i]==cnt[1].S && num){
				num--;
				if(c) ans[i]=cnt[0].S,cnt[0].F++;
				else ans[i]=cnt[2].S,cnt[2].F++;
				cnt[1].F--;
				c=!c;
			}
		}
	}
	ll a=min(c[0],cnt[0].F);
	ll b=min(c[1],cnt[1].F);
	ll s=min(c[2],cnt[2].F);
	pary(c,c+3);
	debug(cnt[0].F,cnt[1].F,cnt[2].F);
	debug(a,b,s);
	cout<<a+b+s<<endl;
	sort(ans,ans+n);
	REP(i,n) cout<<ans[i]<<' ';
}

