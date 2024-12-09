class Solution {
public:
    int candy(vector<int>& ratings) {
        int prev = 1; //keeps track of the last value used (helpful when incrementing)
        int total = 1; //keeps track of the running sum of total candy
        int mark1 = 0; //keeps track of the last location we incremented from
        int mark1val = 0;
        int mark2 = 0; //keeps track of the last location we started decrementing from
        int mark2val = 1;
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings.at(i) > ratings.at(i-1) ) {
                prev = prev + 1;
                mark1 = i;
                mark1val = prev;
                total += prev;
            }
            else if (ratings.at(i) < ratings.at(i-1) ) {
                if (prev == 1) {
                    if (mark2val + 1 >= mark1val) //do we need to increment mark1
                        total += (i - mark1) + prev; //yes
                    else {
                        total += (i - mark2) + prev; //no
                        mark2val += prev;
                    }
                }
                else {
                    mark2 = i;
                    mark2val = 1;
                    prev = 1;
                    total += prev;
                }
            }
            else { //(ratings.at(i) == ratings.at(i)) 
                //increment both marks since having equal ratings has properties of increasing and decreasing in the implementation
                prev = 1;
                mark1 = i;
                mark1val = 1;
                mark2 = i;
                mark2val = 1;
                total += prev;
            }
        }
        return total;
};