class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char , char> smap;
        map<char , char> tmap;
        int i = 0;
        int j = 0;
        while(s[i] || t[j]){
            if(!s[i] || !t[j]) return false;
            if(smap.find(s[i]) != smap.end()){
                if(smap[s[i]] != t[j]) return false;
            }else{
                smap.insert({s[i], t[j]});
            }

            if(tmap.find(t[j]) != tmap.end()){
                if(tmap[t[j]] != s[i]) return false;
            }else{
                tmap.insert({t[j], s[i]});
            }
            i++;
            j++;
        }
        return true;
    }
};