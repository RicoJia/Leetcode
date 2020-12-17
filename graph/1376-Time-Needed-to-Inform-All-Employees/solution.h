#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
#include<climits>

class Solution{
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        //naive thought: 1. build a 2d lookup table: each row represents the subordinates.  Then, for each row, traverse thru all employees, flip their signs and Track down their suborniates.
        // Better solution: We do use DFS, but DFS can return the time to reach the bottom.
        int emp_num = n;
        lookup_ = vector<vector<int> >(emp_num, vector<int>(0));
        for (int i = 0; i < emp_num; ++i){
            int man_id = manager.at(i); 
            if (man_id == -1) continue;   //include head himself
            lookup_.at(man_id).reserve(emp_num);
            lookup_.at(man_id).push_back(i);
        }

        return dfs(headID, informTime);
    }

private:
    //return the time it takes to inform the last subordinate
    int dfs(int id, vector<int>& informTime_){
        int max_time = 0;
        auto& subs = lookup_.at(id);
        for (const auto& sub_id: subs){
            // we are traversing thru the tree to calculate the travelling time to each node. This of course
            //requires that we have no trees.
            //weird thing is step will return segfault even if an infinite loop is not here but behind it...
            max_time = std::max(dfs(sub_id, informTime_), max_time);
        }
        return max_time + informTime_.at(id);
    }

    int max_time_;
    vector<vector<int> > lookup_;
};