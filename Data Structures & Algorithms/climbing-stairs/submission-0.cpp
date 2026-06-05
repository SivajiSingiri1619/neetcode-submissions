class Solution {
public:
    int dp_fun(int target,vector<int>& dp){
          if(target == 0) return 1;
          if(dp[target] != -1) return dp[target];

          int pick1 =(target >= 1) ? dp_fun(target-1,dp) : 0;
          int pick2 = (target >= 2) ? dp_fun(target-2,dp) : 0;

          return dp[target] = (pick1+pick2);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
       return dp_fun(n,dp);
    }
};
