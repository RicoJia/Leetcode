#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <unordered_set>
using std::unordered_set;

#include <functional>
using std::function;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph_(numCourses); // initialize them?
        for (auto& edge: prerequisites){
            graph_.at(edge.at(0)).push_back(edge.at(1));
        }

/*        unordered_set<int>visited;
        int index = 0;
        for (auto &node_connection: graph_) {
            if(visited.find(index)==visited.end()){         // you can do this in the function.
                unordered_set<int>visiting;                 //Instead of having two sets, you can have a vector, with 2 values. This is a major benefit - as you do not need to use find, insert in the unordered map, which will be o(n)
                function<bool (int)> DFS = [&](int next_node_index){
                    if (visiting.find(next_node_index)!=visiting.end()) return false;
                    visiting.insert(next_node_index);
                    for (int& next_node: graph_.at(next_node_index)){
                        if(!DFS(next_node)) return false;
                    }
                    visiting.erase(next_node_index);
                    visited.insert(next_node_index);
                    return true;
                };
                if(!DFS(index)) return false;
            }
            ++index;
        }*/
        vector<int> visit_list(numCourses, 0);  //0 is unvisited, 1 is visited, 2 is visiting.
        for(int index = 0; index < graph_.size(); ++index){
            function<bool (int)> DFS = [&](int next_node_index){
                if(visit_list.at(next_node_index) == 1) return true;
                if (visit_list.at(next_node_index) == 2) return false;
                visit_list.at(next_node_index) = 2;
                for (int& next_node: graph_.at(next_node_index)){
                    if(!DFS(next_node)) return false;
                }
                visit_list.at(next_node_index) = 1;
                return true;
            };
            if(!DFS(index)) return false;
        }
        return true;
    }
};

