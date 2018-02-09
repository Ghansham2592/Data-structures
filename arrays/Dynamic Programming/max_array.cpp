// https://leetcode.com/problems/maximum-subarray/description/
// Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

// For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
// the contiguous subarray [4,-1,2,1] has the largest sum = 6. 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int a_size =nums.size();
        int dp[a_size];
        dp[0] = nums[0];
        int max_a = dp[0];
        for(int i = 1; i<a_size;i++){
            dp[i]= nums[i] + (dp[i-1] > 0? dp[i-1] : 0);
            max_a = max(max_a, dp[i]); 
        }
        return max_a;
        
    }
};