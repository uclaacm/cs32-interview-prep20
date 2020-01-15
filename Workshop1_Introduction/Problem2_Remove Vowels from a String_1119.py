# UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

# Disclaimer: This is not the only valid solution and we do not claim our solutions 
# to be optimal in terms of runtime or memory usage, we are merely giving example 
# solutions to questions for learning purposes only

# Remove Vowels from a String
# Leetcode Problem 1119
# https://leetcode.com/problems/remove-vowels-from-a-string/

class Solution(object):
    def removeVowels(self, S):
        """
        :type S: str
        :rtype: str
        """
        # Warning: You are about to enter a Python magic zone

        # Python has a translate function that translates the ASCII value
        # of characters to another character when "translate" is called
        # See Example 2 of this tutorial:  https://www.programiz.com/python-programming/methods/string/translate
       
        # In this translation map, we are mapping the ASCII values to None
        # so that translate will translate these characters to no character
        translation = {
            ord('a'): None,
            ord('e'): None,
            ord('i'): None,
            ord('o'): None,
            ord('u'): None
        }
        
        # Cue the Python magic
        return S.translate(translation)