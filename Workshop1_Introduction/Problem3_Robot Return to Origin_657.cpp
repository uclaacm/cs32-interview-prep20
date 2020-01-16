/*
    UCLA ACM ICPC: Interview Track Leetcode Problem Solutions

    Disclaimer: This is not the only valid solution and we do not claim our solutions 
    to be optimal in terms of runtime or memory usage, we are merely giving example 
    solutions to questions for learning purposes only

    Remove Robot Return to Origin
    Leetcode Problem 657
    https://leetcode.com/problems/robot-return-to-origin/
*/

class Solution {
public:
    bool judgeCircle(string moves) {

        // Our strategy is to keep track of our x and y
        // coordinates. We will start at (0, 0)
        int x = 0;
        int y = 0;

        // Iterating through the moves string so that
        // we compute each move one at a time
        for(int i = 0; i < moves.size(); i++) {
            
            char cur = moves[i];

            // 'L': Decrement x
            if(cur == 'L')
                x--;
            // 'R': Increment x
            else if(cur =='R')
                x++;
            // 'U': Increment y
            else if(cur == 'U')
                y++;
            // 'D': Decrement y
            else if(cur == 'D')
                y--;
        }

        // Return true if we are back at (0, 0)
        return x == 0 && y == 0;

        // Note: Our choice x and y is arbitrary. As long
        // as you keep 'L' as the opposite of 'R', and 'U'
        // as the opposite of 'D', any choice of starting
        // position and increment/decrement number would work
        // as long as you are consistent.
    }
};