class Solution {
public:
    int minAddToMakeValid(string s) {
        int unmatched=0;
        stack<char>st;
        for(char c: s){
            if (c=='(')
            st.push(c);
        
        else{
            if(!st.empty())
            st.pop();
            else
            unmatched++;
        }}
        return unmatched+st.size();
        
    }
    
};