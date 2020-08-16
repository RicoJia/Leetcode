#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

int main(){
    Solution s;
    vector<int> coins;
    int ret, amount;

    coins = {1,2};
    amount = 3;
    ret = s.change(amount, coins);
    cout<<"Solution is 2, and I got: "<<ret<<endl;

    coins = {1,2,5};
    amount = 6;
    ret = s.change(amount, coins);
    cout<<"Solution is 4, and I got: "<<ret<<endl;

    coins = {2};
    amount = 3;
    ret = s.change(amount, coins);
    cout<<"Solution is 0, and I got: "<<ret<<endl;
//    coins = {3,5,7,8,9,10,11};
//    amount = 500;
//    ret = s.change(amount, coins);
//    cout<<"Solution is 35502874, and I got: "<<ret<<endl;

}