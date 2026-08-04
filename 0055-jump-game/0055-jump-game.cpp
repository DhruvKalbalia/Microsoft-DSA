class Solution {
public:
    bool canJump(vector<int>& nums) {
        int fin = nums.size()-1;
        for (int idx=nums.size()-2; idx>=0; idx--){
            if (idx+nums[idx]>=fin){
                fin=idx;
            }
        }
        return fin==0;
    }
};