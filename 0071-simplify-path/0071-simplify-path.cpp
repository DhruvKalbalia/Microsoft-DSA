class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        stringstream ss(path);//splits path string to individual words
        string dir;

        while(getline(ss, dir, '/')){
            if (dir.empty() || dir == "."){
                continue;
            }
            if (dir == ".."){
                if (!st.empty()){
                    st.pop_back();
                }
            }
            else{
                st.push_back(dir);
            }
        }
        string ans = "";

        for (string dir:st){
            ans += "/" + dir;
        }

        return ans.empty() ? "/":ans;
    }
};