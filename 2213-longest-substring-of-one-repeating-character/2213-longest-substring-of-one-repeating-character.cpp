#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <queue>

using namespace std;

// Structure to represent a block of repeating characters
struct Block {
    int start;
    int end;
    char ch;

    bool operator<(const Block& other) const {
        return start < other.start;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        int k = queryCharacters.length();

        set<Block> blocks;
        priority_queue<int> maxHeap;
        unordered_map<int, int> freqMap;

        // Lambda to add a block's length to our tracking structures
        auto addLength = [&](int len) {
            maxHeap.push(len);
            freqMap[len]++;
        };

        // Lambda to remove a block's length lazily
        auto removeLength = [&](int len) {
            freqMap[len]--;
        };

        // Helper to get the length of a block
        auto getLength = [](const Block& b) {
            return b.end - b.start + 1;
        };

        // 1. Initialize blocks from the starting string
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            Block b = {i, j - 1, s[i]};
            blocks.insert(b);
            addLength(getLength(b));
            i = j;
        }

        vector<int> ans(k);

        // 2. Process each query
        for (int q = 0; q < k; ++q) {
            int idx = queryIndices[q];
            char newChar = queryCharacters[q];

            // Find the block containing 'idx' using upper_bound/prev
            auto it = blocks.upper_bound({idx, n, ' '});
            it--;
            Block curr = *it;

            // If the character is already the same, no change needed
            if (curr.ch == newChar) {
                while (!maxHeap.empty() && freqMap[maxHeap.top()] == 0) {
                    maxHeap.pop();
                }
                ans[q] = maxHeap.top();
                continue;
            }

            // Remove the old block's length
            blocks.erase(it);
            removeLength(getLength(curr));

            int start = curr.start;
            int end = curr.end;
            char oldChar = curr.ch;

            // Split and merge logic around 'idx'
            // Left leftover part
            if (start < idx) {
                Block leftBlock = {start, idx - 1, oldChar};
                blocks.insert(leftBlock);
                addLength(getLength(leftBlock));
            }

            // Right leftover part
            if (idx < end) {
                Block rightBlock = {idx + 1, end, oldChar};
                blocks.insert(rightBlock);
                addLength(getLength(rightBlock));
            }

            // Create the new single-character block for the updated index
            Block newBlock = {idx, idx, newChar};

            // Try merging with the right neighbor if it matches
            auto nextIt = blocks.upper_bound(newBlock);
            if (nextIt != blocks.end() && nextIt->ch == newChar) {
                newBlock.end = nextIt->end;
                removeLength(getLength(*nextIt));
                blocks.erase(nextIt);
            }

            // Try merging with the left neighbor if it matches
            auto prevIt = blocks.lower_bound(newBlock);
            if (prevIt != blocks.begin()) {
                prevIt--;
                if (prevIt->ch == newChar) {
                    newBlock.start = prevIt->start;
                    removeLength(getLength(*prevIt));
                    blocks.erase(prevIt);
                }
            }

            // Insert final merged/updated block
            blocks.insert(newBlock);
            addLength(getLength(newBlock));

            // Clean up the max heap top and record the answer
            while (!maxHeap.empty() && freqMap[maxHeap.top()] == 0) {
                maxHeap.pop();
            }
            ans[q] = maxHeap.top();
        }

        return ans;
    }
};