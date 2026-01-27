/*
 * Meeting Rooms
 *
 * Given an array of meeting time interval objects consisting of start and end times [[start_1,end_1],[start_2,end_2],...]
 * (start_i < end_i), determine if a person could add all meetings to their schedule without any conflicts.
 * 
 * Note: (0,8),(8,10) is not considered a conflict at 8
 * 
 * Example 1:
 * Input: intervals = [(0,30),(5,10),(15,20)]
 * Output: false
 * 
 * Example 2:
 * Input: intervals = [(5,8),(9,15)]
 * Output: true
 * 
 * https://neetcode.io/problems/meeting-schedule/question
 * https://www.geeksforgeeks.org/problems/attend-all-meetings/1
*/

// ! Amazon, Google, Meta, Microsoft, Uber, Apple, Oracle

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

bool canAttendMeetings(vector<vector<int>> &intervals) {
  int n = intervals.size();
  if (n == 0)
    return true;

  // * Sort the intervals
  sort(begin(intervals), end(intervals), [](const vector<int> &a, const vector<int> &b)
       { return a[0] < b[0]; });

  for (int i = 1; i < n; ++i) {
    // cout << intervals[i][0] << " " << intervals[i - 1][1] << endl;
    if (intervals[i][0] < intervals[i - 1][1]) {
      return false;
    }
  }
  return true;
}

int main(void) {
  // * testcase 1
  vector<std::vector<int>> intervals1 = {{0, 30}, {5, 10}, {15, 20}};

  // * testcase 2
  vector<std::vector<int>> intervals2 = {{5, 8}, {9, 15}};

  // * testcase 3
  vector<std::vector<int>> intervals3 = {{5, 10}, {0, 4}};

  std::cout << "Ans: " <<  canAttendMeetings(intervals1) << std::endl;
  std::cout << "Ans: " << canAttendMeetings(intervals2) << std::endl;
  std::cout << "Ans: " << canAttendMeetings(intervals3) << std::endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 02-meeting-schedule.cpp -o output && ./output
