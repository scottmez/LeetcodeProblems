class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        /*
        You are given a string s and an array of strings words. All the strings of words are of the same length.

        A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.

        For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all 
        concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
        Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.
        
        */
        unsigned n = words.at(0).size();

        unordered_map<string, unsigned int> myMap; //maps words to indeces they can be found in s

        vector<int> result; //this is where we will store the output

        myMap.clear();
        for (const string& word : words) { //iterate through words (dont need index)
            myMap[word]++; //creates mapping from word to 1 if it doesnt exist, if it does then it increments it
        }

        for (unsigned int offset = 0; offset < n; ++offset) { // iterate over the n offsets
            //sliding window needs a size
            unsigned int size = 0;
            //sliding window memory
            unordered_map<string, unsigned int> seen;

            //iterate over the string with the step equals to n (size of words)
            for (unsigned int i = offset; i + n <= s.size(); i += n) {
                string sub = s.substr(i, n);

                // if the word is absent in the reference map
                // we clear the sliding window and move on
                auto itr = myMap.find(sub); //same as myMap.count(sub) == 0
                if (itr == myMap.end()) {
                    seen.clear();
                    size = 0;
                    continue;
                }

                //increase the number of the occurrences of the word seen in the map
                ++seen[sub];
                ++size;

                while (seen[sub] > itr->second) {
                    // if the occurrences amount exceeds the reference amount,
                    // we shrink the window from the left until the window is valid again.

                    // A word at the beginning of the current sliding window.
                    string first = s.substr(i - (size - 1) * n, n);

                    //Remove the occurrence from the window,
                    // shrinking it from the left
                    --seen[first];
                    --size;
                }

            //if we used all words from the array, 
            // we have found the correct spot 
            // and we need to calculate the beginning
            // index of the current sliding window

            if (size == words.size()) {
                result.push_back(i - (size - 1) * n);
            }
            }
        }

        return result;
    }
};