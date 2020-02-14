"""
    UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Letter Combinations of a Phone Number
    Leetcode Problem 17
    https://leetcode.com/problems/letter-combinations-of-a-phone-number/
"""

class Solution:
    def __init__(self):
        self.map = {
            '2': ['a', 'b', 'c'],
            '3': ['d', 'e', 'f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z']
        } #initialize a map to store our number -> letters mapping
        self.result = {} #define a class result map that will store the combinations encountered thus far. 
                        #We can make quick checks to see if a combination we obtaind has already been accounted for (check for duplicates).
        
    def letterCombinations(self, digits: str) -> List[str]:
        if digits == "":    #handle bad input.
            return []
        self.letterCombinationsHelper(digits, "")   #call our helper.
        res = []    #we take our result map and add all the keys into the result list because leetcode wants our result to be in a list.
        for key in self.result:
            res.append(key)
        return res
    
    def letterCombinationsHelper(self, digits, comb):   #we define a helper function to help us with the recursion
        if digits == "":    #base case. We have no digits left to consider. if the combination is not already present in our result map then we add it to our results.
            if comb not in self.result:
                self.result[comb] = True
        else:
            for i in range(len(self.map[digits[0]])):   #we take the first digit and consider all possible combinations by iterating through all the letters that digit maps to.
                self.letterCombinationsHelper(digits[1:], comb+self.map[digits[0]][i])

