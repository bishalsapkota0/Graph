class Solution {
    private:
    bool dfs(int source, vector<int>&vis, vector<vector<int>>&adjList){
        if(vis[source]==1) return true; //current path
        if(vis[source]==2) return false; //its on another path
        
        vis[source]=1;//preorder vis
        for(auto nbr: adjList[source]){
            if(dfs(nbr,vis,adjList)) return true;
            
        }
        vis[source]=2;//post order visited
        return false;
    }
  public:
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
     vector<vector<int>>adjList(V);
       for(auto edge: edges){
           int u = edge[0];
           int v = edge[1];
           adjList[u].push_back(v);
       }
       vector<int>vis(V,0);
       for(int node = 0; node<V; node++){
           if(vis[node])continue;
            if(dfs(node,vis,adjList)==true) return true;
       }
       return false;
    }
};