"""
    UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Climbing Stairs
    Leetcode Problem 70
    https://leetcode.com/problems/climbing-stairs/
"""

# Suppose you are climbing a set of stairs that has n steps.
# Every step you take, you can climb up either one step or two steps.
# Return the number of distinct ways you can climb up the stairs.

class Solution:
    def climbStairs(self, int n) -> int:
        if(n < 0):
            # bad input case
            return 0
        elif(n == 1):   #base case
            # If there is only one step, trivially, we can only climb up
            # the step by taking one step.
            return 1
        elif(n == 2):   #base case
            # If there are only two steps, trivially, we can only climb up
            # the step by taking one step + one step, or by taking 2 steps.
            return 2
        else:
            # Now suppose we have a set of N steps. We have two choices:
            # Climb 1 step, or climb 2 steps. If we climb 1, then we
            # still have N-1 steps to go. If we climb 2, then we still
            # have N-2 steps to go. If we assume we already know how to
            # calculate climbStairs(N-1) and climbStairs(N-2), then we
            # are done.
            return self.climbStairs(n-1) + self.climbStairs(n-2)