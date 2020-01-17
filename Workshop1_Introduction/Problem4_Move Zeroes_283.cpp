/*
    UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    To Lower Case
    Leetcode Problem 283
    https://leetcode.com/problems/move-zeroes/

 */

class Solution {
public:
    // Our general strategy will be to put all non-zero
    // values at the front of the vector, and then
    // put 0's in for the rest of the spaces
    void moveZeroes(vector<int>& nums) {
        // This value keeps track of the vector index
        // that we want to put our next non-zero value
        int index = 0;

        for(int i = 0; i < nums.size(); i++) {
            // When we encounter a non-zero value, we
            // will place it at nums[index], and then
            // increment index, because nums[index+1] is
            // the place we want to put our next
            // non-zero number
            if(nums[i] != 0)
                nums[index++] = nums[i];
                // Note: This is just shorthand for
                // nums[index] = nums[i]; index++;
        }

        // We have already gone though the entire vector
        // and placed all non-zero values where they should
        // be. Now, we just have to make sure that the values
        // at nums[index] and onwards are all 0
        for(int i = index; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};