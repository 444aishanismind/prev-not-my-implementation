class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> output(m - 1, "." + string(n - 1, '#'));//m-1 bar . er por n-1 khana # bosate hobe 
        
        output.push_back(string(n, '.'));
        
        return output;
    }
};