class Solution {
public:
vector<int>parent;
vector<int>rnk;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n =edges.size();
        parent.resize(n+1);
        rnk.resize(n+1,0);
        for(int i =0;i<n;i++){
            parent[i]=i;
        }
        for(auto& edge:edges){
            if(find (edge[0])==find(edge[1]))return edge;
            unite(edge[0],edge[1]);
        }
        return {};
        
    }
    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x,int y ){
        int rootx= find(x);
        int rooty=find(y);
        if(rootx==rooty)return ;
        if(rnk[rootx]>rnk[rooty]){
            parent[rooty]=rootx;
        }
        else if(rnk[rooty]>rnk[rootx]){
            parent[rootx]=rooty;
        }
        else{
            parent[rootx]=rooty;
            rnk[rooty]++;
        }

    }
};