'''
* Linked List Cycle: https://leetcode.com/problems/linked-list-cycle/
'''

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        Floyd's Tortoise and Hare Algorithm
        Detects if a linked list has a cycle.
        Time: O(n), Space: O(1)
        :type head: ListNode
        :rtype: bool
        """
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True
        return False


# ---- Helper functions for testing ----
def create_linked_list_with_cycle(values, pos):
    """
    values: list of integers for node values
    pos: index where tail connects (-1 means no cycle)
    """
    if not values:
        return None
    nodes = [ListNode(v) for v in values]
    for i in range(len(nodes) - 1):
        nodes[i].next = nodes[i + 1]
    if pos != -1:
        nodes[-1].next = nodes[pos]
    return nodes[0]


if __name__ == "__main__":
    s = Solution()

    # Test 1: list with cycle
    head1 = create_linked_list_with_cycle([3, 2, 0, -4], 1)  # cycle at node index 1
    assert s.hasCycle(head1) == True

    # Test 2: list without cycle
    head2 = create_linked_list_with_cycle([1, 2], -1)
    assert s.hasCycle(head2) == False

    # Test 3: single node with no cycle
    head3 = create_linked_list_with_cycle([1], -1)
    assert s.hasCycle(head3) == False

    # Test 4: single node with cycle to itself
    head4 = create_linked_list_with_cycle([1], 0)
    assert s.hasCycle(head4) == True

    print("All tests passed ✅")
