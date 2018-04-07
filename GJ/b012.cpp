#include <iostream>
using namespace std;

int v[1005];

int main(){
  string s;
  cin>>s;
  for(int i=0;i<s.size();i++){
    if(s[i]=='I') v[i]=1;
    else if(s[i]=='V') v[i]=5;
    else if(s[i]=='X') v[i]=10;
    else if(s[i]=='L') v[i]=50;
    else if(s[i]=='C') v[i]=100;
    else if(s[i]=='D') v[i]=500;
    else v[i]=1000;
  }
  int ans=0;
  for(int i=0;i<s.size();i++){
    if(v[i]<v[i+1]) ans-=v[i];
    else ans+=v[i];
  }
  cout<<ans<<endl;
}
