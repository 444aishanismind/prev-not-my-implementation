#include <vector>
#include <map>

class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
      
        if (hand.size() % groupSize != 0) {
            return false;
        }

        
        std::map<int, int> countMap;
        for (int card : hand) {
            countMap[card]++;
        }

        
        for (auto& [card, count] : countMap) {
            if (count > 0) {
                int freq = count; // The number of groups this card must start
                
                // Check and consume the next 'groupSize' consecutive cards
                for (int i = 0; i < groupSize; i++) {
                    if (countMap[card + i] < freq) {
                        return false; // Missing a required consecutive partner or not enough count
                    }
                    countMap[card + i] -= freq;
                }
            }
        }

        return true;
    }
};