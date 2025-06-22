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
    vector<int> bfs(const vector<vector<int>> & flights, int src){
        int n = flights.size();
        vector<int> dist(n, -1);
        queue<int> q;

        dist[src] = 0;
        q.push(src);

        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(const auto & e : flights[u]){
                int v = e.first;

                if(dist[v] == -1){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    }


    vector<int> BelmanFord(vector<vector<int>> & flights, int n, int src){
        vector<int> distance(n+1);
        for(int i = 1; i <= n; i++){
            distance[i] = INT_MAX;
        }
        distance[src] = 0;

        for(int i = 1; i <= n-1; i++){
            for( const auto & e : flights ){
                int a = e[0], b = e[1], w = e[2];


                distance[b] = min(distance[b], distance[a] + w);
            }
        }

        return distance;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist = bfs(flights, src);
        if(dist[dst] > k - 1){
            return -1;
        } else {
            vector<int> distance = BelmanFord(flights, n, src);
            return distance[dst];
        }
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

