class Solution {
public:
    int climbStairs(int n) {
        int fromlast=1;
        int from2last=2;
        if(n<=2 )return n;
        
        for(int i =3;i<=n;i++){
            int current=fromlast+from2last;
            fromlast=from2last;
            from2last=current;
        }
        return from2last;
        
    }
};