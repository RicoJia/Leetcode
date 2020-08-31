#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

class Solution{
public:
    int largestArea(vector<vector<int>> samples) {
        // build the lookup table
        vector<vector<int>> table(samples.size(), vector<int>(samples[0].size(), 0));
        for(int row_i = 0 ; row_i < samples.size(); row_i++){
            int dist_to_0 = 1;
            for(int cln_i = samples.size() -1; cln_i >= 0; cln_i--){
                // if hit 0, reset dist to 1. else, increment dist.
                if(samples[row_i][cln_i] == 0) dist_to_0 = 1;
                else{
                    table[row_i][cln_i] = dist_to_0;
                    ++dist_to_0;
                }
            }
        }

        int largest_size = 0;

        // start from the current node, downwards. the largest square at that node will have size = depth = dist_to_0
        for(int row_i = 0 ; row_i < samples.size(); row_i++) {
            for (int cln_i = 0; cln_i < samples[0].size(); cln_i++) {
                int depth = 1, max_size = table[row_i][cln_i];
                while(row_i + depth < samples.size() && depth <= max_size){
                    max_size = (table[row_i + depth][cln_i] < max_size)?table[row_i + depth][cln_i]:max_size;
                    ++depth;
                }
                //depth - 1 is the size here
                largest_size = (depth - 1 > largest_size)? depth - 1: largest_size;
//                cout<<"row: "<<row_i<<" cln: "<<cln_i<<" size: "<<depth-1<<endl;
            }
        }
        return largest_size;
    }
};
