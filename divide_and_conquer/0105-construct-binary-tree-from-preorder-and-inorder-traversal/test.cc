#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;

using std::vector;

int main(){
    Solution s;
    vector<int> preorder = {3,9,100, 1000, 20,15,7};
    vector<int> inorder = {100, 9, 1000, 3,15,20,7};
    s.buildTree(preorder, inorder);
}