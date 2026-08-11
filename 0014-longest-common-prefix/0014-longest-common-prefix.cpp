class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];//first word

        for (int i=1; i<strs.size(); i++){
            while(strs[i].find(prefix)!=0)//compares word
            prefix.pop_back();//removes last char
        }

        return prefix;
    }
};