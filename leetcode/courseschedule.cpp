class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adjList(numCourses);
        vector<int>indegree(numCourses,0);
        queue<int>q;
        vector<int>list;
        //converting the edge list into adjency list 
        for(auto sub:prerequisites){
            int u = sub[0];
            int v = sub[1];
            adjList[u].push_back(v);
        }
        //calculating the indegree for all neighbour
        for(int i = 0; i<numCourses; i++){
            for(auto nbr: adjList[i]){
                indegree[nbr]++; 
            }
        }
       //pushing all node with indegree 0 to queue
        for(int i= 0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        //bfs ->kahns algo 
        while(!q.empty()){
            int top = q.front();
            q.pop();
            list.push_back(top);
            for(auto node: adjList[top]){
                indegree[node]--;
                if(indegree[node]==0){
                    q.push(node);
                }
            }
        }
        //detecting cycle 
        //no cycle->cannot complete the course;
        if(list.size()==numCourses){
                return true;
        }
        else{
            return false;
        }


        
    }
};