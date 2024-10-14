class Solution {
public:
    int helper(int i, vector<int>& nums,vector<int>& dp)
    {
        if(i>=nums.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        dp[i] = max(nums[i] + helper(i+2 , nums,dp) , helper(i+1,nums,dp) );
        return dp[i];
        
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        helper(0,nums,dp);
        return dp[0];
    }
};