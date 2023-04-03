class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        std::sort (people.begin(), people.end());
        int n = people.size();
        int weight;
        size_t forward_counter = 0;
        for (size_t i = 0; i < (n-forward_counter); i++) {
            if (n-1-i == forward_counter) continue;
            weight = people[n-1-i];
            if ((weight+people[forward_counter]) <= limit) 
                forward_counter++;
        }
        int boats = n - forward_counter;
        return boats;
    }
};