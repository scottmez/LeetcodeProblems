class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        // Use a set to keep track of unique bitwise ORs
        unordered_set<int> resultSet;
        unordered_set<int> prevSet;
        unordered_set<int> currentSet;

        int currentOR = 0;
        for (int num : arr) {
            //Prepare the current set for the new number
            currentSet.clear();

            // Add the current number to the current set
            currentSet.insert(num);

            // Update the current set with the new ORs
            for (int prevOR : prevSet) {
                int newOR = prevOR | num;
                currentSet.insert(newOR);
            }
            // Add the current ORs to the result set
            resultSet.insert(currentSet.begin(), currentSet.end());

            // Update the previous set for the next iteration
            prevSet = currentSet;
        }

        return resultSet.size();
    }
};