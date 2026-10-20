class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> currentsegment;
        solve(s, 0, 0, currentsegment, result); 
        return result;
    }

private:
    void solve(string& s, int startindex, int dotsPlaced, vector<string>& currentsegment, vector<string>& result) {
        
        if (dotsPlaced == 3) {
            string lastSegment = s.substr(startindex);
            
        
            if (isValid(lastSegment)) {
                currentsegment.push_back(lastSegment);
                
            
                string ip = "";
                for (int i = 0; i < currentsegment.size(); i++) {
                    ip += currentsegment[i];
                    if (i < currentsegment.size() - 1) {
                        ip += ".";
                    }
                }
                result.push_back(ip);
                
            
                currentsegment.pop_back();
            }
            return;
        }

        
        for (int len = 1; len <= 3; len++) {
            if (startindex + len >= s.length()) {
                break;
            }
            
            string chunk = s.substr(startindex, len);
            
            if (!isValid(chunk)) {
                continue;
            }
            
            currentsegment.push_back(chunk);
            solve(s, startindex + len, dotsPlaced + 1, currentsegment, result);
            currentsegment.pop_back();
        }
    }

   
    bool isValid(string& chunk) {
        if (chunk.length() > 1 && chunk[0] == '0') {
            return false;
        }
        if(chunk.empty()||chunk.length()>3)
        return false;
        int val = stoi(chunk);
        return val >= 0 && val <= 255;
    }
};