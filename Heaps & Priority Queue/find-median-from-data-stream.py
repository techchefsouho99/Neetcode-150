import heapq
class MedianFinder(object):

    def __init__(self):

        # two heaps, large, small, minheap, maxheap
        # heaps should be equal size  
        self.small, self.large = [] , []

    def addNum(self, num):
        """
        :type num: int
        :rtype: None
        """
        heapq.heappush(self.small, -1 * num)

        # make sure every num small is <= every num in large
        if(self.small and self.large and ((-1 * self.small[0]) > self.large[0])):
            val = -1 * heapq.heappop(self.small)
            heapq.heappush(self.large, val)

        # uneven size
        if len(self.small) > len(self.large) + 1:
            val = -1 * heapq.heappop(self.small)
            heapq.heappush(self.large, val)
        
        if len(self.large) > len(self.small) + 1:
            val = -1 * heapq.heappop(self.large)
            heapq.heappush(self.small, val)
        

    def findMedian(self):
        """
        :rtype: float
        """
        if len(self.small) > len(self.large):
            return -1 * self.small[0]
        if len(self.small) < len(self.large):
            return self.large[0]
        else:
            return ( -1 * self.small[0] + self.large[0] ) / 2.0

# Example usage:
if __name__ == "__main__":
    solution = MedianFinder()

    # Test Case 1
    nums1 = [1, 2, 3, 1]
    print("Input:", nums1)
    print("Output:", solution.containsDuplicate(nums1))  # True