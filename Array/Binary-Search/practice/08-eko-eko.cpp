/*
 * Lumberjack Mirko needs to chop down M metres of wood. It is an easy job for him since he has a nifty new woodcutting
 * machine that can take down forests like wildfire. However, Mirko is only allowed to cut a single row of trees.
 * Mirko‟s machine works as follows: Mirko sets a height parameter H (in metres), and the machine raises a giant sawblade to that height and cuts off all tree 
 * parts higher than H (of course, trees not higher than H meters remain intact). Mirko then takes the parts that were cut off. 
 * For example, if the tree row contains trees with heights of 20, 15, 10, and 17 metres, and Mirko raises his sawblade to 15 metres, 
 * the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively, 
 * while Mirko will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).
 * Mirko is ecologically minded, so he doesn‟t want to cut off more wood than necessary. 
 * That‟s why he wants to set his sawblade as high as possible. Help Mirko find the maximum integer height of the sawblade that still allows him to cut off 
 * at least M metres of wood. 
 * 
*/

#include<iostream>
#include<vector>
using namespace std;

bool isPossibleHeight(vector<int> trees, int maxMetre, int mid) { 
  int requiredMetre = 0;

  for(int i=0; i<trees.size(); i++) {
    if(trees[i] > mid) {
      int diff = trees[i] - mid;
      requiredMetre = requiredMetre + diff;
    }
  }

  if(requiredMetre <= maxMetre) {
    return true;
  } else if(requiredMetre > maxMetre) {
    return false;
  }

}

int findMaxMetre(vector<int> trees, int maxMetre) {
  int ans = 0, maxi = -1;
  vector<int> maxarr;
  for(int i=0; i<trees.size(); i++) {
    maxi = max(trees[i], maxi);
  }
  int s = 0, e = maxi;
  while(s<=e) {
    int mid = s+(e-s)/2;
    if(isPossibleHeight(trees, maxMetre, mid)) {
      ans = mid;
      e = mid-1;
    } else {
      s = mid+1;
    }
  }

  return ans;
}

int main() {
  vector<int> trees;
  trees.push_back(4);
  trees.push_back(42);
  trees.push_back(40);
  trees.push_back(26);
  trees.push_back(46);

  int size = 5;
  int maxMetre = 20;

  int meter = findMaxMetre(trees, maxMetre);
  cout<<"meter: "<<meter;

  return 0;
}