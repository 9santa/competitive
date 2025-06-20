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
    int BelmanFord(vector<vector<int>> & times, int n, int k){
        vector<int> distance(n+1);
        for(int i = 1; i <= n; i++){
            distance[i] = INT_MAX;
        }
        distance[k] = 0;

        for(int i = 1; i <= n-1; i++){
            for( auto e : times ){
                int a = e[0], b = e[1], w = e[2];


                distance[b] = min(distance[b], distance[a] + w);
            }
        }

        int ans = Max(distance);
        return (ans != 2147483546) ? ans : -1;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        return BelmanFord(times, n, k);
    }
};

int main() {
    Solution sol;


    // Call your function
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4, k = 2;
    int o = sol.networkDelayTime(times, n, k);

    // Output the result
    cout << "Result: " << o << endl;

    return 0;
}

