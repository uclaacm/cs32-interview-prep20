/*
    UCLA ACM ICPC: Interview Track Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Factorial
*/

// Given a non-negative integer n, return n!
// Note: n! = n * (n - 1) * (n - 2) * ... * 2 * 1;
// A special case if that 0! = 1
class Solution {
public:
    // We will use simple recursion to solve this problem.
    int factorial(int n) {
        // If n == 0 or n == 1, trivially, we return 1
        if(n == 0 || n == 1) {
            return 1;
        }
        
        // The factorial has a recursive definition.
        // Note that (n - 1)! = (n - 1) * (n - 2) * ... * 2 * 1.
        // We can then say that n! = n * (n - 1) * (n - 2) * ... * 2 * 1
        // = n * (n - 1)!
        else {
            return n * factorial(n - 1);
        }
    }
};