class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        /*
        have a running sum 

        words.at(i).size()
        */
        vector<string> fullJust;
        fullJust.push_back(words.at(0));
        int curWidth = words.at(0).size();
        fullJust.back().resize(maxWidth, ' ');
        int curPos = curWidth;
        int firstWordInLine = 1;
        int curWords = 1; // we will always assume that each line contains at least one word because of the guarantee that each word's length will be less than maxWidth
        for(int i = 1; i < words.size(); i++) {
            if (curWidth + 1 + words.at(i).size() <= maxWidth) { //+ 1 for the space
                curWidth += 1 + words.at(i).size(); //needs to be at least one space separating words
                curWords += 1;
            }
            else { //adding the word would cause overflow!!!, so add to next line instead
                //calculate how many spaces need to be added between words

                int numGaps = curWords - 1; //2
                int numSpaces = (maxWidth - curWidth) + numGaps; // 16 - 10 + 2 = 8
                int spacesPerGap = 0;
                int rem = 0;
                if (numGaps > 0) { //to avoid potential division by zero
                    spacesPerGap = (numSpaces/numGaps);  //8/2 = 4
                    rem = numSpaces % numGaps; // 8 % 2 = 0
                } 
                int add = 0;
                
                for (int j = 0; j < numGaps; j++) {
                    if (rem > 0) {
                        add = 1;
                    }   
                    fullJust.back().replace(curPos + spacesPerGap + add, words.at(firstWordInLine + j).size(), words.at(firstWordInLine + j)); //4 + 4 + 0 = 8
                    curPos = curPos + spacesPerGap + add + words.at(firstWordInLine + j).size(); // 4 + 4 + 0 only 8?, should include the new word, so add it + 2 = 10
                    add = 0;
                    rem--;
                }

                fullJust.push_back(words.at(i));
                curPos = words.at(i).size();
                curWidth = curPos;
                curWords = 1;
                firstWordInLine = i + 1;
                fullJust.back().resize(maxWidth, ' ');
            }
        }
        //now we need to check if there are any words we need to add to the last line
        for (int i = firstWordInLine; i < words.size(); i++) {
            fullJust.back().replace(curPos + 1, words.at(i).size(), words.at(i));
            curPos = curPos + 1 + words.at(i).size();
        }

        return fullJust;
    }
};
//currently getting out of bounds array access error, I take break now zzz
