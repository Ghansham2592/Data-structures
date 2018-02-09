// Reverse digits of an integer.
//https://leetcode.com/problems/reverse-integer/description/
// Example1: x = 123, return 321
// Example2: x = -123, return -321

// click to show spoilers.

// Note:
// The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.




class Solution {
public:
    int reverse(int x) {
        // long long n=x;
        long long rev =0;
        while(x!=0){
            rev = rev *10 + x%10;
            x = x/10;
        }
        if (rev < INT_MIN || rev > INT_MAX){
            return  0;
        } 
        return rev;
    }
};