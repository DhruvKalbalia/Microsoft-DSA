class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> target;
        vector<int> ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (s.size()<totalLen)
        return ans;

        for (string word:words)
        target[word] ++;

        for (int offset = 0; offset<wordLen; offset++){
            int left = offset;
            int right = offset;
            int count = 0;

            unordered_map<string,int> window;

            while(right+wordLen <= s.size()){
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (target.find(word)==target.end()){
                    window.clear();
                    count = 0;
                    left = right;
                    continue;
                }

                window[word]++;
                count++;

                while(window[word]>target[word]){
                    string leftword = s.substr(left,wordLen);
                    window[leftword]--;
                    left+=wordLen;
                    count--;
                }

                if (count == wordCount){
                    ans.push_back(left);
                    string leftword = s.substr(left,wordLen);
                    window[leftword]--;
                    left+=wordLen;
                    count --;
                }
            }
        }
        return ans;
    }
};