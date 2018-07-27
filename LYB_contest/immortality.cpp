/*input
10
1 0 1
1 1 2
2 1 2
1 0 3
1 0 4
1 0 5
1 1 6
2 2 6
2 0 5
2 2 5

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
const ll maxn=300005;
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

int anc[maxn][maxlg];
int h[maxn];

int Gee(int op,int a,int b){
	if(op==1){
		anc[b][0]=a;
		h[b]=h[a]+1;
		for(int i=1;i<maxlg;i++)
			anc[b][i]=anc[anc[b][i-1]][i-1];
	}
	else{
		if(h[a]<h[b]) swap(a,b);
		{
			int tmp=h[a]-h[b];
			for(int i=0;i<maxlg;i++) if(tmp&(1<<i)){
				a=anc[a][i];
			}
		}
		if(a==b){
			if(b==0) cout<<"-1\n";
			else cout<<anc[b][0]<<'\n';
		}
		else{
			for(int i=maxlg-1;i>=0;i--){
				if(anc[a][i]!=anc[b][i]){
					a=anc[a][i];
					b=anc[b][i];
				}
			}
			cout<<anc[a][0]<<'\n';

		}
	}
}
/*
int main()
{
	//IOS;
	int n;
	cin>>n;
	REP(i,n){
		int op,a,b;
		cin>>op>>a>>b;
		Gee(op,a,b);
	}

	return 0;
}
*/