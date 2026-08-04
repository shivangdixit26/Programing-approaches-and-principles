class Solution {
    vector<int>parent,rnk;
    int find(int x){
        if(parent[x]!=x)parent[x]=find(parent[x]);
        return parent[x];
    }
    void unite(int x,int y){
        int rx= find(x);
        int ry=find(y);
        if(rnk[rx]<rnk[ry]){
            parent[rx]=parent[ry];
            rnk[rx]++;
        }
        else if(rnk[ry]<rnk[rx]){
            parent[ry]=parent[rx];
            rnk[ry]++;
        }
        else {
        parent[rx]=parent[ry];
        rnk[rx]++;
        }
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n =points.size();
        vector<array<int,3>>edges;
        for(int i =0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int cost= abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({cost,i,j});
            }
        }
        sort(edges.begin(),edges.end());
        parent.resize(n);
        rnk.resize(n);
        for(int i =0;i<n;i++)parent[i]=i;
        int totalcost=0;
        int edgeused=0;
        for(auto& ed:edges){
            int cost=ed[0];
            int u=ed[1];
            int v=ed[2];
            if(find(u)!=find(v)){
                unite(u,v);
                totalcost+=cost;
                edgeused++;
            }

        }
        return totalcost;
        
    }
};