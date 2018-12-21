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
#define X first
#define Y second
#define mkp make_pair
#define pb push_back
#define eb emplace_back
#define pob pop_back
#ifdef cold66
#define IOS()
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif
template<class T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int d[MAXn];
int main(){
  IOS();
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    k--;
    REP(i,n) cin>>d[i];
    sort(d,d+n,greater<int>());
    int tmp = d[k];
    int ans = k+1;
    for(int i=k+1;i<n;i++)if( d[i] == tmp ) ans++;
    cout<<ans<<endl;
  }
}
