class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int dr[]={0,0,1,-1};
        int dc[]={1,-1,0,0};
        vector<vector<int>>mincost(m,vector<int>(n,INT_MAX));
        deque<pair<int,int>>dq;
        dq.push_front({0,0});
        mincost[0][0]=0;
        while(!dq.empty()){
            auto [r,c]=dq.front();
            dq.pop_front();
            if(r==m-1 && c==n-1) return mincost[r][c];
            for(int i =0;i<4;i++){
                int nr= r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    int cost=(grid[r][c]==i+1)?0:1;
                    if(mincost[r][c]+cost<mincost[nr][nc]){
                        mincost[nr][nc]=mincost[r][c]+cost;
                        if(cost==0)dq.push_front({nr,nc});
                        else dq.push_back({nr,nc});
                    }
                }
            }
        }
        return 0;

        
    }
};