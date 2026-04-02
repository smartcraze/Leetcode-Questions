class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<bool> visited(n, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        
        pq.push({0, 0}); // {cost, node}
        int totalCost = 0;
        
        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();
            
            if (visited[u]) continue;
            
            visited[u] = true;
            totalCost += cost;
            
            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    int dist = abs(points[u][0] - points[v][0]) +
                               abs(points[u][1] - points[v][1]);
                    
                    pq.push({dist, v});
                }
            }
        }
        
        return totalCost;
    }
};