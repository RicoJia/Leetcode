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

class Solution {
public:
    string addBinary(string a, string b) {
        // Naive solution: 0. prepend. 1. read 2 chars from each array. 2. have a carry. digit = a xor b. carry = a and b.
        // char to int: - '0';
        // push char to string: y+= d;
        //xor: ^
        //prepend
        int ret_len = std::max(a.size(), b.size()) + 1;
        string ret(ret_len, '0');
        a = string(ret_len - a.size(), '0') + a;
        b = string(ret_len - b.size(), '0') + b;

        int carry = 0;
        // parse thru each char
        for (int i = ret_len -1; i >= 0; --i){
            int a_bit = a.at(i) - '0';
            int b_bit = b.at(i) - '0';
            int sum = a_bit + b_bit + carry;
            int ret_bit = sum % 2;
            ret.at(i) = ret_bit + '0';
            carry = sum >> 1;
        }
        cout<<"c: "<<carry<<endl;
        if (ret.at(0) == '0') ret = {ret.begin()+1, ret.end()};
        return ret;
    }
};