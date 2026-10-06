class Solution {
public:
    int scoreOfParentheses(string s) {
        stack <int> st;
        st.push(0);
        for(char c:s){
            if (c=='('){
                st.push(0);

            }else{
            int score=st.top();
            st.pop();
            int val=(score==0)?1:2*score;
            st.top()+=val;
        }}
        return st.top();
        
    }
};