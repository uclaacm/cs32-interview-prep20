/*
    UCLA ACM ICPC: Interview Track Problem Solutions
    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only
    242 Valid Anagram 
*/

//bad solution, didn't even realize as this was the first solution that popped up
//in my head.
class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
	if (s.empty() && t.empty()) //check if either of them are empty
	{
		return true;
	}
	if(s.empty() || t.empty()) 
	{
		return false;
	}
	if (s.length() != t.length()) //dont even have to check if we dont have the same length
	{
		return false;
	}
	std::unordered_multiset<char> ums1;
	for (int i = 0; i < s.length(); i++) 
	{
		ums1.insert(s[i]); //insert into the hash map 
	}
	for (int i = 0; i < t.length(); i++)
	{
		char val = t[i];
		if (ums1.end() == ums1.find(val))
		{
			return false; //if we cant find the character in the hashmap
			//then it is not an anagram
		}
		ums1.erase(ums1.find(val)); //remove the character for the next iteration
	}
	return true; // if we exit and havent returned false, then the two string are 
	//anagrams of each other
}
};

class Solution {
public:
	bool isAnagram(std::string s,std::string t)
	{
		//stl has a built in function that will sort this string for you
		//do you know which sorting algorithm stl sort() uses? brownie points
		//for you if you do :)
		sort(s.begin(),s.end());
		sort(t.begin(),t.end());
		return s == t;
		//this is good, but I think we can do even better.
	}
};

class Solution {
public:
	bool isAnagram(std::string s,std::string t)
	{
		//since we know there is only lowercase letters in the anagram, 
		//we can initialize 2 vectors of size 26 and keep track of the count
		//and then compare if theyre the same after
		if(s.length() != t.length())
		{
			return false;
		}
		vector<int> s_count(26,0), t_count(26,0); //the () inside means to initialize
		//in our case we are initializing a vector of size 26 to 0s.
		
		int s_length = s.length(); //define outside so the for loop wont continously
		//call the length function
		for(int i = 0; i < s_length; i++)
		{
			s_count[s[i] - 'a']++; //increment the count for that particular bin
			t_count[t[i] - 'a']++; //ditto
		}
		return s_count == t_count; //if they end up the same, return true.
	}
};


