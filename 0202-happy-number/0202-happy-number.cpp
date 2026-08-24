class Solution {
public:
    int sumSquare(int n){
        int sum = 0;
        while(n>0){
            int digit = n%10;
            sum += digit*digit;
            n = n/10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_map<int,bool> mp;
        while(n!=1){
            if (mp.find(n) != mp.end())
            return false;

            mp[n] = true;
            n = sumSquare(n);
        }
        return true;
    }
};