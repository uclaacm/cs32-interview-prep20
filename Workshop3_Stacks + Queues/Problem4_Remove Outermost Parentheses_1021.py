"""
    UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Remove Outermost Parentheses
    Leetcode Problem 1021
    https://leetcode.com/problems/remove-outermost-parentheses/

"""

class Solution(object):
    def removeOuterParentheses(self, S):
        """
        :type S: str
        :rtype: str
        """
        result = ""
        st = []
        
        for curChar in S:
            if (len(st) == 0):
                st.append('(')
            elif (len(st) == 1 and curChar == ')'):
                st.pop()
            elif (curChar == '('):
                st.append('(')
                result += curChar
            else:
                st.pop()
                result += curChar
                
        return result
