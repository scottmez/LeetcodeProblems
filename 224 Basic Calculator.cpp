class Solution {
    public:
     int calculate(string s) {
       int ans = 0;
       int num = 0;
       int sign = 1;
       stack<int> stack{{sign}};  //initialize stack with 1, stack just holds the sign 
       cout << stack.top() << endl;
       for (const char c : s)
         if (isdigit(c))
           num = num * 10 + (c - '0'); //0 * 10 is 0 so first num is okay, second increases base
         else if (c == '(')
           stack.push(sign);
         else if (c == ')')
           stack.pop();
         else if (c == '+' || c == '-') {
           ans += sign * num;
           sign = (c == '+' ? 1 : -1) * stack.top(); //multiply sign by stack top to get final sign of expression
           num = 0;
         }
       return ans + sign * num;
     }
   };