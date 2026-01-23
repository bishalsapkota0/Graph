class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        queue<pair<string, int>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end())
            return 0;
        
        q.push({beginWord, 1});
    
        while (!q.empty()) { //n
            string word = q.front().first;
            int steps = q.front().second;
            if (word == endWord) {
                return steps;
            }
            q.pop();
            for (int i = 0; i < word.size(); i++) { //m 
                char original = word[i];
      
                for (char ch = 'a'; ch <= 'z'; ch++) { //26
                    word[i] = ch;
                    if (st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
       
        return 0;
    }
};