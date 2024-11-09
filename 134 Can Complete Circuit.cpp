class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cur_gas = 0;
        int index = -1;
        int j = 0;
        vector<int> validStarts;
        //find valid starting positions
        //since the starting position is unique we only need to use starting positions where gas[i] is greater than cost[i] 
        if (gas.size() == 1 && gas[0] >= cost[0]) { /* special case when only one starting position*/
            return 0;
        }
        for (int i = 0; i < gas.size(); i++) {
            if (gas[i] > cost[i]) {
                validStarts.push_back(i);
            }
        }
        
        //Run through valid starting positions
        for (int i = 0; i < validStarts.size(); i++) {
            index = validStarts[i];
            int j = (index + 1) % gas.size();
            cur_gas = gas[index] - cost[index];
            while (j != validStarts[i]) {
                cur_gas += gas[j] - cost[j];
                if (cur_gas < 0) {
                    goto endloop;
                }
                j = (j + 1) % gas.size();
            }
            //if we make it through the whole loop without breaking then we know that we can go to all gas stations from that starting index
            return index;
        endloop:
        }
        return -1;
    }
}; //Currently TLE