class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int, int> fruitIndices; // map to store the last index of each fruit
        int lru = fruits[0]; //least recently used fruit (second most recent)
        int i = 1;
        while (i < fruits.size() && fruits[i] == lru) {
            i++; // skip all the same fruits at the start
        }
        if (i == fruits.size()) {
            return i; // if all fruits are the same, return the size of the array
        }
        int mru = fruits[i]; // most recently used fruit (most recent)
        int left = 0; // left pointer of the sliding window
        int right = i; // right pointer of the sliding window
        int max = 2; // at least two fruits in the basket
        fruitIndices[lru] = i-1; // store the index of the least recently used fruit
        fruitIndices[mru] = i; // store the index of the most recently used fruit
        while (right < fruits.size()) {
            if (fruits[right] == lru) {
                lru = mru; // update least recently used fruit
                mru = fruits[right]; // update most recently used fruit
                fruitIndices[mru] = right; // store the index of the most recently used fruit
            }
            else if (fruits[right] != mru) {
                max = std::max(max, right - left); // update max size of the basket
                lru = mru; // update least recently used fruit
                mru = fruits[right]; // update most recently used fruit
                left = fruitIndices[lru]; // move left pointer to the next index after the last occurrence of lru
                fruitIndices[mru] = right;
            }
            right++; // move the right pointer to the next fruit
            //cout << "Left: " << left << ", Right: " << right << ", lru: " << lru << ", mru:" << mru << std::endl; // debug output
        }
        return std::max(max, right - left); // return the maximum size of the basket found
    }
};