class Solution {
    public int maxProfit(int[] prices) {
       int i = 0;
       int max = 0;
       int low = prices[0];
       while(i < prices.length){
        low = Math.min(low, prices[i]);
        max = Math.max(max, prices[i] - low);
        i++;
       }
       return max;
    }
}