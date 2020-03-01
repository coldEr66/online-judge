#include <bits/stdc++.h>
using namespace std;

const int MAXn=1e3+5;
int f[MAXn]; // 定義 f[i] = i個人的對戰籤表有幾種排法
int cal(int x){ //  cal(i) 用來計算 f[i]
    if (x <= 3) return 1; // 一個人或兩個人或三個人都只有一種排法
    if (f[x] != -1) return f[x]; // 已經計算過的不重複計算
    int ret = 0;
    for (int i=x%2;i<x;i+=2) {
        // 枚舉種子人數，若x為奇數，種子人數則有1,3,5,.... 而x為偶數，種子人數則有0,2,4,....
        ret += cal((x-i)/2 + i); // 答案加上(x-i)/2 + i 人時的答案（扣掉種子剩下的人對戰）
    }
    return f[x] = ret;
}
int main(){
    int n; // 輸入人數
    cin >> n;
    for (int i=0;i<MAXn;i++) f[i] = -1;
    cout << cal(n) << endl;
}
