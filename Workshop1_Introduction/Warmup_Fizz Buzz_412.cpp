/*
    UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Fizz Buzz
    Leetcode Problem 412
    https://leetcode.com/problems/fizz-buzz/
*/

class Solution {
public:
    // Note: Vectors represent arrays that can change in size.
    // To use vectors, you need to include the vector library,
    // which Leetcode already does for you
    vector<string> fizzBuzz(int n) {
        // Initialize an empty vector to store the output we wish to return
        vector<string> result;

        // We want our vector to represent numbers from 1 to n (inclusive)
        for(int i = 1; i <= n; i++) {
            // Note: We know that if a % b == 0, then a is divisible by b

            // If our current value i is divisible by both 3 and 5,
                // Add "FizzBuzz" to the vector
            if(i % 3 == 0 && i % 5 == 0)
                // Note: vector::push_back("FizzBuzz") adds a new element
                // at the end of the vector, after its current last element.
                // "FizzBuzz" is copied (or moved) to the new element
                result.push_back("FizzBuzz");

            // Otherwise, if our current value i is divisible by 3,
                // Add "Fizz" to the output
            else if(i % 3 == 0)
                result.push_back("Fizz");

            // Otherwise, if our current value i is divisible by 5,
                // Add "Buzz" to the output
            else if(i % 5 == 0)
                result.push_back("Buzz");

            // At this point we know i is not divisible by 3, 5, or both,
                // So we add the integer (as a string) to the output
            else
                // to_string(i) returns a string with the representation of i
                // Note: To use it, you need to include the string library,
                // which Leetcode already does for you
                result.push_back(to_string(i));
        }
        return result;
    }
};
