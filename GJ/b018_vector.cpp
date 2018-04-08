#include <iostream>
#include <vector>
using namespace std;

vector<int> x;

int main(){
  int n;
  cin>>n;
  x.push_back(1);
  for(int i=2;i<=n;i++){
    for(int j=0;j<x.size();j++) x[j]*=i;
    for(int j=0;j<x.size();j++){
      if(x[j]>=10){
        if(j!=x.size()-1) x[j+1]+=x[j]/10;
        else x.push_back(x[j]/10);
        x[j]%=10;
      }
    }
  }
  for(int i=x.size()-1;i>=0;i--) cout<<x[i];
  cout<<endl;
}
