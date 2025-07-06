'''
*    Top K Frequent Elements: https://leetcode.com/problems/top-k-frequent-elements/description/
'''
from collections import defaultdict

class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        countmap = defaultdict(int)  # should use int for counting, not list
        freqarr = [[] for _ in range(len(nums) + 1)]
        finlst = []

        # Step 1: Count frequencies
        for num in nums:
            countmap[num] += 1

        # Step 2: Bucket sort by frequency
        for num, freq in countmap.items():
            freqarr[freq].append(num)

        # Step 3: Traverse buckets from high to low
        for i in range(len(nums), 0, -1):
            for ele in freqarr[i]:
                finlst.append(ele)
                if len(finlst) == k:
                    return finlst

        return finlst  # fallback

# Example usage:
if __name__ == "__main__":
    solution = Solution()

    nums = [1, 1, 1, 2, 2, 3]
    k = 2
    print(solution.topKFrequent(nums, k))  # Output: [1, 2]