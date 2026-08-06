class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        unordered_map<int, int> rankMap;
        int rank = 1;
        
        for (int i = 0; i < sortedArr.size(); i++) {
            if (i > 0 && sortedArr[i] != sortedArr[i - 1]) {
                rank++;
            }
             rankMap[sortedArr[i]] = rank;
        }
        
        //Loop through the original array and replace each number with its rank from the map
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = rankMap[arr[i]];
        }
        
        return arr;
    }
};