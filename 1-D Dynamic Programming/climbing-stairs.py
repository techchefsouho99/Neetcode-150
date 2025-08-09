'''
* Climbing Stairs: https://leetcode.com/problems/climbing-stairs/description/
'''

class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        # cache = [-1] * n
        # def dfs(i):
        #     if i >= n:
        #         return i == n
        #     if cache[i] != -1:
        #         return cache[i]
        #     cache[i] = dfs(i + 1) + dfs(i + 2)
        #     return cache[i] 
        # return dfs(0) 

        one , two = 1 , 1
        for _ in range(n-1):
            one, two = one + two, one
        return one

# Example usage:
if __name__ == "__main__":
    sol = Solution()

    sol = Solution()
    print(sol.climbStairs(5))  # Output: 8    