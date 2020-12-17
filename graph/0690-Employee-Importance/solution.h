#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
#include<climits>
#include <unordered_map>
using std::unordered_map;

// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
    Employee(const int id, const int importance, const vector<int>& sub) : id(id), importance(importance), subordinates(sub){}
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        //Naive thought: DFS: build the edge list (half), trace down each employee. Maybe you can do it using std::find as well?
        // note that each input is a pointer ptr,
        // you need an unordered_map since ID can be random.
        for (const auto& employee_ptr : employees ){
            edge_list_[employee_ptr -> id - 1] = employee_ptr;
        }
        return dfs(id);
    }

private:
    int dfs(int id){
        Employee *employee_ptr = edge_list_[id - 1];
        int total_val = employee_ptr -> importance;
        for (int sub_id : employee_ptr -> subordinates){
            total_val += dfs(sub_id);
        }
        return total_val;
    }
    unordered_map<int, Employee*> edge_list_;
};