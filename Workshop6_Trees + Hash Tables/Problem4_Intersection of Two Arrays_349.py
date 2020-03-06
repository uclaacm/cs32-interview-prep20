#     UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

#     Disclaimer: This is not the only valid solution and we do not claim our solutions 
#     to be optimal in terms of runtime or memory usage, we are merely giving example 
#     solutions to questions for learning purposes only

#     Intersection of Two Arrays
#     Leetcode Problem 349
#     https://leetcode.com/problems/intersection-of-two-arrays/

class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        outputlist = [] #this is the return list that we are returning
        hashmap = {} #hash map for keeping track of nums1
        for i,val in enumerate(nums1): #add everyvalue into hashmap, non duplicates
        # because we dont care about the indices.
            if val not in hashmap:
                hashmap[val] = i
        for i,val in enumerate(nums2): #check values in nums2
            if val in hashmap and val not in outputlist: #if the value is in hashmap already
            #and our value is not already in output, then append
                outputlist.append(val)
            
        return outputlist #return outputlist