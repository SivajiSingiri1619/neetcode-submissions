class Solution {
public:
    int dp_fun(vector<int>& nums,int target,vector<long long>& dp){
           if(target == 0) return 1;
           if(dp[target] != -1) return dp[target];
           int ways = 0;
           for(int i=0;i<nums.size();i++)
           if(target >= nums[i]){
              ways += dp_fun(nums,target - nums[i],dp);
           }
           return dp[target] = ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        
          vector<long long> dp(target+1,-1);

          return dp_fun(nums,target,dp);
    }
};