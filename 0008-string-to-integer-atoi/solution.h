#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include <cctype>
#include <cmath>
using std::abs;

#include <climits>

class Solution {
public:
    int myAtoi(string str) {
        int signed_curr = 0; int sign = 0;
        bool sign_determined = false;
        for (char &c: str){
            // determine sign and get the corresponding max
            if(sign_determined == false){
                if (c == ' ') {}
                else{
                    sign = (c == '-')? -1: 1;
                    if (isdigit(c)) signed_curr = c - '0';
                    else if(c!='-' && c!='+') return 0;
                    sign_determined = true;
                }
            }
            else{
                if(!isdigit(c)) break;
                else{
                    int n = c - '0';
                    if(sign < 0){
                        if((INT_MIN - sign * n)/10 > signed_curr) {return INT_MIN;};
                    }
                    else{
                        if((INT_MAX - sign * n)/10 < signed_curr) {return INT_MAX;};
                    }
                    signed_curr = signed_curr * 10 + sign * n;
                }
            }
        }
        return signed_curr;
    }
};