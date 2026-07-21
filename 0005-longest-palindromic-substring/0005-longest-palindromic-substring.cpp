class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxLen = 1;
        int n = s.size();

        for (int i=0; i<n; i++){
            int l=i,r=i;//odd palin
            while(l>=0 && r<n && s[l]==s[r]){
                if (r-l+1>maxLen){
                    maxLen = r-l+1;
                    start = l;
                }
                l--;
                r++;
            }

            l=i,r=i+1;//even palin
            while(l>=0 && r<n && s[l]==s[r]){
                if (r-l+1>maxLen){
                    maxLen = r-l+1;
                    start = l;
                }
                l--;
                r++;
            }
        }

        return s.substr(start,maxLen);
    }
};