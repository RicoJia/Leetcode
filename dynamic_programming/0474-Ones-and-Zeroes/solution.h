#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <numeric>

#include <algorithm>
using std::max;

#include <cstring>
using std::memset; 

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // in this program we define a 2D lookup table (m+1)*(n+1)
        int lookup_table[m+1][n+1];
        memset(lookup_table, 0, sizeof(lookup_table));
        for (auto& str: strs){
            int num_1 = std::accumulate(str.begin(), str.end(),0,[](int num_1, char c){return num_1 + c - '0';});
            int num_0 = (int)str.size()-num_1;
            for(int i_0 = m; i_0 >= num_0; --i_0){
                for(int i_1 = n; i_1 >= num_1; --i_1){
                    lookup_table[i_0][i_1] = max(lookup_table[i_0][i_1], 1 + lookup_table[i_0 - num_0][i_1 - num_1]);
                }
            }
        }
        return lookup_table[m][n];
    }
};