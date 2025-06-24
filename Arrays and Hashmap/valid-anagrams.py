'''
* 242. Valid Anagrams: https://leetcode.com/problems/valid-anagram/description/
'''
class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        s_map = {}
        t_map = {}
        if len(s) != len(t):
            return False
        else:
            for i in range(len(s)):
                s_map[s[i]] = 1 + s_map.get(s[i],0)
                t_map[t[i]] = 1 + t_map.get(t[i],0)
            return s_map == t_map

# Example usage:
if __name__ == "__main__":
    solution = Solution()

    # Test Case 1
    s1 = "listen"
    t1 = "silent"
    print("Input:", s1, t1)
    print("Output:", solution.isAnagram(s1, t1))  # True

    # Test Case 2
    s2 = "rat"
    t2 = "car"
    print("\nInput:", s2, t2)
    print("Output:", solution.isAnagram(s2, t2))  # False

    # Test Case 3
    s3 = "aacc"
    t3 = "ccac"
    print("\nInput:", s3, t3)
    print("Output:", solution.isAnagram(s3, t3))  # False
