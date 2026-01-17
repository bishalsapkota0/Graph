class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int>list;
        //1. creating adjency List.
        
        vector<vector<int>>adjList(V);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
        }
        queue<int>q;
        vector<int>indegree(V,0);
        
        for(int i = 0; i<V; i++){
            for(int nbr: adjList[i]){
                indegree[nbr]++;
            }
        }
        //pushing all the node with indegree 0 into queue
        for(int i = 0; i<V; i++){
            if(indegree[i]==0) q.push(i);
          
        }
        //Kahn's algo  bfs
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            list.push_back(top);
            for(auto nbr: adjList[top]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
         if(list.size()==V)
         {
             return false;
         }
         return true;
        
        
        
    }
    
};