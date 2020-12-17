#include "solution.h"
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(){
    Solution s;
    vector<int> vec = {1,2,3, 4, 5};
    auto vecs = s.permute(vec);
    for (const auto &vec: vecs) {
        cout<< "I got: ";
        for (const auto &num: vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout<<"size of solution: "<<vecs.size()<<endl;

}
