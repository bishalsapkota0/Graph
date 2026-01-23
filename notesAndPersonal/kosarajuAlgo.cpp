class Solution {
   private:
   void dfs(int node, vector<int>&vis, vector<int>adj[],stack<int>&st){
     vis[node]=1;
     for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, vis, adj, st);
        }
     }
     st.push(node);
   }
    void helperDFS(int node, vector<int> &vis, vector<int> adjT[]) {
        // helper function that will do dfs for each component and gives number
        // of strongly connected component.
        vis[node] = 1;
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                helperDFS(it, vis, adjT);
            }
        }
    }

   public:
    int kosaraju(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        stack<int> st;
        // initial dfs to store the nodes in stack based on their finishig time
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }
        // reverse the graph
        vector<int> adjT[V];
        // reversing the graph
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (auto it : adj[i]) {
                adjT[it].push_back(i);
            }
        }
        int count = 0;
        while (!st.empty()) {
            // get the top most node
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                count += 1;
                helperDFS(node, vis, adjT);
            }
        }
        return count;
    }
};
