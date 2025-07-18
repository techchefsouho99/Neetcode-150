'''
* Product Of Array Except Self : https://leetcode.com/problems/product-of-array-except-self/description/
'''
class Solution(object):
    def productExceptSelf1(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        pref = [1] * n
        suff = [1] * n
        res = [0] * n

        # Build prefix products
        for i in range(1, n):
            pref[i] = nums[i - 1] * pref[i - 1]

        # Build suffix products
        for i in range(n - 2, -1, -1):
            suff[i] = nums[i + 1] * suff[i + 1]

        # Multiply prefix and suffix for result
        for i in range(n):
            res[i] = pref[i] * suff[i]

        return res

# Example usage:
if __name__ == "__main__":  

    sol = Solution()
    print(sol.productExceptSelf1([1, 2, 3, 4]))  # Output: [24, 12, 8, 6]