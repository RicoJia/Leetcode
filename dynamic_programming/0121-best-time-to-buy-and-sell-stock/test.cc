#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

int main(){
    Solution s;
    vector<int> prices;
    int ret;

    prices={7,6,4,3,1};
    ret = s.maxProfit(prices);
    cout<<"solution is 0, and answer is "<<ret<<endl;


    prices={7,1,5,3,6,4};
    ret = s.maxProfit(prices);
    cout<<"solution is 5, and answer is "
    <<ret<<endl;
}