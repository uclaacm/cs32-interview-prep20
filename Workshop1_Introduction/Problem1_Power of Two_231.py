# UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

# Disclaimer: This is not the only valid solution and we do not claim our solutions 
# to be optimal in terms of runtime or memory usage, we are merely giving example 
# solutions to questions for learning purposes only

# Power of Two
# Leetcode Problem 231
# https://leetcode.com/problems/power-of-two/

class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """

        # 0 is not a power of two and is an edge case that would cause an 
        # infinite loop in our while loop below, so we handle it here
        if n == 0: return False
        
        # while n is divisible by 2, divide n by 2
        while n % 2 == 0:
            n /= 2
        
        # if n is a power of 2, at one point the loop above will have gotten
        # to a point where n is 2, and 2 / 2 = 1 and 1 % 2 != 0, so 
        # return true if n == 1 and false if n != 1
        return n == 1
                