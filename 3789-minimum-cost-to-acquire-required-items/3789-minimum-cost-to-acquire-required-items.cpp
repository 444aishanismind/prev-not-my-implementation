class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1, c2 = cost2, cb = costBoth;
        long long n1 = need1, n2 = need2;

       
        if (cb >= c1 + c2) {
            return (c1 * n1) + (c2 * n2);
        }

      
        if (n1 > n2) {
            return (cb * n2) + (n1 - n2) * min(c1, cb);
        }

        
        return (cb * n1) + (n2 - n1) * min(c2, cb);
    }
};