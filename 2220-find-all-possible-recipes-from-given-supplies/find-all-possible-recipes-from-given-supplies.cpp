class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>>adj;
        unordered_map<string,int>indegree;
        for(const string& recipe:recipes){
            indegree[recipe]=0;
        }
        for(int i =0;i<recipes.size();i++){
           string recipe=recipes[i] ;
           for(auto ingridient:ingredients[i]){
            adj[ingridient].push_back(recipe);
            indegree[recipe]++;
           }
        }
        queue<string>q;
        for(auto supply:supplies){
            q.push(supply);
        }
        unordered_set<string>recipeset(recipes.begin(),recipes.end());
        vector<string>result;
        while(!q.empty()){
            string curr=q.front();
            q.pop();
            if(recipeset.count(curr))result.push_back(curr);
            for(auto neighbor:adj[curr]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0)q.push(neighbor);
            }
        }
        return result;
    }
};