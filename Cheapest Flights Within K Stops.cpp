class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> graph[n];
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n, 1e9);

        for(auto &i : flights)
            graph[i[0]].push_back({i[1], i[2]});

        q.push({0, {src, 0}});
        dist[src] = 0;

        while(!q.empty()){
            auto i = q.front();
            q.pop();

            int stops = i.first;
            int node = i.second.first;
            int cost = i.second.second;

            if(stops > k)
                continue;
            for(auto &j : graph[node]){
                int adjNode = j.first;
                int endNode = j.second;

                if(cost + endNode < dist[adjNode] and stops <= k){
                    dist[adjNode] = cost + endNode;
                    q.push({stops+1, {adjNode, cost + endNode}});
                }
            }
        } 

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
