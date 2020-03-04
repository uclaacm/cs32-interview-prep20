/*
    UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Intersection of Two Arrays
    Leetcode Problem 349
    https://leetcode.com/problems/intersection-of-two-arrays/
*/

// Given two arrays, write a function to compute their intersection.
// Note: Each element in the result must be unique. The result can be in any order.
class Solution {
public:
    // Our strategy is to add the values of nums1 to a set. Next, we
    // add the values of nums2 into a different set only if the value
    // appears in the first set. Then, we turn this new set into a vector.
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // In order to take advantage of the efficiency of
        // hashing, we will use an unordered set (implemented
        // by hash tables) over a set (implemented by trees)

        // Add the values of nums1 to set
        unordered_set<int> set;
        for(int i = 0; i < nums1.size(); i++)
            // Use the insert function to insert
            // values into the set
            set.insert(nums1[i]);

        // Add the values of nums2 into intersection
        // only if the value appears in set
        unordered_set<int> intersection;
        for(int i = 0; i < nums2.size(); i++) {
            // Note: The set.find(x) only returns
            // set.end() only if x isn't in the set
            if(set.find(nums2[i]) != set.end())
                intersection.insert(nums2[i]);
        }

        vector<int> result;
        // To iterate through an unordered_set, use an iterator
        for(auto i = intersection.begin(); i != intersection.end(); i++)
            result.push_back(*i);
        return result;
    }
};

// Time Complexity Analysis:
// We loop through nums1 all the way, and then loop through nums2 all the way.
// Then, we loop through the intersection of nums1 and nums2 all the way to turn
// the unordered_set into a vector. Suppose that nums1.size() = m and
// nums2.size() = n. We know that the intersection of nums1 and nums2 is at least
// min(m, n). Therefore, we can say that the time complexity of this algorithm
// is O(m + n).

// Space Complexity Analysis:
// Suppose that nums1.size() = m and nums2.size() = n. We have a unordered_set of
// at most size m to store the unique values of nums1. We construct an intersection
// using the unordered_set as a filter, so intersection must have a size of at
// most m as well. We also know that the vector result is the same size as
// the intersection. Therefore, we have that the space complexity of this
// algorithm is O(m).