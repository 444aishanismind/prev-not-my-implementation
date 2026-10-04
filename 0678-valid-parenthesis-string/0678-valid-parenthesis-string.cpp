#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> lefts;
        stack<int> stars;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                lefts.push(i);
            } else if (s[i] == '*') {
                stars.push(i);
            } else {
                if (!lefts.empty()) {
                    lefts.pop();
                } else if (!stars.empty()) {
                    stars.pop();
                } else {
                    return false;
                }
            }
        }

        while (!lefts.empty() && !stars.empty()) {
            if (lefts.top() < stars.top()) {
                lefts.pop();
                stars.pop();
            } else {
                return false;
            }
        }

        return lefts.empty();
    }
};