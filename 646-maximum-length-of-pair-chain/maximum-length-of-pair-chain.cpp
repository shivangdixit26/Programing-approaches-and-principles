class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](const vector<int>& a, const vector<int> &b){
            return a[1]<b[1];
        });
        int len=0;
        int chainend=-2000;
        for(auto& pair:pairs){
            if(pair[0]>chainend){
                len++;
                chainend=pair[1];
            }
        }
        return len;
        
    }
};