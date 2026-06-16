class Solution {
public:
    int recur(vector<int>& nums,int i,int tot){
         if(i == nums.size()) return tot;

         return recur(nums,i+1,tot^nums[i]) + recur(nums,i+1,tot);
    }
    int subsetXORSum(vector<int>& nums) {
        
        return recur(nums,0,0);
          
    }
};