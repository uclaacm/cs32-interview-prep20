/*
    UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Backspace String Compare
    Leetcode Problem 844
    https://leetcode.com/problems/backspace-string-compare/
*/

class Solution {
public:
    // The strategy to solving this problem is to use a character stack.
    // Whenever you come across a '#', you pop a character off the stack,
    // if possible. When you do this for all characters in a string, the
    // stack contains the characters of the final typed string.
    bool backspaceCompare(string S, string T) {

        // Initialize a stack for S
        // and a stack for T
        stack<char> stackS;
        stack<char> stackT;

        // For each character in S, if you come across a #, you pop
        // from the stack if it isn't empty. Otherwise, you add the
        // character to the stack.
        for(int i = 0; i < S.size(); i++) {
            if(S[i] != '#')
                stackS.push(S[i]);
            else if(!stackS.empty())
                stackS.pop();
        }

        // Follow the same progress for T
        for(int i = 0; i < T.size(); i++) {
            if(T[i] != '#')
                stackT.push(T[i]);
            else if(!stackT.empty())
                stackT.pop();
        }

        // At this point, the characters in each stack represents
        // the final typed string of each string. To simplify the
        // rest of the algorithm, we will check if the stacks are
        // the same size. If they aren't, then the final typed
        // strings can't be equal.
        if(stackS.size() != stackT.size())
            return false;

        // When the algorithm reaches here, we know the stacks are
        // the same size, so now all we have to do is to compare
        // the contents of the stack. We can do this by continuing
        // to take the top of the stack, and comparing those characters
        // We continue to do this when both stacks become empty, which
        // will happen at the same time.
        while(!stackS.empty()) {
            char curS = stackS.top();
            char curT = stackT.top();
            if(curS != curT)
                return false;
            stackS.pop();
            stackT.pop();
        }

        return true;
    }
};