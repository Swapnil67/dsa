/*
 * Job Sequencing Problem
 * 
 * You are given a 'Nx3' 2-D array 'Jobs' describing 'N' jobs where 'Jobs[i][0]' denotes the id of 'i-th' job,
 * 'Jobs[i][1]' denotes the deadline of 'i-th' job, and 'Jobs[i][2]' denotes the profit associated with 'i-th job'.
 * 
 * You will make a particular profit if you complete the job within the deadline associated with it. 
 * Each job takes 1 unit of time to be completed, and you can schedule only one job at a particular time.
 * 
 * Return the number of jobs to be done to get maximum profit.
 * 
 * If a particular job has a deadline 'x', it means that it needs to be completed at any time before 'x'.
 * Assume that the start time is 0.
 * 
 * https://www.naukri.com/code360/problems/job-sequencing-problem_1169460
*/

// ! Amazon, Microsoft, Google, Flipkart, Expedia, Morgan Stanley

#include <vector>
#include <iostream>
#include <algorithm>

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

vector<int> jobScheduling(vector<vector<int>> &jobs) {
  int n = jobs.size();
  sort(begin(jobs), end(jobs), [&](const auto &j1, const auto &j2) {
    return j1[2] > j2[2];
  });

  // * For Debugging
  // cout << "Sorted By Profit Jobs\n";
  // for (auto &vec : jobs)
  //   printArr(vec);

  vector<int> tasks(n + 1, -1);
  int max_profit = 0, jbs = 0;
  for (auto &j: jobs) {
    int start = j[0], end = j[1], profit = j[2];
    while (end > 0) {
      if (tasks[end] == -1) {
        jbs += 1;
        tasks[end] = profit;
        max_profit += profit;
        break;
      }
      end--;
    }
  } 

  // printArr(tasks);

  return {jbs, max_profit};
}

int main(void) {
  // * testcase 1
  // vector<vector<int>> jobs = {{1, 1, 30}, {2, 3, 40}, {3, 2, 10}};
  
  // * testcase 2
  vector<vector<int>> jobs = {{1, 1, 40}, {2, 1, 50}, {3, 1, 60}};

  cout << "Jobs\n";
  for (auto &vec : jobs)
    printArr(vec);

  vector<int> ans = jobScheduling(jobs);
  cout << "Answer: ";
  printArr(ans);

  return 0;
}
 
// * Run the code
// * g++ --std=c++17 11-job-sequencing-problem.cpp -o output && ./output
