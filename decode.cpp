#include<string>
#include<cctype>
#include <iostream>
#include <algorithm>
// #include"decode.h"
using namespace std;
string decode(const string &data){
    string res; //the string that the function will return
    int cnt=0; //count the times that one character continuous appear
    for(size_t i = 0; i < data.size(); ++i){
        if(!isalpha(data[i])){
            cnt = cnt * 32 + data[i] - 32;
        }else{
            if( cnt == 0 ){
                // if cnt == 0 that means this character only appear once, so append it to the string
                res += data[i];
            }else{
                // else append the character "cnt" times to the string
                for (int j=0;j<cnt;j++) {
                    res += data[i];
                }
            }
            cnt = 0;
        }
    }
    return res;
}

// int main(){
//     string s;
//     cin >> s;
//     cout << decode(s) << endl;
// }
