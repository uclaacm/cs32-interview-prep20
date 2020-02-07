"""
    UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Backspace String Compare
    Leetcode Problem 844
    https://leetcode.com/problems/backspace-string-compare/

"""

class Solution(object):
    def backspaceCompare(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """

        # The strategy to solving this problem is to use a character stack.
        # Whenever you come across a '#', you pop a character off the stack,
        # if possible. When you do this for all characters in a string, the
        # stack contains the characters of the final typed string.

        # This function uses the character stack to determine the final typed string
        def applyBackspace(word):
            
            # initialize stack
            stack = []

            # traverse through each character in the string
            for i in range(len(word)):
 
                # if the current character is not a backspace,
                # add the current character to the stack
                if word[i] != '#':
                    stack.append(word[i])
                
                # otherwise, if the current character is a backspace
                # and the stack is not empty,
                # pop an element off the stack
                else:
                    if len(stack) > 0: stack.pop()

            # Stacks in Python are represented simply by lists,
            # so you can join the elements in the list together
            # for a more thorough explanation of the join function
            # see: https://www.geeksforgeeks.org/join-function-python/

            return "".join(stack)
        
        # Return true if S and T are the same once backspaces are applied
        # and false if their results of the applyBackspace function are not equal
        return applyBackspace(S) == applyBackspace(T)