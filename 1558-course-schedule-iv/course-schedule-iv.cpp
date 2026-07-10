class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    vector<vector<int>> adj(numCourses);
    for (auto& pre : prerequisites) {
        adj[pre[0]].push_back(pre[1]);
    }

    vector<vector<bool>> isPre(numCourses, vector<bool>(numCourses, false));
    
    
    for (int i = 0; i < numCourses; ++i) {
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int neighbor : adj[curr]) {
                if (!isPre[i][neighbor]) {
                    isPre[i][neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    vector<bool> answer;
    for (auto& q : queries) {
        answer.push_back(isPre[q[0]][q[1]]);
    }
    return answer;
}
};