
#     UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

#     Disclaimer: This is not the only valid solution and we do not claim our solutions 
#     to be optimal in terms of runtime or memory usage, we are merely giving example 
#     solutions to questions for learning purposes only

#     Two Sum
#     Leetcode Problem 1
#     https://leetcode.com/problems/two-sum/



class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        #we are implementing a hash map using a dictionary, 
        #we need to check if target - indice already exists.
        hashmap = {} #initialize hashmap
        for i, value in enumerate(nums): #enumerate makes a tuple that keeps track of the indice and the value of the list indice.
            temp = target - value #check the difference 
            if temp not in hashmap: #if the difference is not in the hashmap, hash the current indice in
                hashmap[value] = i
            else: #we found our match!
                return [hashmap[temp],i] 
                #return a list of two indices.
            
            