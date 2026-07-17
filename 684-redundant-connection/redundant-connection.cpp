class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>>graph(n+1);
        for(auto& edge:edges){
            int u= edge[0];
            int v=edge[1];
            vector<bool>visited(n+1,false);
            if(isConnected(graph,u,v,visited))return edge;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return {};
        
    }
    bool isConnected(vector<vector<int>> &graph, int src, int dst, vector<bool> &visited){
        if(src==dst)return true;
        visited[src]=true;
        for( int neighbor:graph[src]){
            if (!visited[neighbor]){
                if(isConnected(graph, neighbor,dst,visited))return true;
            }
        }
        return false;
    }
};