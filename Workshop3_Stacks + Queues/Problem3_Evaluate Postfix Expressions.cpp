/*
    UCLA ACM ICPC: Interview Track Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Evaluate Postfix Expressions
*/

// Return the value of the postfix expression. Assume
// that the only characters that can appear in the C-string are
// '0', '1', ..., '8', '9', '+', '-', '*', and '/',
// and assume that the given postfix expression is valid.
class Solution {
public:

    // Did you pay attention in lecture to the evaluating postfix
    // expressions algorithm? If yes, good for you! Skip the explanation
    // to the implementation. If not, it's your lucky day!

    // In postfix notation, the operator comes AFTER the operands, so
    // instead of a + b, we have a b +. Computers like postfix notation
    // because all postfix expressions can be expressed without parenthesis,
    // and the algorithm for evaluating postfix is relatively simple!

    // Traverse the tokens (either an operand or an operator) from left to
    // right. If it's an operand, push it into your stack. If it's an operator,
    // pop two operands from your stack, apply the operator on those
    // two operands, and then push the result onto the stack. At the end of
    // the traveral, there will be one value in the stack, and that value is
    // your answer!

    // Here is an example run of the algorithm:

    // 3 2 + 6 *
    // 3: Push onto stack: [3]
    // 2: Push onto stack: [3, 2]
    // +:
        // Pop off 3 and 2: []
        // Apply 3 + 2: 5
        // Push result onto stack: [5]
    // 6: Push onto stack: [5, 6]
    // *:
        // Pop off 5 and 6: []
        // Apply 5 * 6: 30
        // Push result onto stack: [30]
    // We are done, and our result is 30

    int evaluatePostfix(char[] exp) {  

        stack<int> st;
    
        // Scan all characters one by one 
        // Recall: C-strings end with '\0' 
        for (int i = 0; exp[i] != '\0'; i++) {

            // If the scanned character is an operand, push it to the stack.
            // Recall: If a char is '0', '1', ..., '8', '9', then you can get
            // its integer value by doing char - '0'
            if (exp[i] - '0' >= 0 && exp[i] - '0' <= 9)
                st.push(exp[i] - '0'); 
    
            // If the scanned character is an operator, pop two  
            // elements from stack and apply the operator
            else {

                // Pop two operands from your stack
                int val1 = st.top(); st.pop();
                int val2 = st.top(); st.pop();

                // Apply the operator on those two operands,
                // and then push the result onto the stack
                switch (exp[i]) {  
                    case '+': st.push(val2 + val1); break;  
                    case '-': st.push(val2 - val1); break;  
                    case '*': st.push(val2 * val1); break;  
                    case '/': st.push(val2 / val1); break;  
                }
                // Note: Order matters! The second value you
                // pop off the stack should be on the left-
                // hand side of the operator, and the first
                // value should be on the right-hand side
            }
        }

        // We are done, and our result is
        // the one value in the stack
        return st.top();
    }

}