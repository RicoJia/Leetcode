#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

class Solution{
public:
    int maxXor(int lo, int hi, int k) {
        int max = 0;
        for (int a = lo; a < hi; ++a) {
            for (int b = a + 1; b <= hi; ++b) {
                int res = a ^ b;
                max = (res <= k && res > max)? res : max;
//                cout<<"a: "<<a<<" b: "<<b<<" res: "<<res<<endl;
            }
        }
        return max;
    }
};
