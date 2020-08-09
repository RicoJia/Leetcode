#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::for_each;

class NumMatrix {
    vector<vector<int>> matrix_sum_;
public:
    NumMatrix(){}
    NumMatrix(vector<vector<int>>& matrix):matrix_sum_(matrix) {
        if(matrix.size() == 0) return;
        for (int cln_i = 1; cln_i < matrix.at(0).size(); ++cln_i) {
            matrix_sum_.at(0).at(cln_i) += matrix_sum_.at(0).at(cln_i - 1);
        }

        for(int row_i = 1; row_i < matrix.size(); ++row_i) {
            matrix_sum_.at(row_i).at(0) += matrix_sum_.at(row_i-1).at(0);
        }

        for(int row_i = 1; row_i < matrix.size(); ++row_i){
            for (int cln_i = 1; cln_i < matrix.at(0).size(); ++cln_i) {
                matrix_sum_.at(row_i).at(cln_i) += (matrix_sum_.at(row_i).at(cln_i - 1) +
                                                    matrix_sum_.at(row_i - 1).at(cln_i) -
                                                    matrix_sum_.at(row_i - 1).at(cln_i - 1));
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0 && col1 == 0) return matrix_sum_.at(row2).at(col2);
        if(row1 == 0) return matrix_sum_.at(row2).at(col2) - matrix_sum_.at(row2).at(col1 - 1);
        if(col1 == 0) return matrix_sum_.at(row2).at(col2) - matrix_sum_.at(row1 - 1).at(col2);

        return matrix_sum_.at(row2).at(col2) + matrix_sum_.at(row1 - 1).at(col1 - 1) - matrix_sum_.at(row1 - 1).at(col2) - matrix_sum_.at(row2).at(col1 -1) ;
    }

    void print_map(){
        for_each(matrix_sum_.begin(), matrix_sum_.end(), [&](auto& row){
            for_each(row.begin(), row.end(), [&](auto& n){cout<<n<<" ";});
            cout<<endl;
        });
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */