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
        // Define a lambda function that returns the length of a palindrome at a position.
        //if l or r are out of boundaries,
        auto get_pa_length = [&](int l, int r){
            int length = s.length();
            if (l < 0 || r >= length ){
                return 0;
            }
            // This is a difficult part. Be aware that a single letter could be palindrome.
            while(l >= 0 && r <= length-1 && s[r] == s[l]){
                --l; ++r;
            }
            return r-l-1;
        };

        // there's an odd palindrome(e.g, bab) and even palindrome (e.g, baab)
        int max_length = 0; int max_position = 0;
        for (int i = 0; i < s.length(); ++i){
            int i_max_length = max(get_pa_length(i,i), get_pa_length(i, i+1));
            if (i_max_length > max_length){
                max_length = i_max_length;
                max_position = i;
            }
        }

        return s.substr(max_position - (max_length-1)/2, max_length);
    }
};
