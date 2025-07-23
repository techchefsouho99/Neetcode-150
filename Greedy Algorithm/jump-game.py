class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n = len(nums)
        target = n - 1
        for i in range(n - 2, -1, -1):
            if nums[i] + i >= target:
                target = i
        return target == 0


# Example usage:
if __name__ == "__main__":
    sol = Solution()

    sol = Solution()
    print(sol.canJump([2,3,1,1,4]))  # True
    print(sol.canJump([3,2,1,0,4]))  # False

