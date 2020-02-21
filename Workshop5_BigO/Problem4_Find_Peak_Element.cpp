/*
    UCLA ACM ICPC: Interview Track Problem Solutions
    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only
    Leetcode 162: Find Peak Element 
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) //we dont need to check if there is only one element
		//in the vector
        {
            return 0; //return index 0.
        }
        for (auto it = nums.begin();  it != nums.end()-1; it++) //end the index before
		//because we are comparing to the index right after and will
		//go out of bound if we dont.
        {
            if(*it > *(it+1)) //if current is greater, it is a peak, return first peak
            {
                return it - nums.begin(); //this will return an int instead of the iterator
            }
        }
        return nums.size()-1; //if we break out the loop, then that means that,the last
		//thing is the greatest.
    }
	//space complexity is constant time because we are not creating any 
	//run time is O(N) because its possible that we dont reach the peak until
	//the very end of the vector
};

//the previous solution had a time complexity of O(N), but we can do even better.

class Solution {
public:
	int findPeakElement(vector<int>& nums){
        if(nums.size() == 1)
        {
            return 0;
        }
        int start = 0;
        int end = nums.size() - 1;
        while(start < end){
            int mid = start + (end-start) / 2; //split down the half and break it into
			//smaller sub arrays traversing.
            if(mid == start) //if our middle is the start, then we have 
			//exhausted all options, and will break out and return start
                break;
            if(nums[mid] > nums[mid-1]) //if nums[mid] is greater than the next index,
			//then it is a possibility that it is a local maximum.
            {
                start = mid; //set the next start iteration to the current middle
            }
            else
            {
                end = mid; //set the next end iteration to the current middle,
				//we no longer check the later half of the array.
            }
        }
        return start; //if we break out, then the first element is the greatest.
    }
	//Time complexity is log(n) average case, worst case would be the list is sorted in 
	//descending order, can you guess what the time complexity for worst case is?
};