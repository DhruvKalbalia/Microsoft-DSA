class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;//unordered map hashing

        for (int i=0; i<nums.size(); i++){
            int complement = target - nums[i];//complement

            if (mp.count(complement))
                return {mp[complement], i};

            mp[nums[i]] = i;//reset
        }

        return {};
    }
};