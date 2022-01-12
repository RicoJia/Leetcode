#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <unordered_set>
using std::unordered_set;

#include <functional>
using std::function;

// 2022/01/06 - DFS
class Solution {
public:
    bool has_loop(std::unordered_map<int,vector<int>>graph, int start_key, int start_dep){
        
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // build graph 
        std::unordered_map<int,vector<int>> graph; 
        for (const auto& preq: prerequisites){
            graph[preq[0]].emplace_back(preq[1]);         
        }
        
        // check each item for loops 
        for(const auto& item: graph){
            int start_key = item.first; 
            for (const int& dep: item.second){
                unordered_set <int> deps
                if (has_loop(graph, start_key, dep))
                    return false; 
            }
        }
        return true; 
    }
};

// 2022 01/06 - BFS
// class Solution:
//     # @param {integer} numCourses
//     # @param {integer[][]} prerequisites
//     # @return {boolean}
//     def canFinish(self, numCourses, prerequisites):
//         map = [[] for x in range(numCourses)]
//         ind = [0 for x in range(numCourses)]
//         
//         for p in prerequisites:
//             if p[0] not in map[p[1]]:
//                 ind[p[0]] += 1
//                 map[p[1]].append(p[0])
//         st = []
//         for i in range(numCourses):
//             if ind[i] == 0:
//                 st.append(i)
//         count = 0
//         while st:
//             tmp = st[0]
//             st.pop(0)
//             count += 1
//             for i in map[tmp]:
//                 ind[i] -= 1
//                 if ind[i] == 0:
//                     st.append(i)
//                         
//         if count < numCourses:
//             return False
//         else: 
//             return True

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

