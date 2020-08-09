#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::max;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int fb = -1*1e5, fs = 0, sb = -1*1e5, ss = 0;   //they are profit after first buy, first sell, second buy, second sell.
//        int index = 0, fs_index = 0, sb_index = 0, ss_index = 0;
        for (auto n: prices){
            fb = max(fb, -1 * n);       // get the best price - the min of all the prices so far

//            if (fb + n > fs) fs_index = index;
            fs = max(fs, fb + n);       // the best one-time transaction (may be different from the first transaction of the best two!)
//            if(fs -n > sb) sb_index = index;
            sb = max(sb, fs - n);       // the best second buy price is either the previous one, or the one buying after making the first first transaction.

//            if(sb + n > ss) ss_index = index;
            ss = max(ss, sb + n);       // the profit of the best two transactions

//            ++index;
        }

//        cout<<"best first sell: "<<fs_index+1<<" | "<<prices.at(fs_index)<<" best second buy: "<<sb_index+1<<" | "<<prices.at(sb_index)
//        <<" best second sell: "<<ss_index+1<<" | "<<prices.at(ss_index)<<endl;
        return ss;
    }
};


