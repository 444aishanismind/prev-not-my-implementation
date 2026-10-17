bool comparePairs(pair<int, int> a, pair<int, int> b) {
    int sumA = 0;
    int tempA = a.first;
    while (tempA > 0) {
        sumA += tempA % 10;
        tempA /= 10;
    }

    int sumB = 0;
    int tempB = b.first;
    while (tempB > 0) {
        sumB += tempB % 10;
        tempB /= 10;
    }

    if (sumA != sumB) {
        return sumA < sumB;
    }
    return a.first < b.first;
}

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); i++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end(), comparePairs);
        
        int swaps = 0;
        for (int i = 0; i < nums.size(); i++) {
            pair<int, int> p = v[i];
            
            int index = p.second;
            
            if (i != index) {
                swaps++;
                swap(v[i], v[index]);
                i--;
            }
        }
        
        return swaps;
    }
};