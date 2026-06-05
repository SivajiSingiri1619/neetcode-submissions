class Solution {
public:
    int dp_fun(int n,vector<long long>& dp){
          if(n <= 2) return 1;

          if(dp[n] != -1) return dp[n];
          int ans = 0;
          for(int i=1;i<n;i++){
              int left = max(i,dp_fun(i,dp));
              int right = max(n-i,dp_fun(n-i,dp));
              ans = max(ans,(left * right));
          }
          return dp[n] = ans;
    }
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        
        vector<long long>dp(n+1,-1);
        return dp_fun(n,dp);
    }
};