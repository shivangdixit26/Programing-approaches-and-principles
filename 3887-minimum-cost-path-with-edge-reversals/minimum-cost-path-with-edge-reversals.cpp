class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto& ed:edges){
            adj[ed[0]].push_back({ed[1],ed[2]}); 
            adj[ed[1]].push_back({ed[0],2*ed[2]});


        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        vector<long long>dist(n,LLONG_MAX);
        dist[0]=0;
        pq.push({0,0});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;
            if (u == n - 1) return d;

            for (const auto& [v, weight] : adj[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n - 1] == LLONG_MAX ? -1 : dist[n - 1];
    }
};