'''
* Container With Most Water: https://leetcode.com/problems/container-with-most-water/
'''


from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        """
        Two-pointer solution for 'Container With Most Water'.
        Time: O(n), Space: O(1)
        """
        lp, rp = 0, len(height) - 1
        maxVol = 0
        while lp < rp:
            width = rp - lp
            h = height[lp] if height[lp] < height[rp] else height[rp]
            maxVol = max(maxVol, width * h)
            if height[lp] < height[rp]:
                lp += 1
            else:
                rp -= 1
        return maxVol

# ---- Run some quick checks when executed directly ----
if __name__ == "__main__":
    s = Solution()

    # Basic tests
    assert s.maxArea([1,8,6,2,5,4,8,3,7]) == 49   # classic example
    assert s.maxArea([1,1]) == 1
    assert s.maxArea([4,3,2,1,4]) == 16
    assert s.maxArea([1,2,1]) == 2
    assert s.maxArea([1]) == 0                    # not enough lines -> 0
    assert s.maxArea([]) == 0

    # Optional: small interactive run
    print("All tests passed ✅")
    # Example usage:
    example = [1,8,6,2,5,4,8,3,7]
    print(f"maxArea({example}) = {s.maxArea(example)}")
