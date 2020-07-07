#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0) return 0;        // this is for x < 1 and large n
        if(x == 1) return 1;        // this is for x = 1/-1 and large n.
        if(n == 1) return x;

        if (n == 0) return 1;
        else if (n > 0) return ((n%2 == 1)?x:1) * myPow(x * x, n / 2);  // we are not using myPow(x, n/2), because if n is large but |x| <1, we can quickly get 0. Else, wait forever!
        else return 1.0/x * myPow(1.0/x, -1*(n+1));     // This is for (2, -2147483648) where you have to shift n to +1.
    }
};

