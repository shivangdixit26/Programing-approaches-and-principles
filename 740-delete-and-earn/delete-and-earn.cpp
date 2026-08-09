class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int maxval=0;
        for(int num:nums){
            maxval=max(maxval,num);
        }
        vector<int>points(maxval+1,0);
        for(int num:nums){
            points[num]+=num;
        }
        int prev1=0;
        int prev2=0;
        for(int i=0;i<=maxval;i++ ){
            int current=max(prev1,prev2+points[i]);
            prev2=prev1;
            prev1=current;
        }
        return prev1;
        
    }
};