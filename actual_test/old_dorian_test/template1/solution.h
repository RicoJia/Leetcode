#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

class Solution{

public:
    int maxShared(int friends_nodes, vector<int> friends_from, vector<int> friends_to, vector<int> friends_weight) {

        if(friends_from.empty()) return 0;

        //build a 2D table
        vector<vector<int>> table(friends_nodes+1, vector<int>(friends_nodes, 0));
        //3D weight table
        int max_edge_num = 0;
        vector<vector<int>> edge_list;

        for (int i = 0; i < friends_from.size(); ++i){
            ++table.at(friends_from.at(i)-1).at(friends_to.at(i)-1);
            ++table.at(friends_to.at(i)-1).at(friends_from.at(i)-1);
            if(table.at(friends_from.at(i)-1).at(friends_to.at(i)-1) == max_edge_num){
                edge_list.push_back({friends_from.at(i), friends_to.at(i)});
            }
            else if(table.at(friends_from.at(i)-1).at(friends_to.at(i)-1) > max_edge_num){
                edge_list = {{friends_from.at(i), friends_to.at(i)}};
                edge_list.reserve(friends_nodes * (friends_nodes - 1)/2);
                max_edge_num = table.at(friends_from.at(i)-1).at(friends_to.at(i)-1);
            }
        }

//        calculate the max product
        int max_prod = 0;
        for(auto const& pair:edge_list){
            int prod = pair.at(0) * pair.at(1);
            max_prod = (prod > max_prod)?prod:max_prod;
        }

        return max_prod;
    }
};
