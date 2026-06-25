/*
* Leetcode - 355
* Design Twitter
*
* https://leetcode.com/problems/design-twitter/
*/

// ! Amazon, Google, Microsoft, Meta, Apple, Uber, PayPal

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

typedef pair<int, int> pii;
typedef vector<int> vi;

// * ------------------------- Brute Force Approach -------------------------`
// * Using two min_heap
// * n - total number of followeeIds associated with the userId
// * m - maximum number of tweets by any user
// * N - total number of userIds
// * M - maximum number of followees for any user
// * TIME COMPLEXITY O(nlogn) 
// * SPACE COMPLEXITY O(N * m + N * M + n)
class TwitterBrute {
  int count;
  unordered_map<int, vector<vi>> tweet_map;
  unordered_map<int, unordered_set<int>> follow_map;
public:
  TwitterBrute() {
    count = 0;
  }
  
  void postTweet(int userId, int tweetId) {
    tweet_map[userId].push_back({count++, tweetId});
  }
  
  vector<int> getNewsFeed(int userId) {
    vector<int> res;

    // * Min Heap with custom comparator function
    const auto compare = [&](const vi &a, const vi &b) {
      return a[0] < b[0];
    };
    priority_queue<vi, vector<vi>, decltype(compare)> min_heap(compare);

    follow_map[userId].insert(userId); // * Follow himself
    // * Get all latest tweets from it's  
    for (int followeeId: follow_map[userId]) {
      if (tweet_map.count(followeeId)) {
        vector<vi> &tweets = tweet_map[followeeId];
        int idx = tweets.size() - 1;
        // * {count, tweetId, followeeId, tweet_index}
        min_heap.push({tweets[idx][0], tweets[idx][1], followeeId, idx});
      }
    }

    // * Get the remaining tweets
    while (!min_heap.empty() && res.size() < 10) {
      vi tweet = min_heap.top();
      min_heap.pop();

      res.push_back(tweet[1]); // * push the tweetId
      int idx = tweet[3];      // * tweet_index
      
      // * Check if we have more tweets from same followeeId in `tweet`
      if (idx > 0) {
        vi next_tweet = tweet_map[tweet[2]][idx - 1];
        min_heap.push({next_tweet[0], next_tweet[1], tweet[2], idx - 1});
      }
    }

    return res;
  }
   
  void follow(int followerId, int followeeId) {
    follow_map[followeeId].insert(followeeId);
  }
  
  void unfollow(int followerId, int followeeId) {
    follow_map[followeeId].erase(followeeId);
  }
};


// * ------------------------- Optimal Approach -------------------------`
// * Using two min_heap
// * n - total number of followeeIds associated with the userId
// * m - maximum number of tweets by any user
// * N - total number of userIds
// * M - maximum number of followees for any user
// * TIME COMPLEXITY O(nlogn) 
// * SPACE COMPLEXITY O(N * m + N * M + n)

class Twitter {
  int count;
  unordered_map<int, vector<pii>> tweet_map;
  unordered_map<int, unordered_set<int>> follow_map;
public:
  Twitter() {
    count = 0;
  }
  
  void postTweet(int userId, int tweetId) {
  }
  
  vector<int> getNewsFeed(int userId) {
   
  }
   
  void follow(int followerId, int followeeId) {
    follow_map[followerId].insert(followeeId);
  }
  
  void unfollow(int followerId, int followeeId) {
    follow_map[followerId].erase(followeeId);
  }
};

int main(void) {
  Twitter *obj = new Twitter();
  // obj->postTweet(userId,tweetId);
  // vector<int> param_2 = obj->getNewsFeed(userId);
  // obj->follow(followerId,followeeId);
  // obj->unfollow(followerId,followeeId);
  return 0;
}

