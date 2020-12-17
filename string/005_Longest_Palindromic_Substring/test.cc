#include "solution.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(){
    Solution s;
    std::string a1 = "";
    std::string expect = "";
//    cout<<"got: "<<s.longestPalindrome(a1)<<" expected: "<<expect<<endl;

    a1 = "string";
    expect = "A single char";
    cout<<"got: "<<s.longestPalindrome(a1)<<" expected: "<<expect<<endl;

    a1 = "s";
    expect = "A single char";
    cout<<"got: "<<s.longestPalindrome(a1)<<" expected: "<<expect<<endl;

    a1 = "aba";
    expect = a1;
    cout<<"got: "<<s.longestPalindrome(a1)<<" expected: "<<expect<<endl;

    a1 = "abba";
    expect = a1;
    cout<<"got: "<<s.longestPalindrome(a1)<<" expected: "<<expect<<endl;

    a1 = "abbacdf";
    expect = "abba";
    cout<<"got: "<<s.longestPalindrome(a1)<<" expected: "<<expect<<endl;

    a1 = "abbacdfaba";
    expect = "abba";
    cout<<"got: "<<s.longestPalindrome(a1)<<" expected: "<<expect<<endl;


}


