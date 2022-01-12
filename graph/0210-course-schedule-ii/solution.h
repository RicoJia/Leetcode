#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::reverse;

// // 2022-01-09
// // class Solution {
// public:
//     bool has_loop(std::unordered_map<int,vector<int>>graph, int start_key, unordered_set <int> visited){
//         if (visited.find(start_key) != visited.end()) return true;
//         visited.insert(start_key);
//         for (const int& item: graph[start_key]){
//             if (has_loop(graph, item, visited))
//                 return true;
//         }
//         return false;
//     }
//
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         // build graph
//         std::vector<vector<int>> depended(numCourses);
//         vector<int> depends(numCourses, 0);
//         for(const auto& j: prerequisites){
//             depended.at(j[1]).emplace_back(j[0]);
//             ++depends.at(j[0]);
//         }
//
//         int cnt = 0;
//         std::stack<int> s{};
//
//         for (int i = 0; i < depends.size(); ++i){
//             if (depends[i] == 0){
//                 s.push(i);    // tricky
//             }
//         }
//
//         // for(auto i: depended) cout<<i<<endl;
//         // for(auto i: depends) cout<<i<<endl;
//
//
//         while(!s.empty()){
//             int i = s.top();
//             s.pop();
//             cnt++;
//             for(const auto& child: depended.at(i)){
//                 --depends.at(child);
//                 if(depends.at(child) == 0){
//                     s.push(child);
//                 }
//             }
//         }
//
//         if(cnt == numCourses)
//             return true;
//         else return false;
//     }
// };

class Solution {
private:
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //Topological Sort: 1. build a directed edge-list for (A is a preq for b is A->B )dependency. 2. This sort can be implemented only in a unique way: start from the beginning of the list, trace down each node
        // and their dependencies one by one using DFS. 3. Once you touch the end of the node, add the node to a stack (LIFO), then backtrack to the beginning. 4. If there are branches, trace down
//        those branches. 5. Once you're done with a node, you start another one. 6. when you're done with the list, take stuff out of the stack one by one.
//        BENEFIT OF THIS DESIGN: the later nodes in the edge list will always stop at node that needs "joint dependencies ", marked by some previous nodes. This way, we are sure that this
//        sequence from the stack can visit all the dependencies first, then the final node!

        //build an adjacency list, A -> B
        vector<vector<int>> adjacency_list(numCourses);
        for (const auto& preq: prerequisites){
            adjacency_list.at(preq.at(1)).emplace_back(preq.at(0));
        }
        vector<int> status_list(numCourses, 0); //-1 visitied, 0 unvisited, 1 being visited
        vector<int> output; output.reserve(numCourses);
        //DFS to trace down each node in the adjacency list. Push each node onto a "stack"
        for (int i = 0; i < numCourses; ++i){
            // if there's a loop, we return false.
            if (!dfs(i, status_list, adjacency_list, output)) return {};
        }

        reverse(output.begin(), output.end());
        return output;
    }

    bool dfs(int current_i, vector<int>& status_list, const vector<vector<int>>& adjacency_list, vector<int>& output){
        if (status_list.at(current_i) == -1) return true;
        if (status_list.at(current_i) == 1) return false;
        //now the current node has not been explored
        status_list.at(current_i) = 1;
        const auto& edges = adjacency_list.at(current_i);
        for(const int next_i : edges){
            if(!dfs(next_i, status_list, adjacency_list, output)) return false;
        }
        status_list.at(current_i) = -1;
        output.emplace_back(current_i);
        return true;
    }
};
