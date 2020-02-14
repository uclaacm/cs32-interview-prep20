"""
    UCLA ACM ICPC: Interview Track Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Sum of Array of Numbers
"""

# Given a vector of integers, use recursion to return the sum of
# the integers in the vector.

class Solution:
    def sumOfArray(self, arr) -> int:
        if len(arr) == 0:  #base case
            return 0
        else:
            return arr[0] + self.sumOfArray(arr[1:]) #recursive case. Add first number and pass on the rest to the next recursive call.