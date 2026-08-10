

#include <bits/stdc++.h>
using namespace std;

class Twitter {
private:
     
        int time=0;
        unordered_map<int,unordered_set<int>> following;// userId -> set of followeeIds 
        unordered_map<int ,vector<pair<int,int>>> tweets;// userId -> list of {timestamp, tweetId}
        
    
    public:
    Twitter(){
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
 }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<vector<int>> maxHeap;
        unordered_set<int> usersToCheck = following[userId];
        usersToCheck.insert(userId);
        for(int user:usersToCheck){
            if (tweets.count(user) && !tweets[user].empty()) {
                int index = tweets[user].size() - 1; // Last element is the most recent
                int timestamp = tweets[user][index].first;
                int tweetId = tweets[user][index].second;
                
                maxHeap.push({timestamp, tweetId, user, index});
            }
        }
        while(!maxHeap.empty()&&res.size()<10){
            auto curr = maxHeap.top();
            maxHeap.pop();
            int tweetId=curr[1];
            int user=curr[2];
            int index=curr[3];
            res.push_back(tweetId);
            // If this user has an older tweet (index - 1 >= 0), push it into the heap
if (index - 1 >= 0) { 
    int nextIndex = index - 1; 
    int nextTimestamp = tweets[user][nextIndex].first;
    int nextTweetId = tweets[user][nextIndex].second;
    
    maxHeap.push({nextTimestamp, nextTweetId, user, nextIndex});
}
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) //followerId = The userId of the person clicking the "Follow" button.

//followeeId = The userId of the person being followed.
{
        if (followerId != followeeId){
            following[followerId].insert(followeeId);
        }
        
    }
    
    void unfollow(int followerId, int followeeId) {
       if (followerId != followeeId){
        following[followerId].erase(followeeId);
       } 
        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */