#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
#include <string>
using std::string;

#include <cstring>
using std::memset;

// 0 2 0 2 0 3 0 3
class Solution{
public:
// Complete the isValid function below.
    string isValid(string s) {
        int look_up[26];
        memset(look_up, 0, 26 * sizeof(int));
        for (auto &c: s) {
            ++look_up[c - 'a'];
        }

        int a1 = 0, a2 = 0;
        int num1= 0, num2 = 0;
        bool removed = false;
        for(int i: look_up){
            if(i == 0) continue;
            if(a1 == 0){
                a1 = i;
                ++num1;
                continue;}
            if(a2 == 0 && i!= a1){
                a2 = i;
                ++num2;
                continue;
            }
            if(i!=a1 && i!= a2) return "NO";
            else{
                if(i == a1) ++num1;
                if(i == a2) ++num2;
            }
        }
        if (std::abs(a1 - a2) == 1 && (num1 == 1 || num2 == 1)) return "YES";   //a1, a2, random, num can be random. you only let:
        if((a1 == 1 && num1 == 1)|| (a2 == 1 && num2 == 1)) return "YES";
        return "NO";
    }
};