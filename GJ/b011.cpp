#include <iostream>
using namespace std;

int main(){
  string a;
  int ans=0;
  for(int i=0;i<3;i++){
    int tmp=0;
    cin>>a;
    for(int j=0;j<a.size();j++){
      if(isdigit(a[j])){    //if(a[j]>='0' && a[j]<='9')
        tmp+=a[j]-'0';
        tmp*=10;
      }
    }
    tmp/=10;
    ans+=tmp;
  }
  cout<<ans<<endl;
}
