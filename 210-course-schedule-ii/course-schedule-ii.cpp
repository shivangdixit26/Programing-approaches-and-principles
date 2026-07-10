class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses);
        for(vector<int> pre:prerequisites){
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
            
        }
        vector<int>result;
        while(!q.empty()){
            int course=q.front();
            q.pop();
            result.push_back(course);
            for(int neighbor:adj[course]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0)q.push(neighbor);
            }

        }
        return (result.size()==numCourses)?result:vector<int>{};
        
    }
};