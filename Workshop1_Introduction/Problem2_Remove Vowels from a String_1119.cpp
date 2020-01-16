/*
    UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Remove Vowels from a String
    Leetcode Problem 1119
    https://leetcode.com/problems/remove-vowels-from-a-string/
*/

class Solution {
public:
    string removeVowels(string s) {
        // Our strategy is to construct a string that is identical
        // to s, without including the vowels
        string result = "";

        for(int i = 0; i < s.size(); i++) {

            // Add the current character only if
            // it is not a vowel
            char cur = s[i];
            if(!isVowel(cur))
                result += s[i];
        }

        return result;
    }
private:
    // Checks if the value of c is a vowel
    bool isVowel(char c) {
        return c == 'a' ||
               c == 'e' ||
               c == 'i' || 
               c == 'o' || 
               c == 'u';
    }
};
