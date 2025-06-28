'''
* Group Anagrams: https://leetcode.com/problems/group-anagrams/description/
'''

from collections import defaultdict

class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        res = defaultdict(list)
        for s in strs:
            count = [0] * 26  # Count of each letter a-z
            for ch in s:
                count[ord(ch) - ord('a')] += 1
            res[tuple(count)].append(s)
        return list(res.values())  # Convert dict_values to list

# Example usage
if __name__ == "__main__":
    solution = Solution()
    input_strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
    result = solution.groupAnagrams(input_strs)
    print("Grouped Anagrams:")
    for group in result:
        print(group)