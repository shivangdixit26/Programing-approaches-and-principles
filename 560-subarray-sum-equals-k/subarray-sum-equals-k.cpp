class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int prefixsum=0;
        unordered_map<int,int>sum;
        sum[0]=1;
        for(int num:nums){
            prefixsum+=num;
            if(sum.find(prefixsum-k)!=sum.end()){
                count+=sum[prefixsum-k];
            }
            sum[prefixsum]++;
        }
        return count;
        
    }
};