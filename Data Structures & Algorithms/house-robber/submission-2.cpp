class Solution {
public:
    int dp_fun(vector<vector<int>>& dp,vector<int>& nums,int ind,int tot){
         if(ind >= nums.size()) return tot;

         if(dp[ind][tot] != -1) return dp[ind][tot];
         int robs = dp_fun(dp,nums,ind+2,tot+nums[ind]);
         int notRob = dp_fun(dp,nums,ind+1,tot);
         return dp[ind][tot] = max(robs,notRob);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int tot = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(n+1,vector<int>(tot+1,-1));
        return dp_fun(dp,nums,0,0);
    }
};
