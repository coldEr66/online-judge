#include <iostream>
#include <cstring>
using namespace std;

char a[105],b[105];
int x[105],y[105],z[105];

int main(){
  cin>>a>>b;
  int alen=strlen(a);
  int blen=strlen(b);
  for(int i=0;i<alen;i++) x[i]=a[alen-i-1]-'0';
  for(int i=0;i<blen;i++) y[i]=b[blen-i-1]-'0';
  for(int i=0;i<alen;i++){
    for(int j=0;j<blen;j++){
      z[i+j]+=x[i]*y[j];
    }
  }
  for(int i=0;i<105;i++){
    if(z[i]>=10){
      z[i+1]+=z[i]/10;
      z[i]%=10;
    }
  }
  int i=104;
  for(;z[i]==0;i--);
  for(;i>=0;i--) cout<<z[i];
  cout<<endl;
}
