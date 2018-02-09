// https://leetcode.com/problems/two-sum/description/
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Example:
// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        int d,a = 0;
        int b = 0;
         vector <int> g1;
        // cin>>t;
        for(int i= 0;i<size;i++){
            d = target - nums[i];
            for(int j= i+1;j<size;j++){
                if (d == nums[j]) 
                    {
                        // a = i;
                        // b = j;
                   
                    g1.push_back(i);
                    g1.push_back(j);
                        return (g1);
                        // break;
                    }
            }
        }
        return (g1);
        
    }
};