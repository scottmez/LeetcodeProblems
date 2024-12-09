class Solution {
public:
    string intToRoman(int num) {
        map<int, string> iToR;
        iToR[1] = "I";
        iToR[2] = "II";
        iToR[3] = "III";
        iToR[4] = "IV";
        iToR[5] = "V";
        iToR[6] = "VI";
        iToR[7] = "VII";
        iToR[8] = "VIII";
        iToR[9] = "IX";
        iToR[10] = "X";
        iToR[20] = "XX";
        iToR[30] = "XXX";
        iToR[40] = "XL";
        iToR[50] = "L";
        iToR[60] = "LX";
        iToR[70] = "LXX";
        iToR[80] = "LXXX";
        iToR[90] = "XC";
        iToR[100] = "C";
        iToR[200] = "CC";
        iToR[300] = "CCC";
        iToR[400] = "CD";
        iToR[500] = "D";
        iToR[600] = "DC";
        iToR[700] = "DCC";
        iToR[800] = "DCCC";
        iToR[900] = "CM";
        iToR[1000] = "M";
        iToR[2000] = "MM";
        iToR[3000] = "MMM";

        int thousands = num - (num % 1000);
        int hundreds = (num % 1000) - (num % 100);
        int tens = (num % 100) - (num % 10);
        int ones = (num % 10);
        string result = iToR[thousands] + iToR[hundreds] + iToR[tens] + iToR[ones];
        return result;
    }
};