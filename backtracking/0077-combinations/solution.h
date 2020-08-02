#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

class Solution {
private:
    vector<vector<int>> ret_;
    void DFS_append(int first_num, int size, int n, vector<int>& vec){
        if(vec.size() == size) {
            ret_.push_back(vec);
            return;
        }
        for(int num = first_num; num <=n; ++num){   // think of [...1 ...],[...2...]...
            vec.push_back(num);
            DFS_append(num+1, size, n, vec);
            vec.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        int size = 1;
        //calculate the size of the array.
        for (int i = 0; i < k; ++i){
            size *= (int)((n-i)/(1.0 + i));
        }
        ret_.reserve(size);    //n*(n-1)...(n-k+1)/(1 * ... k)

        vector<int> vec;
        DFS_append(1, k, n, vec);

        return ret_;
    }
};