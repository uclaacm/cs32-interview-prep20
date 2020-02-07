"""
    UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Implement Stack using Queues
    Leetcode Problem 225
    https://leetcode.com/problems/implement-stack-using-queues/
"""

class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q = []
        

    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.q.append(x)

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        top = self.q[len(self.q) - 1]
        self.q = self.q[:-1]
        return top

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self.q[len(self.q) - 1]
        

    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return len(self.q) == 0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
