"""
    UCLA ACM ICPC: Interview Track Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Evaluate Postfix Expressions
    Geeks4Geeks: https://www.geeksforgeeks.org/stack-set-4-evaluation-postfix-expression/
    Solution also based off of Geeks4Geeks Solution

"""

# The main function that converts given infix expression 
# to postfix expression 
def evaluatePostfix(exp): 

    # Initialize the empty stack
    numStack = []    
    
    # Iterate over the expression for conversion 
    for i in exp: 
            
        # If the scanned character is an operand 
        # (number here) push it to the stack 
        if i.isdigit(): 
            numStack.append(int(i)) 

        # If the scanned character is an operator, 
        # pop two elements from stack and apply it. 
        else: 
            val1 = numStack.pop()
            val2 = numStack.pop()
            if i == '+': numStack.append(val2 + val1)
            elif i == '-': numStack.append(val2 - val1)
            elif i == '*': numStack.append(val2 * val1)
            elif i == '/': numStack.append(val2 / val1)
            
            # These evaluations can also be handled using
            # the Python eval function
            # numStack.append(str(eval(val2 + i + val1))) 

    return numStack.pop() 