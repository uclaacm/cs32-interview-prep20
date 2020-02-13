/*
    UCLA ACM ICPC: Interview Track Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Group Integers
*/

// A vector is an STL data structure
// that is basically like an array,
// but you have access to the size()
// function!

// Given a vector of integers, return whether is it possible to
// choose a group of some of the integers such that the group sums
// to the given target
class Solution {
public:
    // To simplify the problem, we will create a helper function that
    // returns whether it is possible to choose a group of some of the
    // integers at or after a given index such that the group sums to
    // the given target.
    bool groupSumHelper(vector<int> nums, int target, int index) {
        // If target == 0, we can choose no elements, which by default
        // sums up to 0.
        if(target == 0) {
            return true;
        }

        // when the given index is out of bounds, we can't choose any
        // elements that add up to target (since target != 0), so we
        // return false. We are assuming that the index will go out
        // of bounds in the positive direction.
        else if(index >= nums.size()) {
            return false;
        }

        // If the nums[index] (the first element starting at index) equals
        // the target, then we can choose just nums[index] to sum up to the
        // target. Therefore, we return true.
        else if(nums[index] == target) {
            return true;
        }

        // In all other cases, we have to check the rest of the vector.
        // We have two choices.
        else {
            return

            // If nums[index] is in the group that sums
            // up to the target, we have to check if there is a group in the
            // rest of the vector that sums up to target - nums[index].
            groupSumHelper(nums, target - nums[index], index + 1) ||

            // If nums[index] is not in the group, then we just check if there
            // if a group in the rest of the vector that sums up to target. 
            groupSumHelper(nums, target, index + 1);
        }
    }

    // Now, all we need to do is to call groupSumHelper with index 0
    // to get our answer.
    bool groupSum(vector<int> nums, int target) {
        return groupSumHelper(nums, target, 0);
    }
};