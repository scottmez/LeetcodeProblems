class Solution {
public:
    int romanToInt(string s) {
        /*
        I = 1
        V = 5
        X = 10
        L = 50
        C = 100
        D = 500
        M = 1000
        */
        map<char,int> rToI;
        rToI['I'] = 1;
        rToI['V'] = 5;
        rToI['X'] = 10;
        rToI['L'] = 50;
        rToI['C'] = 100;
        rToI['D'] = 500;
        rToI['M'] = 1000;

        int prevElem = 0;
        int elem = 0;
        int total = 0;
        char c = 'a';
        for (int i = 0; i < s.size(); i++) {
            c = s.at(i);
            elem = rToI[c];
            if (elem > prevElem) { //account for IV, IX, etc.
                total -= (prevElem * 2);
            }
            total += elem;
            prevElem = elem;
        }
        return total;
    }
};