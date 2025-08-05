class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unplaced = fruits.size();
        list<int> baskets_list(baskets.begin(), baskets.end());
        for (int fruit : fruits) {
            for (auto it = baskets_list.begin(); it != baskets_list.end(); ++it) {
                if (fruit <= *it) {
                    baskets_list.erase(it);
                    unplaced--;
                    break;
                }
            }
        }
        return unplaced;
    }
};