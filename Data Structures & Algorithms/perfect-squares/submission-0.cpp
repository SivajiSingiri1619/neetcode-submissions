class Solution {
public:
      int dp_fun(vector<long long>& squares,int val,int ind,vector<vector<int>>& dp){
         if(val == 0) return 0;
         if(ind < 0) return 1e9;

         if(dp[ind][val] != -1) return dp[ind][val];

         int notPick = dp_fun(squares,val,ind-1,dp);
         int pick = 1e9;
         if(val >= squares[ind]){
              pick = dp_fun(squares,val-squares[ind],ind,dp);
         }
        return dp[ind][val] = min(pick+1,notPick);
    }
    int numSquares(int n) {
         vector<long long> squares;
         for(int i=1;(i*i) <= n;i++){
             squares.push_back(i*i);
             if(n == i*i) return 1;
         }
         vector<vector<int>>dp(squares.size(),vector<int>(n+1,-1));
        return dp_fun(squares,n,squares.size()-1,dp);
    }
};