'''
* Contains Duplicate: https://leetcode.com/problems/contains-duplicate/description/
'''

class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        seen = set()
        for num in nums:
            if num in seen:
                return True
            seen.add(num)
        return False

# Example usage:
if __name__ == "__main__":
    solution = Solution()

    # Test Case 1
    nums1 = [1, 2, 3, 1]
    print("Input:", nums1)
    print("Output:", solution.containsDuplicate(nums1))  # True

    # Test Case 2
    nums2 = [1, 2, 3, 4]
    print("\nInput:", nums2)
    print("Output:", solution.containsDuplicate(nums2))  # False

    # Test Case 3
    nums3 = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
    print("\nInput:", nums3)
    print("Output:", solution.containsDuplicate(nums3))  # True
