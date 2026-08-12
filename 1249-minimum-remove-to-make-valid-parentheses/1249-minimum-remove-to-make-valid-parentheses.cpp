class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
       
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty() && s[st.top()] == '(') {
                    st.pop(); 
                } else {
                    st.push(i); //js indices
                }
            }
        }
        
       
        unordered_set<int> invalidIndices;
        while (!st.empty()) {
            invalidIndices.insert(st.top());
            st.pop();
        }
        
     
        string result = "";
        for (int i = 0; i < s.length(); i++) {
            if (invalidIndices.find(i) == invalidIndices.end()) {
                result += s[i];
            }
        }
        
        return result;
    }
};