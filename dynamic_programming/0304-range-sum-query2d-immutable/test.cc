#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;

using std::vector;

int main(){
    vector<vector<int>> nums;
    NumMatrix numMatrix_obj;
    int ret;

    /*
     * 3 0 1 4 2
     * 5 6 3 2 1
     * 1 2 0 1 5
     */
    nums = {{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}};
    numMatrix_obj = NumMatrix(nums);
    ret = numMatrix_obj.sumRegion(1,1,2,2);
    numMatrix_obj.print_map();
    cout<<"Solution is 11, and I got: "<<ret<<endl;

}