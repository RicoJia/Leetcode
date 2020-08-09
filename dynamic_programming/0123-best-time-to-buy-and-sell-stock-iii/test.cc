#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;

using std::vector;

int main(){
    Solution s;
    vector<int> prices;
    int ret;

    prices = {3,3,5,0,0,3,1,4};
    ret = s.maxProfit(prices);
    cout<<"Solution is: 6, and I got "<<ret<<endl;
}