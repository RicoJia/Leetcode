#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::min;


// BEST METHOD
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row_num = triangle.size();
        for (int r = row_num - 2; r >= 0; --r){
            for (int n_i = 0; n_i < triangle.at(r).size(); ++n_i){
                triangle.at(r).at(n_i) += min(triangle.at(r + 1).at(n_i), triangle.at(r+1).at(n_i+1));
            }
        }
        return triangle.at(0).at(0);
    }
};

// // 2022-01-10
// Lessons learned: 
//  1. if indexing going one direction is too difficult, can we go the other way? 
//  2. referencing ```auto itr = sum.back().end();``` gives seg fault, or heap buffer flow
// // class Solution {
// public:
//     vector<vector<int>> t_;
//     void last_row_neighbors(int& il, int&ir, int row_num, int i){
//         int sz = t_.at(row_num).size();
//         if(i == 0){
//             il = 0;
//             ir = 0;
//         }
//         else if (i == sz-1){
//             il = sz - 2;
//             ir = sz - 2;
//         }
//         else{
//             il = i - 1;
//             ir = i;
//         }
//     }
//
//     int minimumTotal(vector<vector<int>>& triangle) {
//         t_ = triangle;
//         vector<vector<int>> sum;
//         sum.emplace_back(t_.at(0));
//         for (int row_num = 1; row_num < t_.size(); row_num++){
//             int il, ir;
//             vector<int> sum_r (t_[row_num].size(), 0);
//             for(int i = 0; i < t_[row_num].size(); ++i){
//                 last_row_neighbors(il, ir, row_num, i);
//                 sum_r[i] = std::min(sum[row_num-1].at(il), sum[row_num-1].at(ir)) + t_[row_num].at(i);
//             }
//             sum.emplace_back(sum_r);
//         }
//         for(auto r: sum)
//         {for(auto i:r)
//                 cout<<i<<" ";
//         cout<<endl;
//         }
//         auto itr = (std::min_element(sum.back().begin(), sum.back().end()));
//         // cout<<(itr == sum.back().end())<<endl;
//         // *itr;
//         return *itr;
//         // return (*std::min_element(sum.back().begin(), sum.back().end()));
//     }
// };
