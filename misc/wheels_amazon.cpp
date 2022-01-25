//https://leetcode.com/discuss/interview-question/1365052/amazon-oa
#include <vector>
#include <iostream>
using std::cout; using std::endl; 
using std::vector; 
int main()
{
    vector<int> total_wheels{6,3,2, 4, 5}; 
    vector<int> expected {2,0,1, 2, 0}; 

    vector<int> ret(total_wheels.size()); 
    int id = 0;
    for (const auto i: total_wheels){
        if (i%2 == 1) ret.at(id) = 0; 
        else{
            ret.at(id) = (i/4) + 1; 
        }
        ++id; 
    }
        
    bool correct = true; 
    for(int i = 0; i < total_wheels.size(); ++i){
        if (ret[i] != expected[i]) correct = false; 
        cout<<"expected: "<<expected[i]<<" | ret: "<<ret[i]<<endl; 
    }
    if (correct) cout<<"All correct"<<endl; 
    else cout<<"there's an error"<<endl;
}
