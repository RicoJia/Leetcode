// 2022-01-07
class Solution {
public:
    vector<vector<int>> sol_; 
    // Tricky part: 1. let the base case do its part; 2. clean up yourself for the next possibility
    void back_track(vector<int>& candidates, int target, int start, vector<int>& current){
        if (candidates[start] > target) {
            return;   
        } 
        current.emplace_back(candidates[start]);
        if (candidates[start] == target){
            sol_.emplace_back(current);  
        }
        else{
            for (int i = start; i < candidates.size(); ++i){
                back_track(candidates, target-candidates[start], i, current); 
            }
        }
        current.pop_back();
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end()); 
        for (int start = 0; start < candidates.size(); ++start){
            vector<int> current = {}; 
            back_track(candidates, target, start, current); 
        }
        return sol_; 
    }
};
