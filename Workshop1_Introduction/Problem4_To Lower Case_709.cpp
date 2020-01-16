/*
    UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    To Lower Case
    Leetcode Problem 709
    https://leetcode.com/problems/to-lower-case/

 */

class Solution {
public:
    // Since the problem doesn't give any restrictions
    // on functions we can use, we can use the tolower
    // function to simplify the problem
    string toLowerCase(string str) {
        // Our strategy is to construct a string that is identical
        // to s, but every character is lowercase
        string result = "";

        for(int i = 0; i < str.size(); i++)
            // Add the lowercase character to the result
            result += tolower(str[i]);
            // Note: To use tolower, you need to include the
            // cctype library, which Leetcode already does for you

        return result;
    }
};