#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;
using std::vector; 

int main(){
    Solution s;

    s.maxOfMinAltitudes({{1, 2, 3},
                         {4, 5, 1}}
    );

    s.maxOfMinAltitudes(
    {{5, 1},
    {4, 5}});

}
