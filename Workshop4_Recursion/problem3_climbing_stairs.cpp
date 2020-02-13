/*
    UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Climbing Stairs
    Leetcode Problem 70
    https://leetcode.com/problems/climbing-stairs/
*/

// Suppose you are climbing a set of stairs that has n steps.
// Every step you take, you can climb up either one step or two steps.
// Return the number of distinct ways you can climb up the stairs.
class Solution {
public:
    // We will use simple recursion to solve this problem.
    int climbStairs(int n) {
        // If there is only one step, trivially, we can only climb up
        // the step by taking one step.
        if(n == 1) {
            return 1;
        }

        // If there are only two steps, trivially, we can only climb up
        // the step by taking one step + one step, or by taking 2 steps.
        else if(n == 2) {
            return 2;
        }
        
        // Now suppose we have a set of N steps. We have two choices:
        // Climb 1 step, or climb 2 steps. If we climb 1, then we
        // still have N-1 steps to go. If we climb 2, then we still
        // have N-2 steps to go. If we assume we already know how to
        // calculate climbStairs(N-1) and climbStairs(N-2), then we
        // are done.
        else {
            return climbStairs(n - 1) + climbStairs(n - 2);
        }
    }
};