#include <iostream>
#include <sstream>
using std::cout;
using std::endl;
using std::stringstream;

#include <string>
using std::string;

#include <cmath>
#include <algorithm>
using std::max;
//Method 1 - not suitable for long strings
//class Solution {
//public:
//    string addBinary(string a, string b) {
//        auto str_2_int = [&](string& str){
//            int ret = 0;
//            for (char c: str)
//                ret = (ret<<1) | (c-'0');
//            return ret;
//        };
//
//        auto int_2_binary_str = [&](int i){
//            stringstream ss;
//            int  k = (int)log2(i);
//            while(k>=0){
//                ss<<((i>>(k)) & 1);
//                --k;
//            }
//            return ss.str();
//        };
//        int a_int = str_2_int(a);
//        int b_int = str_2_int(b);
//
//        return (a_int + b_int == 0)?"0":int_2_binary_str(a_int + b_int);
//    }
//};

class Solution {
public:
    string addBinary(string a, string b) {
        // lambda function for getting next char from string.
        auto get_next_digit = [&](string s, int i) {
            if (i < 0) return 0;
            else return s.at(i) - '0';
        };
        stringstream ss;
        int carry = 0;
        int max_size = (int) max(a.length(), b.length());
        for (int i = 0; i < max_size; ++i){
            int ca = get_next_digit(a, a.length()- i -1);
            int cb = get_next_digit(b,b.length() - i -1);
            ss<<((carry + ca + cb)&1);
            carry = ((carry + ca + cb)>>1)&1;
        }
        if (carry == 1) ss<<carry;
        string ret_s = ss.str();
        return string(ret_s.rbegin(), ret_s.rend());    // return MSB -> LSB.
    }
};