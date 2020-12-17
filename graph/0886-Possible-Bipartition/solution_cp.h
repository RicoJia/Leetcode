#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <cstring>
using std::memset;

//Method 1:  Not working
//class Solution {
//public:
//    // the non-graph based solution
//    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
//        int group_id[N + 1];
//        memset(group_id, -1, sizeof(group_id));        //default is -1, so if there are no conflicts, these people are okay with either group
//        for (auto const& dislike:dislikes){
//            // if there is no preference, the first dislike item is in group 1
//            if(group_id[dislike[0]] == -1 && group_id[dislike[1]] == -1) {
//                group_id[dislike[0]] = 0;
//                group_id[dislike[1]] = 1;
//            }
//            else{
//                if(group_id[dislike[0]] == -1) group_id[dislike[0]] = 1 - group_id[dislike[1]];
//                if(group_id[dislike[1]] == -1) group_id[dislike[1]] = 1 - group_id[dislike[0]];
//                if(group_id[dislike[1]] == group_id[dislike[0]]) {
//                    cout<<dislike[0]<<" "<<dislike[1]<<endl;
//                    return false;
//                }
//            }
//        }
//        return true;
//    }
//};

/*Method 2*/
//#include <algorithm>
//using std::min;
//using std::max;
//using std::max_element;
//
//class Solution {
//public:
//    // the non-graph based solution
//    bool possibleBipartition(int N, vector <vector<int>> &dislikes) {
//        vector<vector<int>> edge_list(N+1);     //first element is dummy
//        for(auto const& dislike: dislikes){
//            int smaller_element = min(dislike[0], dislike[1]);
//            int larger_element = max(dislike[0], dislike[1]);
//            edge_list.at(smaller_element).emplace_back(larger_element);
//        }
//
//        int group_id[N + 1];
//        memset(group_id, -1, sizeof(group_id));        //default is -1, so if there are no conflicts, these people are okay with either group
//        for (int i = 1; i <= N; ++i ) {
//
//            int max_id = -1;
//            if(group_id[i] == -1){
//                // first, check if the current row in  edge_list is empty, then
//                // we try to find if any element has been colored.
//                for(auto const& disliked_node: edge_list.at(i)){
//                    if (group_id[disliked_node] > -1){
//                        max_id = group_id[disliked_node];
//                        break;
//                    }
//                }
//                group_id[i] = (max_id == -1)? 0: 1-max_id;        //assign it to 0.
//            }
//
//            for(int disliked_node: edge_list.at(i)){
//                if(group_id[disliked_node] == group_id[i]) {
//                    return false;
//                }
//                group_id[disliked_node] = 1 - group_id[i];      // assign the disliked_node to the other group.
//            }
//        }
//        return true;
//    }
//};

/*Method 3 - working but too slow */
//#include <algorithm>
//using std::min;
//using std::max;
//using std::max_element;
//
//class Solution {
//private:
//    bool color_node_and_neighbors(int* group_id, int i, vector<vector<int>> edge_list){
//        // determine the current node's group id
//        if(group_id[i] == -1){
//            int max_id = -1;
//            // first, check if the current row in  edge_list is empty, then
//            // we try to find if any element has been colored.
//            for(auto const& disliked_node: edge_list.at(i)){
//                if (group_id[disliked_node] > -1){
//                    max_id = group_id[disliked_node];
//                    break;
//                }
//            }
//            group_id[i] = (max_id == -1)? 0: 1-max_id;        //assign it to 0.
//        }
//        // color each neighbor's group
//        for(int disliked_node: edge_list.at(i)){
//            if(group_id[disliked_node] == group_id[i]) {
//                return false;
//            }
//            else if(group_id[disliked_node] != -1) continue;
//            else{
//                group_id[disliked_node] = 1 - group_id[i];      // assign the disliked_node to the other group.
//                if(!color_node_and_neighbors(group_id, disliked_node, edge_list)) return false;     //DFS
//            }
//        }
//        return true;
//    }
//
//public:
//    // the non-graph based solution
//    bool possibleBipartition(int N, vector <vector<int>> &dislikes) {
//        vector<vector<int>> edge_list(N+1);     //first element is dummy
//        for(auto const& dislike: dislikes){
//            edge_list.at(dislike[0]).emplace_back(dislike[1]);
//            edge_list.at(dislike[1]).emplace_back(dislike[0]);
//        }
//
//        int group_id[N + 1];
//        memset(group_id, -1, sizeof(group_id));        //default is -1, so if there are no conflicts, these people are okay with either group
//        for (int i = 1; i <= N; ++i ) {
//            if(!color_node_and_neighbors(group_id, i, edge_list)) return false;
//        }
//        return true;
//    }
//};

// Method 4
#include <algorithm>
using std::min;
using std::max;
using std::max_element;

class Solution {
private:
    bool color_node_and_neighbors(int* group_id, int i, int parent_id, vector<vector<int>>& edge_list){
        // determine the current node's group id. since we are doing dfs, we can know what the parent's group_id is.
        if(group_id[i] == -1){
            group_id[i] = 1 - parent_id;        //assign it to 0.
        }
        // color each neighbor's group
        for(int disliked_node: edge_list.at(i)){
            if(group_id[disliked_node] == group_id[i]) {
                return false;
            }
            else if(group_id[disliked_node] != -1) continue;
            else{
                group_id[disliked_node] = 1 - group_id[i];      // assign the disliked_node to the other group.
                if(!color_node_and_neighbors(group_id, disliked_node, group_id[disliked_node], edge_list)) return false;     //DFS
            }
        }
        return true;
    }

public:
    // the non-graph based solution
    bool possibleBipartition(int N, vector <vector<int>> &dislikes) {
        vector<vector<int>> edge_list(N+1);     //first element is dummy
        for(auto const& dislike: dislikes){
            edge_list.at(dislike[0]).emplace_back(dislike[1]);
            edge_list.at(dislike[1]).emplace_back(dislike[0]);
        }

        int group_id[N + 1];
        memset(group_id, -1, sizeof(group_id));        //default is -1, so if there are no conflicts, these people are okay with either group
        for (int i = 1; i <= N; ++i ) {
            if(!color_node_and_neighbors(group_id, i, 0, edge_list)) return false;
        }
        return true;
    }
};