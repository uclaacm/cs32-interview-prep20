"""
    UCLA ACM ICPC: Interview Track Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Group Integers
"""

# Given a list of integers, return whether is it possible to
# choose a group of some of the integers such that the group sums
# to the given target

class Solution:
    def groupIntegers(self, nums, target) -> bool:
        if len(nums) < 0:  #just a random sanity check
            return False
        if len(nums) <= 0 and target != 0: #base case 1: we have run out of numbers to pick but we have not reached 0
            return False
        elif target == 0:     #base case 2: we may or may not have run out of numbers to pick from but we have reached our target and found our group.
            return True
        else:
            #we could choose to pick the first number to be in our group.
            remaining_target = target - nums[0]
            remaining_list = nums[1:]
            #we could also not choose to pick the first number of the list in which case target will remain the same but we discard the first element.            
            return self.groupIntegers(remaining_list, remaining_target) or self.groupIntegers(remaining_list, target)
