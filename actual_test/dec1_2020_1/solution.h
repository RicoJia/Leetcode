#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
#include<climits>

#include <unordered_map>
using std::unordered_map;

#include <deque>
using std::deque;

#include <stack>
using std::stack;

class Solution {
public:
    int calculate(string s) {
        //Thoughts:
        //  1. parse the string. (truncate space)
        //  search for * and /, push their positions
        //  return int.
        s.erase(std::remove(s.begin(), s.end(), ' '), s.begin());
        stack<int> sta;
        int curr = 0;

        for (const auto& c: s){
            if (c == '-'){
                int num = -1 * sta.pop_back();
                sta.push_back(num);
            }
            else if (c == "*" || c == "/"){

            }

        }
        return ret;
    }
};