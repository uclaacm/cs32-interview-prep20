/*
    UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Remove Outermost Parentheses
    Leetcode Problem 1021
    https://leetcode.com/problems/remove-outermost-parentheses/
*/

class Solution {
public:
    // Surprise! This solution actually doesn't require a
    // stack or a queue! However, it uses stack-like ideas,
    // so it's fair game as a stack/queue problem!

    // The strategy is to keep a counter when looping through the
    // string. Every time we see '(', we increment the counter.
    // Every time we see ')', we decrement the counter. This
    // is analogous to pushing into a stack whenever we see '(',
    // and popping the stack whenever we see ')'.

    // However, there are two special cases. If we see '(' and
    // our count is 0 (a.k.a the stack is empty), this is an
    // outer '(' and won't be included in the output. If we
    // see ')' and our count is 1 (a.k.a the stack has one
    // element), this is an outer ')' and also won't be
    // included in the output. These are special cases because
    // these operations either start with a count of 0, or end
    // with a count of 0.

    string removeOuterParentheses(string S) {
        int count = 0;
        string result = "";
        for(int i = 0; i < S.size(); i++) {

            // Case 1: We see '(' and our count is 0.
            // This is an outer parenthesis and won't
            // go into our solution. Note that since
            // we're guaranteed to be given a valid
            // string, every time the count if 0,
            // we're guaranteed that S[i] == '('.
            if(count == 0) {
                count++;
            }

            // Case 2: We see ')' and our count is 1.
            // This is an outer parenthesis and won't
            // go into our solution.
            else if(count == 1 && S[i] == ')') {
                count--;
            }

            // Case 3: We see '(' and our count isn't 0.
            // This is an inner parenthesis and will
            // go into our solution.
            else if(S[i] == '(') {
                count++;
                result += S[i];
            }

            // Case 4: We see ')' and our count isn't 1.
            // This is an inner parenthesis and will
            // go into our solution.
            else /* S[i] == ')' */ {
                count--;
                result += S[i];
            }
        }
        return result;
    }

    // Here is the stack solution. It's not as efficient as
    // the previous solution, but it's a good exercise to
    // compare this algorithm with our solution.

    string alsoRemoveOuterParentheses(string S) {
        stack<char> st;
        string result = "";
        for(int i = 0; i < S.size(); i++) {
            if(st.empty()) {
                st.push('(');
            }
            else if(st.size() == 1 && S[i] == ')') {
                st.pop();
            }
            else if(S[i] == '(') {
                st.push('(');
                result += S[i];
            }
            else {
                st.pop();
                result += S[i];
            }
        }
        return result;
    }

};