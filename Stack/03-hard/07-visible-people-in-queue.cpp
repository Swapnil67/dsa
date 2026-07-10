/*
 * Leetcode - 1944
 * Number of Visible People in a Queue
 * 
 * There are n people standing in a queue, and they numbered from 0 to n - 1 in left to right order. 
 * You are given an array heights of distinct integers where heights[i] represents the height of the ith person.
 * 
 * A person can see another person to their right in the queue if everybody in between is shorter than both of them. 
 * More formally, the ith person can see the jth person if i < j and 
 * min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1]).
 * 
 * Return an array answer of length n where answer[i] is the number of people the ith person 
 * can see to their right in the queue.

 * Example 1
 * * Input       : heights = [10,6,8,5,11,9]
 * * Output      : [3,1,2,1,1,0]
 * 
 * Example 2
 * * Input       : heights = [5,1,2,3,10]
 * * Output      : [4,1,1,1,0]
 * 
 * https://leetcode.com/problems/number-of-visible-people-in-a-queue/
*/

// ! Google, Meta, Microsoft, Amazon, Rippling, Oracle

#include <stack>
#include <vector>
#include <iostream>

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

// * ------------------------- APPROACH : Optimal Approach -------------------------`
// * Using Monotonic Stack
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
vector<int> canSeePersonsCount(vector<int>& heights) {
  int n = heights.size();
  vector<int> ans(n);

  int visible = 0;
  stack<int> st;
  for (int i = n - 1; i >= 0; --i) {
    // * If st.top() has smaller height than current then pop that height and incr visible count
    while (!st.empty() && st.top() < heights[i]) {
      st.pop();
      visible++;
    }

    // * If stack is not empty that means we have something who's height is greater than current height
    if (st.size())
      visible++;

    ans[i]= visible;
    st.push(heights[i]);

    // * reset the visible count
    visible = 0;
  }

  return ans;
}

int main() {
  vector<int> heights = {10, 6, 8, 5, 11, 9};
  cout << "Heights" << endl;
  printArr(heights);
  
  vector<int> ans = canSeePersonsCount(heights);
  printArr(ans);

  return 0;
}

// * run the code
// * g++ --std=c++17 07-visible-people-in-queue.cpp -o output && ./output
