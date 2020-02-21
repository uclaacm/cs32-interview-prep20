/*
    UCLA ACM ICPC: Interview Track Problem Solutions
    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only
    Leetcode 258 Add Digits
*/

class Solution {
public:
    int addDigits(int num) {
		//lets implement this recursively
        vector<int> total;
        if(num < 10)
        {
            return num; //if the num is less than 10, we good! also 
			//can serve as our base case if we need it to be
        }
        while(num > 0)
        {
            total.push_back(num%10); //get the individual digits of num
            num = num / 10; //dont forget to divide
        }
		//by now num = 0 in order to exit the while loop
        for(int i = 0; i < total.size(); i++)
        {
            num += total[i]; //let num = the digits we pushed back in the vector
        }
        return addDigits(num); //add recursively until the function returns
		//something smaller than 10.
    }
	//unfortunately, we all know that recursion is probably not our safest bet
	//if run time is important to us.
	//bad space complexity too because of all the additional copies of vector<int> total
	//that we have to keep track
	//but this is easy to implement.
	
};

//how about we skip the stack and just have an int keeping track of sum?
class Solution {
public:
    int addDigits(int num) {
        if(num<10) 
		{
			return num;
        }
		int sum = 0;
        while(num)
		{
            sum+=num%10;
            num/=10;
        }
        return addDigits(sum);
    }
	//so we get rid of the additional space needed! yes, that means that 
	//space complexity for this implementation is O(1).
	//time complexity would be n still.
	//bad news: theres a way of doing this in O(1) time and space complexity.
	
};


//onto the next solution

//i recommend reading this nice writeup by alokgupta 
//this has time complexity and space complexity of 1.
// I still don't really understand this solution but since you're reading this,
// I recommend going to : https://leetcode.com/problems/add-digits/discuss/501117/O(1)-time-and-space-complexity-floorcongruenceiterativerecursive-approach
//hopefully it blew your mind like it did with mine.

class Solution {
public:
    int addDigits(int num) {
        return 1 + (num-1)%9;
    }
};