#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <queue>
using std::queue;

#include <algorithm>

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector <vector<int>> reverse_graph(graph.size());
        queue<int> leaf_nodes;
        // building the reverse graph
        int current_node = 0;
        for (auto const &row: graph) {
            if(row.size() == 0)
                leaf_nodes.push(current_node);
            else{
                for (int next_node: row) {
                    reverse_graph.at(next_node).emplace_back(current_node);
                }
            }
            ++current_node;
        }

        //popping edges from graph and add the nodes to the list
        vector<int> ret_list; ret_list.reserve(graph.size());
        current_node = 0;
        while(!leaf_nodes.empty()){
            int current_node = leaf_nodes.front();
            leaf_nodes.pop();
            ret_list.emplace_back(current_node);
            for(int& last_node: reverse_graph.at(current_node)){
                graph.at(last_node).erase(std::remove(graph.at(last_node).begin(), graph.at(last_node).end(), current_node), graph.at(last_node).end());        //remove the edge
                if(graph.at(last_node).size() == 0) leaf_nodes.push(last_node);
            }
        }
        // sort the list
        std::sort(ret_list.begin(), ret_list.end());
        return ret_list;
    }
};