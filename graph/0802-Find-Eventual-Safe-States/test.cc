#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;
using std::vector; 

int main(){
    Solution s;
    vector<vector<int>> graph; 
    vector<int> ret; 
    
    graph = {{1,2},{2,3},{5},{0},{5},{},{}}; 
    ret = s.eventualSafeNodes(graph); 
    for(auto const& num: ret){
        cout<<num<<" ";
    }
    cout<<endl; 

}
