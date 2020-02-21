/*
    UCLA ACM ICPC: Interview Track Problem Solutions
    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only
    268 Missing Number 
*/

class Solution {
public:
int missingNumber(vector<int>& nums) {
		//this has good run time, but horrible space complexity, can you think why?
        int size = nums.size() + 1;
        vector<int> complete(size,0);
        for(int i = 0; i < size; i++) //we are making an additional array that will 
		//contain the missing number
        {
            complete[i] = i;
        }
		//we will sum up both arrays, complete will always have the bigger sum,
		//subtract nums from complete and we will get our missing number.
        return accumulate(complete.begin(),complete.end(),0)- accumulate(nums.begin(),nums.end(),0);
    } //this implementation did not hold constant space complexity as it will always 
	//have to create an additionaly O(N) cost array to compare.
};

//I think we can do better though!

//I saw this on leetcode and I thought it was super neat,
//the XOR method, if you dont know what XOR is, I would read up on bitwise operations
//in short, every number in your computer has a bit representation
//XOR means that it will only output 1 if the two inputs are 0 and 1. so 0 and 0, 1 and 1
//will not output 1.


class Solution {
public:
int missingNumber(vector<int>& nums){
	int size = nums.size();
	int missing = nums.size(); //if we initialize missing to n, then everything that
	//gets XORed will either be 0(as missing will be comparing with the number itself)
	//or the number that we are missing!
	for(int i = 0; i < size; i++)
	{
		missing ^= i;
		missing ^= nums[i];
	}
	return missing;
	//this implementation is fast(bitwise operators are very fast)
	//and always has constant space complexity as we are not implementing more variables
	//for an increasing n.
}
};