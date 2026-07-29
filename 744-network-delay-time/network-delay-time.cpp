class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto& t:times){
            adj[t[0]].push_back({t[1],t[2]});
        }
        vector<int>distance(n+1,INT_MAX);
        distance[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({k,0});
        while(!pq.empty()){
            auto[node,weight]=pq.top();
            pq.pop();
            if(distance[node]<weight)continue;
            for(auto& [next,wt]:adj[node]){
                if(distance[next]>weight+wt){
                    distance[next]=weight+wt;
                    pq.push({next,weight+wt});
                }
            }

        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(distance[i]==INT_MAX)return -1;
            ans=max(ans,distance[i]);
        }
        return ans;

        
    }
};