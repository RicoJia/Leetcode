// https://leetcode.com/problems/subarrays-with-k-different-integers
// Method 1 - DP, O(N2)
class Solution {
public:
    std::vector<int> nums_;
    int cnt_;
    int k_;

    bool is_distinct(int l, int r){
        unordered_set<int> s;
        for (int i = l; i < r+1; ++i)
            s.insert(nums_.at(i));
        if (s.size() == k_)
            return true;
        else
            return false;
    }

    // [l,r], and no overflow
    bool is_good(int l, int r, bool not_yet_good){
        if (not_yet_good){
            return is_distinct(l, r);
        }
        else {
            auto res = std::find(nums_.begin()+l, nums_.begin()+r, nums_.at(r));
            return res != (nums_.begin() + r);
        }
        return false;
    }
    void dp(int l, int r, bool not_yet_good){
        if (r == nums_.size()) return;
        if (is_good(l, r, not_yet_good)){
            ++cnt_;
            dp(l, r+1, false);
        }
        // Failed: corner case: 1,2,1,3. dp to find
        else if (not_yet_good){
            dp(l, r+1, true);
        }

    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        nums_ = nums;
        cnt_ = 0;
        k_ = k;
        for (int l = 0; l < nums_.size() - (k - 1); ++l)
            dp(l, l+(k-1), true);
        return cnt_;
    }
};

// Method 2 - Smart O(N) - DP with "substrings with at most k substrings"
// at most characters: 
//  1. count from i until there's k+1 distinct chars. 
//      - As we count i, count+= (i-j+1), that means we have (i-j+1) substrings with not more than k distinct nums
//      - we are not counting the last i in, so at most K distinct nums
//  2. Then increment j, until frequency <= k
//      - we decrease the frequency. when it's 1, we erase it so we can use frequency.size() as an indicator
//      - when frequency <= k (remember last i is not counted in, so effectively substrings will have <= (k-1) distinct nums), we know there were (i-j+1) substrings with k distinct nums
#include <iostream>
#include <map>
using namespace std;

int substring_with_atmost_k_characters(string s , int k){
        if( k == 0){
            return 0;
        }
        map<int,int> frequency;
        int n = s.length();//length of string
        int j=0;
        int count = 0;
        for(int i=0;i<n;i++){
            frequency[s[i]]++;
            while(frequency.size() > k and j <= i){
                int p = frequency[s[j]]--;
                if(p == 1){
                    frequency.erase(s[j]);
                }
                j++;
            }
            count += (i-j+1);
        }
        return count;
    }

// main function
int main()
{
    string str = "xyzyxx";
    int k = 3;
    cout << "Total substrings with exactly "
         << k << " distinct characters: "
         << substring_with_atmost_k_characters(str,k) - substring_with_atmost_k_characters(str,k-1) << endl;
    return 0;
}

