class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        std::sort(satisfaction.begin(),satisfaction.end()); //O(nlogn)
        int n = satisfaction.size();
        int* sums = new int[n+1];
        sums[n] = 0; //for the case that all satifaction values are negative
        //this ensures we will find the maximal value corresponding to discarding all dishes
        int temp;
        int counter;
        for (size_t i = 0; i < n; i++) {
            temp = 0;
            counter = 1;
            for (size_t j = i; j < n; j++) { //O(n^2)
                temp += satisfaction.at(j)*counter;
                counter++;
            }
            sums[i]=temp; 
            //std::cout << sums[i] << '\n';
        }

        int max_elem = *std::max_element(sums, sums+n+1); // O(n)
        return max_elem;
    }
};