class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalsum=0;
        for(int num:nums)totalsum+=num;
        if(totalsum%2 !=0)return false;
        int target=totalsum/2;
        vector<bool>dp(target+1,false);
        dp[0]=true;
        for(int num:nums){
            for(int j =target;j>=num;j--){
                if(dp[j-num]){
                    dp[j]=true;
                }
                if(dp[target])return true;
            }
        }
        return dp[target];

        
    }
};