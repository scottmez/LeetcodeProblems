class Solution {
public:
    bool isHappy(int n) {
        map<int,int> m;
        // the logic is that we want to stop if we get a result we've seen before, b/c that meens we're looping
        while (m.count(n) == 0) {
            int sum = 0;
            int temp = n;
            while (temp != 0) {
                int digit = temp % 10;
                int square = pow(digit, 2);
                sum += square;
                temp /= 10;
            }
            //cout << "n : " << n << endl;
            //cout << "sum : " << sum <<  endl;
            m[n] = sum;
            n = sum;
        }

        if (m.count(1) > 0) {
            return true;
        }

        return false;
    }
};