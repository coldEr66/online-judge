#include <iostream>
#include <algorithm>
using namespace std;

int d[105];
int math[105];
int x[105];

bool cmp(int a,int b){
  if(d[a]!=d[b]) return d[a]>d[b];
  else return math[a]>math[b];
}

int main(){
  int n;
  cin>>n;
  for(int i=1;i<=n;i++) x[i]=i;
  for(int i=0;i<n;i++){
    int id,sum=0;
    cin>>id;
    for(int j=0;j<5;j++){
      int tmp;
      cin>>tmp;
      if(j==2) math[id]=tmp;
      sum+=tmp;
    }
    d[id]=sum;
  }
  sort(x+1,x+n+1,cmp);
  for(int i=1;i<=n;i++) cout<<x[i]<<endl;
}
