#include <vector>
#include <iostream>

class Twitter {
public:
  Twitter() {
  }
  
  void postTweet(int userId, int tweetId) {
  }
  
  std::vector<int> getNewsFeed(int userId) {
  }
   
  void follow(int followerId, int followeeId) {
  }
  
  void unfollow(int followerId, int followeeId) {
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

