class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::multimap <double, vector<int>> mmp; 
        for (const auto& p: points){
            double dist = sqrt(p[0]*p[0] + p[1]*p[1]); 
            // use insert, and use std::pair
            mmp.insert(std::pair<double, vector<int>>(dist, p));
        }
        vector<vector<int>> ret; 
        // this is because there's no itertor+2 for multimap. So need iter++
        auto beg = mmp.begin(); 
        for (int i = 0; i < k; ++i){
            // -> can be used here
            auto p = (beg++)->second;
            ret.emplace_back(p);    
        }
        return ret;
    }
};
