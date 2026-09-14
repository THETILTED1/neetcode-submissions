class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        wordList.push_back(beginWord);

        unordered_map<string, unordered_set<string>> adj{};
        int l = beginWord.size();
        int n = wordList.size();

        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                int cts = 0;
                for (int k = 0; k < l; k++){
                    cts += wordList[i][k] != wordList[j][k];
                    if (cts > 1) break;                   
                }
                if (cts == 1){
                    adj[wordList[i]].insert(wordList[j]);
                    adj[wordList[j]].insert(wordList[i]);
                }
            }
        }

        if (!adj.contains(endWord)) return 0;

        unordered_map<string, int> levels{};

        queue<string> q{};
        q.push(beginWord);
        levels[beginWord] = 1;

        while (!q.empty()){
            string str = q.front();
            q.pop();

            if (str == endWord)
                return levels[endWord];

            for (const auto& i : adj[str]){
                if (levels[i] == 0){
                    q.push(i);
                    levels[i] = levels[str] + 1;
                }         
            }   
        }

        return 0;        
    }
};
