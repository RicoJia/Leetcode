#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;
using std::vector; 

int main(){
    Solution s;
    vector<int> friends_from; vector<int> friends_to; vector<int> friends_weight;
    int friends_nodes;
    s.maxShared(4, {1,1,1,1,3,3,3,3,3,3,4,4,4,4,4,4,4},
                   {3,3,3,4,1,1,1,1,1,1,1,1,1,1,1,1,1},
                   {8,34,45,77,3,23,27,42,46,65,2,11,30,41,60,75,94});
}
