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
Space Complexity: O(1) because our hash table will always have 26 keys as there are 26 characters in the english alphabet.
"""
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        letters = {} #initialize a dictionary that will contain the counts of all the characters.
        for c in "abcdefghijklmnopqrstuvwxyz":
            letters[c] = 0
        
        for c in s:
            if c in letters:            #we update the letter counts in the letters map.
                letters[c] += 1
        
        for c in t:                     #we update the letter counts in the letters map by decrementing already seen values.
            if c in letters:
                letters[c] -= 1
        
        for letter in letters:                  #this is a check if we have the same letters in both string s and t and same number of characters of each letter
           if letters[letter] != 0:
                return False
        
        return True


"""
Time Complexity: O(NlongN)
Space Complexity: O(N)
"""
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        ls = [] #list of characters for s
        for c in s:
            ls.append(c)
        lt = []
        for c in t:
            lt.append(c)
        ls = sorted(ls)
        lt = sorted(lt)
        for i in range(len(s)):
            if ls[i] != lt[i]:
                return False
        return True
