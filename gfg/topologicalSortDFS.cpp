/*
1/16/2026 8:58 PM 
https://www.geeksforgeeks.org/problems/topological-sort/1
Archit Agrawal;
*/
class Solution {
    private:
    void dfs(int &index ,int source, vector<bool>&vis, vector<int>&topo,
    vector<vector<int>>&adjList){
        if(vis[source]==true)return;
        vis[source]=true;
        
        for(auto nbr: adjList[source]){
            dfs(index,nbr, vis,topo, adjList);
        }
        topo[index]= source;
        index--;
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>topo(V);
       vector<vector<int>>adjList(V);
       for(auto edge: edges){
           int u = edge[0];
           int v = edge[1];
           adjList[u].push_back(v);
       }
        vector<bool>vis(V,false);
        int index = V-1;
        
        // calling dfs for each nodes 
        //passing i-> node/source , vis array , and topo to save our ans
         for(int i = 0; i <V; i++){
             dfs(index,i, vis,topo,adjList);
         }
         return topo;
        
    }
};