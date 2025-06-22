#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << __FUNCTION__ << ":" << __LINE__ << " " << #x << " = " << x << endl

template<typename T>
T Max(const vector<T> v){
    return *max_element(v.begin(), v.end());
};

class Solution {
public:
    vector<vector<char>> buildMatrix(const string & s, int numRows){
        int cols = s.size();
        vector<vector<char>> matrix(numRows, vector<char>(cols, ' '));

        int row = 0, col = 0;
        bool goingDown = true;

        for(int i = 0; i < s.size(); i++){
            matrix[row][col] = s[i];

            if(goingDown){
                if(row == numRows - 1){
                    goingDown = false;
                    row--;
                    col++;
                } else {
                    row++;
                }
            } else {
                if (row == 0){
                    goingDown = true;
                    row++;
                } else {
                    row--;
                    col++;
                }
            }
        }
        return matrix;
    }

    string convert(string s, int numRows) {
        if(numRows == 1 || s.size() <= numRows) return s;
        auto zigzag = buildMatrix(s, numRows);

        string ans;

        for(const auto & row : zigzag){
            for(const char c : row){
                if(c != ' ') ans += c;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;


    // Call your function
    string s = "PAYPALISHIRING";
    int numRows = 3;

    cout << sol.convert(s, numRows) << '\n';

    // Output the result
    //cout << "Result: " << o << endl;

    return 0;
}

