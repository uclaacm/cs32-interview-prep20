/*
    UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Two Sum
    Leetcode Problem 1
    https://leetcode.com/problems/two-sum/
*/

// Given an array of integers, return indices of the two numbers such that
// they add up to a specific target.
// You may assume that each input would have exactly one solution, and you
// may not use the same element twice.
class Solution {
public:
    // Our strategy is to map each value x to its index in the
    // vector. While we do this, we check if the map contains
    // the key y so that target = x + y
    vector<int> twoSum(vector<int>& nums, int target) {
        // In order to take advantage of the efficiency of
        // hashing, we will use an unordered map (implemented
        // by hash tables) over a map (implemented by trees)
        unordered_map<int, int> map;

        // We will store our solution indexes here
        vector<int> solutions;

        for(int i = 0; i < nums.size(); i++) {
            // Given value x, we are looking for y
            // such that t = x + y. In other words,
            // y = t - x
            int complement = target - nums[i];

            // Given a value, if we find the complement
            // in the map, then we find the two indexes
            // i and j such that nums[i] + nums[j] = target
            if(map.find(complement) != map.end()) {
                // Add the current index, as well as the
                // index of the complement value to the
                // solution. By our implementation, we
                // mapped the complement to its index.
                // Then, we return the solution
                solutions.push_back(i);
                solutions.push_back(map[complement]);
                return solutions;
            }

            // If we don't find the complement, then
            // we just map the current value to the
            // current index. A future value may be
            // the complement to this value.
            map[nums[i]] = i;
        }

        // We are guaranteed to find a solution, but C++ doesn't
        // know this. Therefore, we must return a vector<int>
        // at the end of the loop, even if this code never runs
        return solutions;
    }
};

// Time Complexity Analysis:
// We examine each value in nums at most once. If nums.size() = n, then we
// will do at most n examinations. Therefore, the time complexity is O(n).

// Space Complexity Analysis:
// We attempt to put each value in an unordered_map. If nums.size() = n,
// then in the worst case, we add all n elements into the unordered_map.
// Therefore, the space complexity is O(n).