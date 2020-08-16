#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::reverse;

class Solution {
private:
    vector<vector<int>> adjacency_list_;         //you can use this as courses are represented in consecutive numbers.
    void buildAdjacencyList(const vector<vector<int>>& prerequisites, int numCourses){
        adjacency_list_ = vector<vector<int>>(numCourses);
        for(auto const& course_pair: prerequisites){
            adjacency_list_.at(course_pair.at(1)).emplace_back(course_pair.at(0));
        }
    }

    int topologicalSort(int node, vector<int>& ret, vector<int>& node_status) {
        //if node has no children, put the node in the bucket, and return normal
        // if node has been visited, just return nortmal
        // if the node is being visited, just return cycle
        // check the next node's neightbors -> if any neighbor returns normal, ret = normal. Else, if there are only cycle(s), ret = cycle. . if ret == normal, put this node in ret. Then, return ret.

        if( node_status.at(node) == 0){
            return 0;
        }
        if(node_status.at(node) == -1){
            return -1;           // return cycle
        }
        if (adjacency_list_.at(node).size() == 0) {         //Ordering of this check is important: you might have a visited tail node, but you don't want to add it there!!
            node_status.at(node) = 0;
            ret.emplace_back(node);
            return 0;       //return normal
        }

        int ret_value = 1;
        node_status.at(node) = -1;      //I tripped here: forgot to color!
        for (int next_node: adjacency_list_.at(node)) {
            ret_value = topologicalSort(next_node, ret,node_status);
            if(ret_value == -1) break;
        }
        node_status.at(node) = 0;   //I tripped here: mark as visited
        if(ret_value == 0) ret.emplace_back(node);
        return ret_value;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        buildAdjacencyList(prerequisites, numCourses);

        vector<int> ret;
        vector<int> node_status(numCourses, 1); //        VISITING = -1, VISITED = 0, UNVISITED = 1;

        for (int node = 0; node < numCourses; ++node) {
            topologicalSort(node, ret, node_status);
        }

        if(ret.size()<numCourses) return{};

        reverse(ret.begin(), ret.end());
        return ret;
    }
};