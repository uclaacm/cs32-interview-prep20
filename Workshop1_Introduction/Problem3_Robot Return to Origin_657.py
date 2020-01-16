# UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

# Disclaimer: This is not the only valid solution and we do not claim our solutions 
# to be optimal in terms of runtime or memory usage, we are merely giving example 
# solutions to questions for learning purposes only

# Remove Robot Return to Origin
# Leetcode Problem 657
# https://leetcode.com/problems/robot-return-to-origin/

class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        
        # our strategy is to perform the moves on x and y coordinates
        # then check at the end if these x and y coordinates went back
        # to their starting poitn of (0,0)

        x = 0
        y = 0
        
        # traverse through every character (current move) in moves
        for curMove in moves:

            # left moves are indicated by a decrease in the x-coordinate 
            if curMove == "L":
                x -= 1

            # right moves are indicated by an increase in the x-coordinate 
            elif curMove == "R":
                x += 1
            
            # up moves are indicated by an increase in the y-coordinate 
            elif curMove == "U":
                y += 1

            # down moves are indicated by a decrease in the y-coordinate
            elif curMove == "D":
                y -= 1
        
        # return true if the robots position after all of the moves is still (0,0)
        return x == 0 and y == 0