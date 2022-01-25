class Solution {
public:
    void dp(int next_i, vector<int> vec){
        vec.emplace_back(nums_.at(next_i));
        ret_.emplace_back(vec); 
        for (int j = next_i + 1; j < nums_.size(); ++j){
            dp(j, vec); 
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        ret_.emplace_back(vector<int>());
        nums_ = nums; 
        
        for(int i = 0; i < nums.size(); ++i){
            vector<int> vec; 
            dp(i, vec);         
        }
        
        return ret_; 
    }
