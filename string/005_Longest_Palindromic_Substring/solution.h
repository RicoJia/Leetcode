#include <string>
#include <algorithm>
using std::string;
using std::max;

#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
// Manacher's Algorithm is used here
    string longestPalindrome(string s) {
       // Naive Solution: at each element, expand towards both ends. See if they're better solutions.
       //Corner cases: empty string. Single letter. Even palindrome is also an option.
       if (s.empty()) return "";

        auto get_pa_len = [&](int l, int r) {
            if (l < 0 || r > s.size() - 1 || s[l] != s[r]) return 1;
            while (l >= 0 && r < s.size()) {
                if (s[l] == s[r]) {
                    --l;
                    ++r;
                }
                else break;
            }
            return r - l - 1;
        };

        int max_len = 0;
        int max_pos = 0;
        for(int i = 0; i < s.size(); ++i){
            int pa_len = max(get_pa_len(i, i), get_pa_len(i, i + 1));
            if (max_len < pa_len){
                max_pos = i;
                max_len = pa_len;
            }
        }
        //even: [max_pos - (pa_len/2 - 1), max_pose + pa_len/2] odd: [max_pos - (pa_len - 1)/2, max_pos + (pa_len)/2]
        int l = (max_len % 2) ==0 ? max_pos - (max_len/2 - 1) :  max_pos - (max_len - 1)/2;
        return  s.substr(l,max_len);
}
};
