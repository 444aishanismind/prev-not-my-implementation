class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        unordered_map<char,int> pool;
        int n=s.length();
        for(char ch:s)
            pool[ch]++;

        string result="";
        string current="";
        solve(current,pool,target,0,false,result);
        return result;
        }
        private:

        bool solve(string& current,unordered_map<char,int>& pool,string& target, int i,bool greater,string& result)
        {int n=target.length();
            if(i==n){
            if(greater) {
                result=current;
                return true;}
            else
            return false;}
            for(char ch='a';ch<='z';ch++){
                if (pool[ch]==0) continue;
                if (!greater && ch<target[i] ) continue;
               current.push_back(ch);
                pool[ch]--;
                bool nextgreater=greater||(ch>target[i]);
                if(solve(current,pool, target, i + 1, nextgreater, result))
                return true;
                current.pop_back();
                pool[ch]++;


            }
            return false;

        }
        
    };
