// https://leetcode.com/problems/palindrome-number/description/
// Determine whether an integer is a palindrome. Do this without extra space.
// negative numbers are not palindrom as er test case of q

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        long long rev=0;
        int y = x;
        bool flag = false;
        while(x){
            rev = rev*10 + x%10;
            x/=10;
        }
        if ((rev > INT_MIN && rev < INT_MAX) && (rev == y)){
            flag = true;
        }
        // if (rev == x) {
        //     return true;
        // }
        
        return flag;
    }
};