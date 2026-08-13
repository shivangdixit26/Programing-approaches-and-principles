class Solution {
public:
    string reverseWords(string s) {
        vector<string>order;
        string curr="";
        for(char ch:s){
            if(ch==' '){
               if(!curr.empty()){
                order.push_back(curr);
                curr="";
               }

            }
            else{
                curr=curr+ch;

            }
        }
        if(!curr.empty())order.push_back(curr);
        int n =order.size();
        if(n==0)return "";
        string ans="";
        for(int i =n-1;i>0;i--){
            ans+=order[i]+' ';
        }
        return ans+order[0];
        
    }
};