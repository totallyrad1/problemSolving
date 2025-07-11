class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        map<char , string> patterns;
        map<string , char> revpatterns;
        int i = 0;
        while(s[i] == ' ') i++;

        while(s[i]){
            string temp = "";
            while(s[i] != ' ' && s[i]){
                temp += s[i];
                i++;
            }
            words.push_back(temp);
            while(s[i] == ' ') i++;
        }

        if(words.size() != pattern.size()) return false;
        i = 0;
        while(pattern[i]){
            if(patterns.find(pattern[i]) != patterns.end() && words[i] != patterns[pattern[i]]){
                return false;
            }else if(revpatterns.find(words[i]) != revpatterns.end() && pattern[i] != revpatterns[words[i]]){
                return false;
            }
            else{
                patterns.insert({pattern[i], words[i]});
                revpatterns.insert({words[i], pattern[i]});
            }
            i++;
        }
        return true;
    }
};