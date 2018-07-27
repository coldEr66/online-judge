/*input
4
2 6
3 1
7 9
5 4
4
1 4
3 4
1 2
3 3
*/
#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define F first
#define S second
#define REP(i,n) for(int i=0;i<((int)n);i++)
#define pb push_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#ifdef leowang
#define debug(...) do{\
	fprintf(stderr,"%s - %d : (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
	_DO(__VA_ARGS__);\
}while(0)
template<typename I> void _DO(I&&x){cerr<<x<<endl;}
template<typename I,typename...T> void _DO(I&&x,T&&...tail){cerr<<x<<", ";_DO(tail...);}
#else
#define debug(...)
#endif
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
	out<<'('<<P.F<<','<<P.S<<')';
	return out;
}
//}}}
const ll maxn=100005;
const ll maxlg=__lg(maxn)+2;
const ll INF64=8000000000000000000LL;
const int INF=0x3f3f3f3f;
const ll MOD=ll(1e9+7);
const double PI=acos(-1);
//const ll p=880301;
//const ll P=31;

ll mypow(ll a,ll b){
	ll res=1LL;
	while(b){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return res;
}

struct ST{
	int sz;
	ll a[maxn];
	ll M[maxn][maxlg];
	ll m[maxn][maxlg];
	ST(){}
	void build(){
		REP(i,sz) M[i][0]=a[i];
		for(int j=1;j<maxlg;j++) REP(i,sz){
			if(i+(1<<(j-1))<sz){
				M[i][j]=max(M[i][j-1],M[i+(1<<(j-1))][j-1]);
			}
			else M[i][j]=M[i][j-1];
		}
		REP(i,sz) m[i][0]=a[i];
		for(int j=1;j<maxlg;j++) REP(i,sz){
			if(i+(1<<(j-1))<sz){
				m[i][j]=min(m[i][j-1],m[i+(1<<(j-1))][j-1]);
			}
			else m[i][j]=m[i][j-1];
		}
	}
	ll query(int l,int r){
		int tmp=__lg(r-l);
		return max(M[l][tmp],M[r-(1<<tmp)][tmp])-min(m[l][tmp],m[r-(1<<tmp)][tmp]);
	}
}A,B;

int x[maxn],y[maxn];

int main(){
	int n;
	cin>>n;
	A.sz=n;
	B.sz=n;
	REP(i,n) cin>>x[i]>>y[i];
	REP(i,n) A.a[i]=x[i]+y[i];
	REP(i,n) B.a[i]=x[i]-y[i];
	A.build();
	B.build();
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		l--;
		cout<<max(A.query(l,r),B.query(l,r))<<'\n';
	}
}
