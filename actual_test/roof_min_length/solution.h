#include <iostream>

#include <vector>

#include <algorithm>
#include<climits>

#include <unordered_map>

using namespace std;

class Solution{
public:
    int sln(vector<int>cars, int k){
        std::sort(cars.begin(), cars.end()); 
        int min_diff = INT_MAX; 
        for (int i = 0; i < cars.size()-k+1; ++i){
           int sum = cars.at(i+2) -  cars.at(i) + 1; 
            if (sum < min_diff) min_diff = sum;
        }
        return min_diff; 
    }

};
