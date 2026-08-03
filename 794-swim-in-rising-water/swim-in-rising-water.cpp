class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n =grid.size();
        int low=max(grid[0][0],grid[n-1][n-1]);
        int high=n*n-1;
        while(high>low){
            int mid= (low+high)/2;
            if(canreach(grid,n,mid))high=mid;
            else low=mid+1;
            

        }
        return low;
        
    }
    private:
    bool canreach(vector<vector<int>>& grid,int n,int threshold){
        if(grid[0][0]>threshold)return false;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        queue<pair<int,int>>q;
        int directions[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
        visited[0][0]=true;
        q.push({0,0});
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            if(r==n-1 && c==n-1)return true;
            for(auto dir:directions){
                int nr=r+dir[0];
                int nc=c+dir[1];
                if(nr>=0 && nr<n && nc>=0 && nc<n && !visited[nr][nc] && grid[nr][nc]<=threshold){
                    visited[nr][nc]=true;
                    q.push({nr,nc});
                }

            }
        }
        return false;

    }
};