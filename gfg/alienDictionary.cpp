class Solution {
    
  public:
    string findOrder(vector<string> &dict) {
        
        int N = dict.size();
        int K = 26;
        vector<int>used(K,0);
        for(auto &w : dict){
            for(char ch :w){
                used[ch-'a']=1;
            }
        }
        vector<vector<int>>adjList(K);
		for(int i = 0; i<N-1; i++){
			string s1 = dict[i];
			string s2 = dict[i+1];
			int len = min(s1.size(),s2.size());
			//creating the adjency list 
			bool foundDiff = false;

			for(int ptr = 0; ptr<len ; ptr++)
			{
				//finding the first non equal characters
				if(s1[ptr]!=s2[ptr]){
					adjList[s1[ptr]-'a'].push_back(s2[ptr]-'a');
					foundDiff = true;
					break;
				}
			}
			if(!foundDiff && s1.size()>s2.size()){
		    return "";
		}
		}
		

		//creating the indegree vector for topo sort algo..
		vector<int>indegree(K,0);
		for(int i =0; i<K ; i++){
			for(auto nbr: adjList[i]){
				indegree[nbr]++;
			}
		}
		queue<int>q;
		for(int i = 0 ; i<K; i++){
			if(used[i]&&indegree[i]==0) q.push(i);
		}
		int proceed = 0;
		string ans = "";
		while(!q.empty()){
			int top = q.front();
			q.pop();
			ans.push_back(char(top+'a'));
			proceed++;
			for(auto it:adjList[top]){
				indegree[it]--;
				if(used[it]&&indegree[it]==0){
					q.push(it);
				}
			}
		}
		//ans;
		// i got the topo in my ans with char
	   //if fall letters that were present in the dictionary were not processed -> we hit a loop 

	   
	   //cycle detection is missing
	   int c =0;
	   for(int itr = 0; itr<K; itr++){
	       if(used[itr]==1) c++;
	   }
	   if(c==ans.size())
	   {
	       return ans;
	   }
	   else {
	       return "";
	   }
	   
        
        
    }
};