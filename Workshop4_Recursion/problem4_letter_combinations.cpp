/*
    UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Letter Combinations of a Phone Number
    Leetcode Problem 17
    https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/

// A vector is an STL data structure
// that is basically like an array,
// but you have access to the size()
// function! Also, push_back(x) acts
// like push(x) of a stack.

// We will use simple recursion to solve this problem.
class Solution {
private:
    // We will define a helper function that takes in
    // a character and returns the vector of the letters
    // the character can map to.
    vector<string> map(char digit) {
        switch(digit) {
            case '2': return {"a", "b", "c"};
            case '3': return {"d", "e", "f"};
            case '4': return {"g", "h", "i"};
            case '5': return {"j", "k", "l"};
            case '6': return {"m", "n", "o"};
            case '7': return {"p", "q", "r", "s"};
            case '8': return {"t", "u", "v"};
            case '9': return {"w", "x", "y", "z"};
            default: return {};
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        // If we are given no digits, then we can't make and letter
        // combinations. Therefore, we return the empty vector.
        if(digits.size() == 0) {
            return {};
        }

        // If we are given only one digit, then we simply return
        // a vector of all the letters that digit maps to.
        else if(digits.size() == 1) {
            return map(digits[0]);
        }

        // Assume that we are passed a string of length N, but we can
        // compute letterCombinations for a string of length N-1.
        // We can compute letterCombinations for a string of length N
        // by getting a vector of letters the first character can map
        // to, and then adding that to the letterCombinations of the 
        // rest of the characters.
        else {
            // We will construct our vector inside the variable result.
            vector<string> result;

            // heads represent the vector of letters the first character
            // can map to.
            vector<string> heads = map(digits[0]);

            // tails represents letterCombinations on the rest of the characters
            // Note that digits.substr(1, digits.size() - 1) returns digits without
            // the first character.
            vector<string> tails = letterCombinations(digits.substr(1, digits.size() - 1));

            // We will use a nested for-loop to construct our result.
            // This is because we want to add every letter in heads
            // to the beginning of each letter combination in tails.
            for(int i = 0; i < heads.size(); i++) {
                for(int j = 0; j < tails.size(); j++) {
                    result.push_back(heads[i] + tails[j]);
                }
            }

            return result;
        }
    }
};