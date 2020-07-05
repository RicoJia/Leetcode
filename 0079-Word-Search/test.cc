#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;

#include <vector>
using std::vector;
#include <string>
using std::string;

int main(){
    Solution s;
    vector<vector<char>> board = {
//            {'S', 'E', 'E'}
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
    };
    string word = "SEE";
//    cout<<word<<"status: "<<s.exist(board, word)<<endl;

    board = {{'a'}};
    word = "a";
    cout<<"word: "<<word<<" status: "<<s.exist(board, word)<<endl;

}