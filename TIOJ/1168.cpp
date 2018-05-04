#include <bits/stdc++.h>
#include "lib1168.h"
using namespace std;

map<int,int> cnt;
priority_queue<int> mxpq;
priority_queue<int,vector<int>,greater<int>> mnpq;
void pop_big(){
  while(!cnt[mxpq.top()]) mxpq.pop();
  cnt[mxpq.top()]--;
  mxpq.pop();
}
void pop_small(){
  while(!cnt[mnpq.top()]) mnpq.pop();
  cnt[mnpq.top()]--;
  mnpq.pop();
}
void push(int s){
  cnt[s]++;
  mxpq.push(s);
  mnpq.push(s);
}
int big(){
  while(!cnt[mxpq.top()]) mxpq.pop();
  return mxpq.top();
}
int small(){
  while(!cnt[mnpq.top()]) mnpq.pop();
  return mnpq.top();
}
/*
int main(){
  int x,y;
  while(cin>>x>>y){
    if(x==0) pop_big();
    else if(x==1) pop_small();
    else if(x==2) push(y);
    else if(x==3) cout<<big()<<endl;
    else cout<<small()<<endl;
  }
}
*/
