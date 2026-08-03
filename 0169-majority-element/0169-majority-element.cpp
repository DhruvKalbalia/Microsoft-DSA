class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = NULL;
        int count = 0;

        for (int i=0; i<nums.size(); i++){
            if (count == 0){               
                count = 1;
                maj = nums[i];
            }else if (nums[i]==maj){
                count++;
            }else{
                count--;
            }
        }
        return maj;
    }
};