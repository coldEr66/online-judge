#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)


const int MAXn=1e4+2,MAXlg=__lg(MAXn)+2;

inline int getint(){
  ll _x=0,_tmp=1; char _tc=getchar();
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
int d[102];
int dp[MAXn],s[MAXn];
int b[181];
int main(){
  // IOS();
  int n,m;
  n = getint();
  REP(i,n) d[i] = getint();
  m = getint();
  s[0]=1;
  REP(i,n)for(int j=m;j-d[i]>=0;j--){
    if( s[j-d[i]] && dp[j]<dp[j-d[i]]+1 ){
      dp[j] = dp[j-d[i]]+1;
      s[j] = s[j-d[i]];
    }
    else if( s[j-d[i]] && dp[j]==dp[j-d[i]]+1 ) s[j]+=s[j-d[i]];
  }
  if( dp[m]==0 ) cout<<0<<' '<<0<<endl;
  else{
    printf("%d ",dp[m]);
    b[0]=1;
    // assert(dp[m]>=0);
    REP1(i,dp[m]){
      REP(j,180) b[j]*=i;
      REP(j,180)if( b[j]>=10 ) b[j+1]+=b[j]/10,b[j]%=10;
    }
    REP(i,180) b[i]*=s[m];
    REP(i,180)if( b[i]>=10 ) b[i+1]+=b[i]/10,b[i]%=10;
    // assert(s[m]!=0);
    int x;
    for(x=180;b[x]==0;x--);
    for(;x>=0;x--) printf("%d",b[x]);
    printf("\n");
  }
}
