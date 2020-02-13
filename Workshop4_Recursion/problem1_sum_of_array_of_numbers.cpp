/*
    UCLA ACM ICPC: Interview Track Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Sum of Array of Numbers
*/

// A vector is an STL data structure
// that is basically like an array,
// but you have access to the size()
// function!

// Given a vector of integers, use recursion to return the sum of
// the integers in the vector.
class Solution {
public:
    // To simplify the problem, we will create a helper function that
    // returns the sum of a vector starting at a given index.
    int sumOfArrayHelper(vector<int> nums, int index) {
        // Our base case is when the given index is out of bounds, in which
        // we return 0. We are assuming that the index will go out of bounds
        // in the positive direction.
        if(index >= nums.size()) {
            return 0;
        }

        // Now, assume that our function works when you are given a higher
        // index. In other words, assume we already know the answer to
        // sumOfArrayHelper(nums, index + 1). In order to calculate
        // sumOfArrayHelper(nums, index), all we need is add nums[index]
        // to sumOfArrayHelper(nums, index + 1).        
        else {
            return nums[index] + sumOfArrayHelper(nums, index + 1);
        }
    }

    // Now, all we need to do is to call sumOfArrayHelper with index 0
    // to get our answer.
	int sumOfArray(vector<int> nums) {
		return sumOfArrayHelper(nums, 0);
    }
};
