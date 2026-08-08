class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;

for(int x:nums)

{

freq[x]++;

}
int n=nums.size();

vector<vector<int>>buckets(n+1);

for(auto&p :freq)

{

int num=p.first;

int f= p.second;

buckets[f].push_back(num);





}
vector<int> res;

res.reserve(k); 
for (int f=n; f>=1&& (int)res.size()<k;--f )
{
    for(int num :buckets[f])

{

res.push_back(num);

if((int)res.size()==k) break;

}

}

return res;
}

        
    
};