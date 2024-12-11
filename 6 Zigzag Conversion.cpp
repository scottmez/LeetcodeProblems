class Solution {
public:
    string convert(string s, int numRows) {
        /*
        numRows = 1, 1 aprt | s[0], s[1]
        2, 2 | s[0], s[2]
        3, 4 | s[4]
        4, 6 | s[6]
        5, 8 | s[8]
        6, 10
        formula for how far apart letters are on the top row:
        (numRows *2) - 2
        
        for not top or bottom, i.e. middle rows the pattern will be different
        for "true" middle it will always be the same distance apart, which is exactly half of the top/bottom row formula
        3, 2
        4, N/A (no "true") middle
        5, 4 

        for "false" middle it will alternate between two values apart
        notice that if you sum the alternating values you get the top row distances
        4, 4or2  
        5, 6or2
        6, 8or2 or 6or4
         
        */
        if (numRows == 1) {
            return s;
        }
        string newS = "";
        int k = (numRows * 2) - 2; //amount to change increment by 
        for (int i = 0; i < numRows; i++) { //down
            int j = i; //increment this one
            int row = i; //keep this one
            int div = 2; // default to middle row
            int offset = 0;
            //first figure out if i is a top/bottom row
            if (row == 0 || row == (numRows - 1)) {
                div = 1; 
            }
            //then find out if i is a "false" middle
            else{
                offset = (numRows - 1) - (2 * row);
            }
            while (j < s.size()) {
                newS.push_back(s.at(j));

                j += (k / div) + offset; // replace with formula here
                offset *= -1;
            }
        }
        return newS;
    }
};