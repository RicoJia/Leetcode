#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;
using std::vector; 

int main(){
    Solution s;
    vector<int> prices;
    int ret, fee;

    prices = {1, 3, 2, 8, 4, 9};
    fee = 2;
    ret = s.maxProfit(prices, fee);
    cout<<"solution is 8, and I got "<<ret<<endl;
}
