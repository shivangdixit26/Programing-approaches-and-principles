class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        
        vector<double> maxfound(n, 0.0);
        maxfound[start_node] = 1.0;

       
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            auto topPair = pq.top();
            pq.pop();

            double prob = topPair.first;
            int node = topPair.second;

           
            if (node == end_node) return prob;

           
            if (prob < maxfound[node]) continue;

            for (auto& neighbor : adj[node]) {
                int next = neighbor.first;
                double edgeProb = neighbor.second;

                if (prob * edgeProb > maxfound[next]) {
                    maxfound[next] = prob * edgeProb;
                    pq.push({maxfound[next], next});
                }
            }
        }

        return maxfound[end_node];
    }
};