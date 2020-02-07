"""
    UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Valid Parentheses
    Leetcode Problem 20
    https://leetcode.com/problems/valid-parentheses/

"""

class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """

        # The strategy for this problem is to traverse through
        # the the string and push open parentheses onto the stack
        # and then pop them off the stack once we enocounter their
        # closed parenthesis counterpart.
        
        # We create a dictionary mapping closed parentheses to 
        # their equivalent open parentheses so we can check if
        # what we popped off of the stack corresponds to the 
        # closed parenthesis we currently have
        par = {")":"(","}":"{","]":"["}
        stack = []
        
        # Traverse through all the characters in s
        # An assumption we make here based on the prompt of
        # the question is that there are only parentheses in
        # this string
        for char in s:
            
            # Since our dictionary has closed parenthesis keys,
            # we know that if the current character is not in
            # the dictionary, it's an open parenthesis
            if char not in par:

                # Add open parentheses to the stack
                stack.append(char)

            # Otherwise, we know it's a closed parenthesis
            else: 

                # If the stack is empty, this means we have a 
                # closed parenthesis without any open parentheses
                # before it, so we know this is invalid
                if len(stack) == 0: return False

                # Otherwise, if the top of the stack constains the 
                # open counterpart to your current closed parenthesis,
                # then you have a valid pair, so you can pop the open
                # parenthesis off the stack
                elif stack[-1] == par[char]:
                    # (arr[-1] in Python gives you the last element in a list, 
                    # which is the top of the stack)
                    stack.pop()
                
                # Otherwise, this is not the correct pairing of open and closed
                # parentheses, so the string has invalid parentheses
                else: return False
        
        # Return True if the stack is empty (all parentheses come in pairs)
        # and False if there are left over open parentheses without a match
        return len(stack) == 0