"""
    UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Add Digits
    Leetcode Problem 258
    https://leetcode.com/problems/add-digits/

"""

# Recursive Solution
class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        
        if num % 10 == num: return num
        
        numSum = 0
        while num % 10 != num:
            numSum += num % 10
            num = num / 10
        numSum += num
        
        return self.addDigits(numSum)
