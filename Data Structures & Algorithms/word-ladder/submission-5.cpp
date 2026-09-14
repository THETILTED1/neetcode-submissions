class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> ws(wordList.begin(), wordList.end());
        if (!ws.contains(endWord))
            return 0;

        int l = beginWord.size();

        queue<string> q{};
        q.push(beginWord);
        int level = 1;
        
        while (!q.empty()){
            int qs = q.size();
            for (int i = 0; i < qs; i++){
                string str = q.front();
                q.pop();

                if (str == endWord)
                    return level;
                
                for (int j = 0; j < l; j++){
                    char o = str[j];
                    for (char t = 'a'; t <= 'z'; t++){
                        if (t == o)
                            continue;
                        str[j] = t;

                        if (ws.contains(str)){
                            q.push(str);
                            ws.erase(str);
                        }
                    }
                    str[j] = o;
                }
            }
            level++;
        }
        return 0;
    }
};
