class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> us(wordList.begin(), wordList.end());
        if (!us.contains(endWord))
            return 0;

        us.erase(beginWord);
        us.erase(endWord);

        int l = beginWord.size();

        int k = 1;
        unordered_set<string> fr[2];
        fr[0].insert(beginWord);
        fr[1].insert(endWord);

        unordered_set<string> tmp{};

        while (!fr[0].empty() and !fr[1].empty()){
            bool s = fr[0].size() > fr[1].size();
            tmp.clear();

            for (string str : fr[s]){
                for (int j = 0; j < l; j++){
                    char o = str[j];
                    for (char t = 'a'; t <= 'z'; t++){
                        if (t == o)
                            continue;
                        str[j] = t;

                        if (fr[!s].contains(str))
                            return k + 1;

                        if (us.contains(str)){
                            tmp.insert(str);
                            us.erase(str);
                        }
                    }
                    str[j] = o;
                }
            }
            fr[s] = move(tmp);
            k++;            
        }
        return 0;
    }
};
