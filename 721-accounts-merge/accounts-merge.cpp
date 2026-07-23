class Solution {
    unordered_map<string, string> parent;
    unordered_map<string, int> rank;

    string find(string x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(string x, string y) {
        string rootX = find(x);
        string rootY = find(y);
        if (rootX == rootY) return;
        
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,string>emailtoname;
        for(auto& account : accounts){
            string name = account[0];
            string firstemail= account[1];
            for(int i =1;i<account.size();i++){
                string email=account[i];
                emailtoname[email]=name;
                if(parent.find(email)==parent.end()){
                    parent[email]=email;
                    rank[email]=0;
                }
                unite(firstemail,email);
            }
            
        }
        unordered_map<string,vector<string>>groups;
        for(auto& [email,name]:emailtoname){
            string root=find(email);
            groups[root].push_back(email);
        }
        vector<vector<string>>result;
        for(auto& [root,emails]:groups){
            sort(emails.begin(),emails.end());
            emails.insert(emails.begin(),emailtoname[emails[0]]);
            result.push_back(emails);

        }
        return result;
    }
};