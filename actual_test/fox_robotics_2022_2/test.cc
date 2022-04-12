#include "solution.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include <stdexcept>
#include <iostream>

#include <cmath>
int minimalNumberOfPackages(int items, int availableLargePackages, int availableSmallPackages)
{
    if (availableLargePackages * 5 + availableSmallPackages < items){
        return -1; 
    }
    int min_large = std::min(items/5, availableLargePackages); 
    return items - (min_large * 4); 
}


#ifndef RunTests
int main()
{
    std::cout << minimalNumberOfPackages(16, 2, 100000);
}
#endif
