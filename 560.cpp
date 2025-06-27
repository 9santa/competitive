class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> freq;
        freq[0] = 1;
        int cnt = 0;
        int prefix = 0;
        
        for (const int &num : nums){
            prefix += num;

            if(freq[prefix - k]) cnt += freq[prefix - k];

            freq[prefix]++;
        }
        return cnt;
    }
};
