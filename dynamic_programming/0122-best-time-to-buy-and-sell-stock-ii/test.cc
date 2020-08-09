#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

int main(){
    Solution s;
    vector<int> prices;
    int ret;

    prices = {7, 1, 5, 3, 6, 4};
    ret = s.maxProfit(prices);
    cout<<"Solution is 7, and I got: "<<ret<<endl;
}