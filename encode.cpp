#include <string>
#include <algorithm>
#include <iostream>
// #include"encode.h"
using namespace std;
string gt(int x){ // this function will transform an integer into a string
    string res = "";
    while (x) {
        int cur = x%32;
        res += char(cur + 32);
        x /= 32;
    }
    reverse(res.begin(),res.end()); // because you start from the digits in ones, so you must to reverse the string
    return res;
}
string encode(const string &data){
    string res; // the string that the function will return
    int sameCnt = 0; // count the times that one character continuous appear
    int cur = -1; // record the charcater that appear now
    for(size_t i = 0; i < data.size(); ++i){
        if( i && data[i] == data[i-1] ){
            ++sameCnt;
        }else{
            // if the character different from the former, you must to put it into the returned string(res)
            if (cur != -1) {
                if (sameCnt != 1) res += gt(sameCnt);
                res += char(cur);
            }
            cur = (int)data[i];
            sameCnt = 1;
        }
    }
    if( sameCnt > 0 ){
        if (sameCnt != 1) res += gt(sameCnt);
        res += char(cur);
    }
    return res;
}

// int main(){
//     string s;
//     cin >> s;
//     cout << encode(s) << endl;
// }
