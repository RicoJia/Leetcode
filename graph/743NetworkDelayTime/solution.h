#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::min;

#include <cstring>

// DO not have const!! it might cause trouble, as in passing a const type to a non-const function
class Solution{
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        //Ford - something?
        int MAX_TIME = 1e9;
        int shortest_time[N];             //tripped big time here.
        for(int i = 0; i < N; ++i) shortest_time[i] = MAX_TIME;
//        std::vector<int> shortest_time(N, MAX_TIME);
        shortest_time[K - 1] = 0;
        for(int i = 0; i < N; ++i){
            for (auto& time: times){
                int last = time[0], node = time[1], t = time[2];
                shortest_time[node - 1] = min(shortest_time[node - 1], shortest_time[last - 1] + t);
            }
        }
//
//        if(std::any_of(shortest_time.begin(), shortest_time.end(), [&](int i){return i == MAX_TIME; })) return -1;     //not sure if?
//        return *(std::max_element(shortest_time.begin(), shortest_time.end()));

        if(std::any_of(shortest_time, shortest_time + N, [&](int i){return i == MAX_TIME; })) return -1;     //not sure if? Yes it does work.
        return *(std::max_element(shortest_time, shortest_time + N));
//            return shortest_time[1];
    }
};