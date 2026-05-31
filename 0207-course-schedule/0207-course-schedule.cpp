class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph
        for (auto &pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];

            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        // Add courses with no prerequisites
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int completed = 0;

        while (!q.empty()) {

            int curr = q.front();
            q.pop();

            completed++;

            for (int next : adj[curr]) {
                indegree[next]--;

                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return completed == numCourses;
    }
};