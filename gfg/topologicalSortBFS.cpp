class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        //1.converting edge list into adjency list 
        vector<vector<int>> adjList(V);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
        }
        //topological sort using bfs 
        vector<int>indegree(V,0);//to store indegree
        queue<int>q; 
        vector<int>list;//this will have asnwer
        
        //counting indegree for each node
        for(int i =0; i<V; i++){
            for(auto nbr: adjList[i]){
                indegree[nbr]++;
            }
        }
         for (int i = 0; i < V; i++){
             if (indegree[i] == 0)q.push(i);
         }
        
        //BFS - > using Kahn's Algorighm
        while(!q.empty()){
            int top = q.front();
            q.pop();
            list.push_back(top);
            for(auto next: adjList[top]){
                indegree[next]--;
                if(indegree[next]==0){
                    q.push(next);
                }
            }
            
        }
        return list;
    }
};