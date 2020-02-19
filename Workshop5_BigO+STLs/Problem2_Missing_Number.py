"""
    UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Backspace Valid Anagram 242
    Leetcode Problem 
    https://leetcode.com/problems/backspace-string-compare/

"""

"""
Time Complexity: O(N)
Space Complexity: O(1)
"""
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        sum = 0
        for val in nums:
            sum += val
        
        real_sum = n * (n+1) / 2
        missing_num = real_sum - sum
        
        return missing_num


"""
Time Complexity: O(N)
Space Complexity: O(N)
"""
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        numbers = {} #find all the numbers and store them in numbers
        for num in nums:
            numbers[num] = True
        
        for num in range(1, len(nums) + 1): #find the number from 1 to n which is not in numbers.
            if num not in numbers:
                return num