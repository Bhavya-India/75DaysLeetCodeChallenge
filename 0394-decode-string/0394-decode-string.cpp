class Solution {
public:
    string decodeString(string s) {

        stack<int> numStack;
        stack<string> strStack;

        string currentString = "";
        int currentNum = 0;

        for (char c : s) {

            if (isdigit(c)) {

                currentNum = currentNum * 10 + (c - '0');
            }

            else if (c == '[') {

                numStack.push(currentNum);
                strStack.push(currentString);

                currentNum = 0;
                currentString = "";
            }

            else if (c == ']') {

                int repeat = numStack.top();
                numStack.pop();

                string temp = currentString;

                currentString = strStack.top();
                strStack.pop();

                while (repeat--) {
                    currentString += temp;
                }
            }

            else {

                currentString += c;
            }
        }

        return currentString;
    }
};