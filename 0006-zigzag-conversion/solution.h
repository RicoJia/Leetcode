#include <string>
using std::string;

#include<vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        // lambda function for determining indices of a row.
        int max_gap = (numRows - 1) * 2;

        auto get_indices = [&](int row_i){
            int i = 0; int next_index = row_i;
            vector<int> ret_vec;
            ret_vec.reserve(s.length());
            while(next_index < s.length()){
                ret_vec.push_back(next_index);
                ++i;
                int last_index = next_index;
                next_index += (i%2 == 0)? row_i*2: max_gap-row_i*2;      //if the next element has odd in the vector (excluding the first one), it should add 2 * row_i to the previous one. Else, add max_gap - 2 * row_i.
                if(last_index == next_index) ret_vec.pop_back();           //for the first row and bottom row, you need to weed out the same elements
            }
            return ret_vec;
        };

        string ret_str;
        ret_str.reserve(s.length());

        for(int i = 0; i < numRows; ++i){
            auto row_indices = get_indices(i);
            for(int i: row_indices) ret_str.push_back(s.at(i));
        }
        return ret_str;
    }
};

////Method 2
//class Solution {
//public:
//    string convert(string s, int nRows) {
//        if (s.empty() || nRows < 2) return s;
//        std::vector<string> ret(nRows);
//        for (size_t i=0; i<s.size(); ++i) {
//            int m = i % (nRows-1), n = i / (nRows-1);
//            (n & 0x1 ? ret[nRows-m-1] : ret[m]) += s[i];
//
//            cout<<"-------------"<<endl;
//            cout<<"n & 0x1: "<<(n & 0x1)<<" n: "<<n<<" m: "<<m<<" nRows-m-1: "<<nRows-m-1<<endl;
//            for(auto str: ret) cout<<str<<endl;
//        }
//        return std::accumulate(ret.cbegin(), ret.cend(), string());
//    }
//};