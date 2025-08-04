class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int lru_i = 0; // index of least recently used fruit
        int lru = fruits[0]; //least recently used fruit (second most recent)
        int right = 1;
        while (right < fruits.size() && fruits[right] == lru) {
            right++; // skip all the same fruits at the start
        }
        if (right == fruits.size()) {
            return right; // if all fruits are the same, return the size of the array
        }
        int mru = fruits[right]; // most recently used fruit (most recent)
        int mru_i = right; // index of most recently used fruit
        int left = 0; // left pointer of the sliding window
        int max = 2; // at least two fruits in the basket
        while (right < fruits.size()) {
            if (fruits[right] == lru) {
                lru = mru; // update least recently used fruit
                lru_i = mru_i; // update index of least recently used fruit
                mru = fruits[right]; // update most recently used fruit
                mru_i = right; // update index of most recently used fruit
            }
            else if (fruits[right] != mru) {
                max = std::max(max, right - left); // update max size of the basket
                lru = mru; // update least recently used fruit
                lru_i = mru_i; // update index of least recently used fruit
                mru = fruits[right]; // update most recently used fruit
                mru_i = right; // update index of most recently used fruit
                left = lru_i; // move the left pointer to the index of least recently used fruit
            }
            right++; // move the right pointer to the next fruit
            //cout << "Left: " << left << ", Right: " << right << ", lru: " << lru << ", mru:" << mru << std::endl; // debug output
        }
        return std::max(max, right - left); // return the maximum size of the basket found
    }
};