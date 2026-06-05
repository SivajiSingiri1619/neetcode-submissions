class Solution {
public:
    int dp_fun(vector<int>& dp,vector<int>& nums,int ind){
         if(ind >= nums.size()) return 0;

         if(dp[ind] != -1) return dp[ind];

        return dp[ind] = max(dp_fun(dp,nums,ind+1),nums[ind]+dp_fun(dp,nums,ind+2));

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n+1,-1);
        return dp_fun(dp,nums,0);
    }
};
