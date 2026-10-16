class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum>9*num)
        return "";
        int q = sum / 9;
        int r = sum % 9;
string ans;
ans.reserve(num);//ans e num space reserve kori
ans.append(q, '9');// q khana 9 added
if(r>0)
ans.push_back('0' + r);
ans.append(num-q-(r>0),'0');
 return ans;       
    }
};