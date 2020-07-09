#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;

using std::vector;


int main(){
    Solution s;
    vector<int> piles;
    int H; int ret;

    piles ={3,6,7,11};
    H = 8;
    ret = s.minEatingSpeed(piles, H);
    cout<<"ret: "<< ret << " solution: "<< 4<<endl;
    cout<<"*******************************"<<endl;

    piles ={30,11,23,4,20};
    H = 5;
    ret = s.minEatingSpeed(piles, H);
    cout<<"ret: "<< ret << " solution: "<< 30<<endl;
    cout<<"*******************************"<<endl;

    piles ={30,11,23,4,20};
    H = 6;
    ret = s.minEatingSpeed(piles, H);
    cout<<"ret: "<< ret << " solution: "<< 23<<endl;
    cout<<"*******************************"<<endl;

    piles = {2};
    H = 4;
    ret = s.minEatingSpeed(piles, H);
    cout<<"ret: "<< ret << " solution: "<< 1<<endl;
    cout<<"*******************************"<<endl;

    piles = {332484035,524908576,855865114,632922376,222257295,690155293,112677673,679580077,337406589,290818316,877337160,901728858,679284947,688210097,692137887,718203285,629455728,941802184};
    H = 823855818;
    ret = s.minEatingSpeed(piles, H);
    cout<<"ret: "<< ret << " solution: "<< 1<<endl;
    cout<<"*******************************"<<endl;

}