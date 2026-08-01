class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows=heights.size();
        int cols=heights[0].size();
        int directions[4][2]={{0,1},{0,-1},{-1,0},{1,0}};

        vector<vector<int>>efforts(rows,vector<int>(cols,INT_MAX));
        efforts[0][0]=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        pq.push({0,0,0});
        while(!pq.empty()){
            auto it=pq.top();
            int e=it[0];
            int r=it[1];
            int c=it[2];
            pq.pop();
            if(r==rows-1&& c==cols-1) return e;
            if(e>efforts[r][c])continue;
            for(auto& dir:directions){
                int nr=r+dir[0];
                int nc=c+dir[1];
                if(nr>=0 && nr<rows && nc>=0 && nc<cols){
                    int neweffort=max(e,abs(heights[nr][nc]-heights[r][c]));
                    if(efforts[nr][nc]>neweffort){
                        efforts[nr][nc]=neweffort;
                        pq.push({neweffort,nr,nc});
                    }
                }
            }

        }
        return efforts[rows-1][cols-1];

        
    }
};