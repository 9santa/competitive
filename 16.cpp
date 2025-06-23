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
    int threeSumClosest(vector<int>& nums, int target) {
        int n = (int)(nums.size());
        int closestDiff = INT_MAX;
        int closestSum = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    int sum3 = nums[i] + nums[j] + nums[k];
                    int diff = abs(sum3 - target);
                    if(diff < closestDiff){
                        closestDiff = diff;
                        closestSum = sum3;
                    }
                }
            }
        }
        return closestSum;
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

