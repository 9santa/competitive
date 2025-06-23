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
    int maxArea(vector<int>& height) {
        int n = (int)(height.size());
        int maxA = 0;

        for(int l = 0, r = n - 1; l < r;){
            maxA = max(maxA, (min(height[l], height[r]) * (r - l)));
            if(height[l] < height[r]) l++;
            else r--;
        }
        return maxA;
    }
};

int main() {
    Solution sol;


    // Call your function
    vector<int> height{1,8,6,2,5,4,8,3,7};

    cout << sol.maxArea(height) << '\n';

    // Output the result
    //cout << "Result: " << o << endl;

    return 0;
}

