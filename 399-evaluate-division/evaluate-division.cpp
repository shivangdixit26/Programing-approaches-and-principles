class Solution {
    double dfs(string src, string dst,unordered_set<string>&visited,unordered_map<string,vector<pair<string,double>>>&adj){
        if(adj.find(src)==adj.end() || adj.find(dst)==adj.end()) return -1.0;
        if (src==dst)return 1.0;
        visited.insert(src);
        for(auto& neigbor :adj[src]){
            string next=neigbor.first;
            double weight=neigbor.second;
            if(visited.find(next)==visited.end()){
                double result=dfs(next,dst,visited,adj);
                if(result!=-1.0){
                    return result*weight;
                }
            }
        }
        return -1.0;


    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>adj;
        for(int i =0;i<equations.size();i++){
            auto u= equations[i][0];
            auto v =equations[i][1];
            double z=values[i];
            adj[u].push_back({v,z});
            adj[v].push_back({u,1/z});
        }
        vector<double>ans;
        for(auto& q:queries){
            unordered_set<string>visited;
            ans.push_back(dfs(q[0],q[1],visited,adj));
        }
        return ans;
    }
};