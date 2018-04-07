#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char a[105],b[105];
int x[105],y[105],z[105];

int main(){
  cin>>a;
  cin>>b;
  int alen=strlen(a);
  int blen=strlen(b);
  int len=max(strlen(a),strlen(b));
  for(int i=0;i<alen;i++) x[i]=a[alen-i-1]-'0';
  for(int i=0;i<blen;i++) y[i]=b[blen-i-1]-'0';
  for(int i=0;i<len;i++) z[i]=x[i]+y[i];
  for(int i=0;i<len;i++){
    if(z[i]>=10) z[i+1]++,z[i]-=10;
  }
  int i;
  for(i=104;z[i]==0;i--);
  for(;i>=0;i--) cout<<z[i];
  cout<<endl;
}
