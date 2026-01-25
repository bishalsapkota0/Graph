class Solution{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        using P = pair<int,int>;
        vector<int>dist(V,1e9);
        priority_queue<P,vector<P>, greater<P>>pq;
        dist[S]= 0;
        pq.push({dist[S],S});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it: adj[node]){
                int edge = it[1]; //node
                int adjNode= it[0]; //edge weight
                //edge releeaxation 
                if(dist[adjNode]>dist[node]+edge){
                    dist[adjNode] = dist[node]+ edge;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
         return dist;

    }
};