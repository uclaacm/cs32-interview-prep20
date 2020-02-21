"""
    UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Find Peak Element
    Leetcode Problem 162
    https://leetcode.com/problems/find-peak-element/

"""

"""
Time Complexity: O(NlogN)
Space Complexity: O(1)
"""
class Solution:
    def findPeakElement(self,nums):
        
        # Python uses a version of MergeSort to sort, so the sort has O(NlogN)
        # this finds the value of the peak value as the end of the sorted array
        peakVal = sorted(nums)[len(nums) - 1]

        # return the index of this maximum value
        for i in range(len(nums)):
            if nums[i] == peakVal:
                return i

"""
Time Complexity: O(N)
Space Complexity: O(1)
"""
class Solution:
    def findPeakElement(self,nums):
        peak = -sys.maxsize - 1 # minimum possible integer

        # find the index of the maximum value in the array in O(N)
        for i in range(len(nums)):
            if nums[i] > peak:
                peak = nums[i]
                index = i
        
        # return the location of this index
        return index

