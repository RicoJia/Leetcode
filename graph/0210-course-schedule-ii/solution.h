#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::reverse;

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