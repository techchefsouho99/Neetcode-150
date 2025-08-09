'''
* Valid Palingdrome: https://leetcode.com/problems/valid-palindrome/description/
'''

class Solution(object):
    def alphaNum(self, c):
        return (
            'A' <= c <= 'Z' or
            'a' <= c <= 'z' or
            '0' <= c <= '9'
        )

    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        l, r = 0, len(s) - 1
        while l < r:
            while l < r and not self.alphaNum(s[l]):
                l += 1
            while l < r and not self.alphaNum(s[r]):
                r -= 1
            if s[l].lower() != s[r].lower():
                return False
            l += 1
            r -= 1
        return True

# Example usage:
if __name__ == "__main__":
    sol = Solution()
    sol = Solution()
    print(sol.isPalindrome("A man, a plan, a canal: Panama"))  # Output: True
    print(sol.isPalindrome("race a car"))                      # Output: False
