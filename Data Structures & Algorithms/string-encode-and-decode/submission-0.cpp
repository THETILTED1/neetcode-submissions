class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for (string s : strs){
            result += to_string(s.size());
            result += '#';
            result += s;
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result{};
        int id = 0;

        while (id < s.size()){
            int x = s.find("#", id);
            int l = stoi(s.substr(id, x - id));
            result.push_back(s.substr(x + 1, l));
            id += (x - id + 1 + l);
        }

        return result;
    }

};
