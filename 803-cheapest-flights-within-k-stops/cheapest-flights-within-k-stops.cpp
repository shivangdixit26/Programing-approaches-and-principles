class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto& flight:flights){
            adj[flight[0]].push_back({flight[1],flight[2]});

        }
        vector<int>price(n,INT_MAX);
        price[src]=0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stops>k )continue;
            for(auto& [next,spend]:adj[node]){
                if(price[next]>cost+spend){
                    price[next]=cost+spend;
                    q.push({1+stops,{next,cost+spend}});
                }
            }

        }
        return (price[dst]!=INT_MAX)?price[dst]:-1;
        
    }
};