#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

void push_train();
void move_station_1_to_2();
void move_station_2_to_1();
void pop_train();
void no_solution();

stack<int> st1,st2;
int pos[10000005];
void findr(int tmp){
	while(st1.top()!=tmp){
		move_station_1_to_2();
		st2.push(st1.top());
		pos[st1.top()]=2;
		st1.pop();
	}
	st1.pop();
	move_station_1_to_2();
	pop_train();
}
void findl(int tmp){
	while(st2.top()!=tmp){
		move_station_2_to_1();
		st1.push(st2.top());
		pos[st2.top()]=1;
		st2.pop();
	}
	st2.pop();
	pop_train();
}

void solve(int N,int order[]){
	int cur=1;
	for(int i=1;i<=N;i++){
		st1.push(i);
		pos[i]=1;
		push_train();
	}
	REP(i,N){
		if(pos[order[i]]==1) findr(order[i]);
		else if(pos[order[i]]==2) findl(order[i]);
	}
}

