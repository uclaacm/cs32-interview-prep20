/*
    UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Valid Parentheses
    Leetcode Problem 20
    https://leetcode.com/problems/valid-parentheses/
*/

class Solution {
public:

    // The strategy for this problem is to use a character stack.
    // We traverse the string from left to right, putting open
    // parenthesis into the stack, and attemping to match closing
    // parenthesis with the top of the stack.
    bool isValid(string s) {
        stack<char> stack;
        for(int i = 0; i < s.size(); i++) {
            char cur = s[i];

            // If the current character is an open parenthesis,
            // push it onto the stack
            if(cur == '(' || cur == '{' || cur == '[') {
                stack.push(cur);
            }

            // If the current character is ')', first check
            // if the stack is empty. If it is, then ')' can't
            // be matched with anything. Next, check if the 
            // top of the stack is '('. It it isn't, then ')'
            // is matched with the wrong open parenthesis.
            // If it is, then we have a match, and we can
            // remove the open parenthesis from the stack.
            else if(cur == ')') {
                if(stack.empty() || stack.top() != '(')
                    return false;
                else
                    stack.pop();
            }

            // Follow a similar process for '}'
            else if(cur == '}') {
                if(stack.empty() || stack.top() != '{')
                    return false;
                else
                    stack.pop();
            }

            // Follow a similar process for ']'
            else if(cur == ']') {
                if(stack.empty() || stack.top() != '[')
                    return false;
                else
                    stack.pop();
            }
        }
        
        // Finally, we must check if the stack is empty at the end.
        // It is wasn't then we would have extra open parenthesis
        // that aren't matched with any closing parenthesis.
        return stack.empty();
    }
};