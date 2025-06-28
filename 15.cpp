class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = (int)(nums.size());
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int l = i + 1, r = n - 1; l < r;){
                long long sum3 = (long long)nums[i] + nums[l] + nums[r];
                if(sum3 == 0){
                    v.push_back({nums[i], nums[l], nums[r]});

                    while(l < r && nums[l] == nums[l+1]) l++;
                    while(r > l && nums[r] == nums[r-1]) r--;

                    l++;
                    r--;
                }

                if(sum3 < 0) l++;
                else if(sum3 > 0) r--;
            }
        }
        return v;
    }
};
