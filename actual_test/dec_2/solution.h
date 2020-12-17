#include <iostream>

#include <vector>

#include <algorithm>
#include<climits>

#include <unordered_map>
#include <string>

using namespace std;

class Solution{
public:
    //Thoughts:
    // 1. Have two vector of vectors: roaring and roared
    // 2. for each char in the string:
    // 3.   find the first horse in roaring that says the char.
    // 4.       if we find one, we increment the pointer to its next char. If ptr points to
    //          the end of "neigh", push the horse to roared.
    // 5.       if we cannot find one, we push a horse to roaring, take out a horse in roared. set the pointer to its beginning
    // 6.　return the size of roared and roaring.

    int countHorses(string s){
        vector<size_t> roaring;
        int roared = 0;
        const string neigh = "neigh";
        for(const char& c: s){
            auto c_pos = neigh.find(c);
            if (c_pos == string::npos){
                cout<<"Invalid"<<endl;
                return -1;
            }
            auto vec_itr = std::find(roaring.begin(), roaring.end(), c_pos);
            if(vec_itr!= roaring.end()){
                ++(*vec_itr);
                if ((*vec_itr) == neigh.size()){
                    roaring.erase(vec_itr);
                    ++roared;
                }
            } else{
                roaring.push_back(1);
                if (roared > 0) --roared;
            }
        }
        return roared + roaring.size();
    }
};