class Solution {
public:
    bool isPalindrome(string s) {
        //first filter out all non-alphanumeric characters
        string sf = ""; //s but filtered :O
        for (int i = 0; i < s.size(); i++) {
            if (isalnum(s.at(i))) {
                sf.push_back(tolower(s.at(i))); //run it through tolower() so all letters are lowercase
            }
        }

        //now we just check if its a palindrome
        int leftIndex = 0;
        int rightIndex = sf.size() - 1;
        while (leftIndex <= rightIndex) {
            if (sf.at(leftIndex) != sf.at(rightIndex)) { //does it violate the trait of a palindrome
                return false;
            }
            leftIndex++;
            rightIndex--;
        }
        //we checked everything, its a palindrome!
        return true;
    }
};