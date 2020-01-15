# UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

# Disclaimer: This is not the only valid solution and we do not claim our solutions 
# to be optimal in terms of runtime or memory usage, we are merely giving example 
# solutions to questions for learning purposes only

# Fizz Buzz
# Leetcode Problem 412
# https://leetcode.com/problems/fizz-buzz/

class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        # initialize an empty array to store the output we wish to return
        ret = []
        
        # we want our values outputted to start at 1 and go up to n
        # Python range(x,y) values include x, and go up to (but don't include) y
        for i in range(1, n + 1):
        
        # Note: we know mathematically that if a % b == 0, then a is divisible by b

            # if our current value i is divisible by both 3 and 5, add "FizzBuzz" to the output
            if i % 3 == 0 and i % 5 == 0:
                ret.append("FizzBuzz")
            
            # otherwise, if our current value i is divisible by 3, add "Fizz" to the output
            elif i % 3 == 0:
                ret.append("Fizz")
            
            # otherwise, if our current value i is divisible by 5, add "Buzz" to the output
            elif i % 5 == 0:
                ret.append("Buzz")
            
            # at this point we know i is not divisible by 3, 5, or both, so we add the integer (as a string) to the output
            else:
                ret.append(str(i))
        
        # return our array of outputs
        return ret