'''
* Maximum Subarray: https://leetcode.com/problems/maximum-subarray/description/
'''

class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxSub = nums[0]
        currSum = 0
        for num in nums:
            if currSum < 0:
                currSum = 0
            currSum += num
            maxSub = max(maxSub, currSum)
        return maxSub

# Example usage:
if __name__ == "__main__":
    solution = Solution()

    sol = Solution()
    print(sol.maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))  # Output: 6 (subarray [4,-1,2,1])