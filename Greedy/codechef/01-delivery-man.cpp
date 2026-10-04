/*
 * Codechef
 * Delivery Man
 * 
 * Andy and Bob are the only two delivery men of Pizza-chef store. Today, the store received N orders. 
 * It's known that the amount of tips may be different when handled by different delivery man. 
 * More specifically, if Andy takes the ith order, he would be tipped Ai dollars and if Bob takes 
 * this order, the tip would be Bi dollars.
 * 
 * They decided that they would distribute the orders among themselves to maximize the total tip money. 
 * One order will be handled by only one person. Also, due to time constraints Andy cannot take more 
 * than X orders and Bob cannot take more than Y orders. It is guaranteed that X + Y is greater 
 * than or equal to N, which means that all the orders can be handled by either Andy or Bob.
 * 
 * Please find out the maximum possible amount of total tip money after processing all the orders.
 * 
 * Example 1    :
 * Input        : A = [1 2 3 4 5], B = [5 4 3 2 1], X = 3, Y = 3
 * Output       : 21
 * Explanation  : Bob will take the first three orders (or the first two) and Andy will 
 *                take the rest (of course).
 *
 * https://www.codechef.com/problems/TADELIVE
 * https://drive.google.com/file/d/10SqF88hqJ2-3XoGQ7Nc9svrOt0kaHAc0/view
 * https://docs.google.com/document/d/1G_lYkIlrHg-Jt9P2o5Xdhk80CZu2EexwbJcOoB_w3BI/edit?tab=t.0
*/

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

// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(N)
int getMaxTip(vector<int> &a, vector<int> &b, int x, int y) {
  int n = a.size();
  typedef long long ll;

  // * base sum = Bob does all orders
  ll base_sum = 0;
  vector<ll> diff(n);
  for (int i = 0; i < n; ++i) {
    base_sum += b[i];
    diff[i] = a[i] - b[i];
  }
  cout << "base_sum: " << base_sum << endl;

  // * sort differences in descending order
  sort(diff.rbegin(), diff.rend());
  printArr(diff);

  // * compute prefix sums of top k deltas
  vector<ll> prefix(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    prefix[i] = prefix[i - 1] + diff[i - 1];
  }
  printArr(prefix);

  // * calculate max tip
  ll max_tip = 0;
  for (int i = 0; i <= n; ++i) {
    // * i = number of tasks Andy takes
    // * n - i = number of tasks bob takes
    if (i <= x && (n - i) <= y) {
      ll total = base_sum + prefix[i];
      cout << i << " " << (n - i) << " -> " << total  << endl;
      max_tip = max(max_tip, total);
    }
  }

  return max_tip;
}

int main(void) {
  // * testcase 1
  int X = 3, Y = 3;
  vector<int> andy = {1, 2, 3, 4, 5};
  vector<int> bob = {5, 4, 3, 2, 1};

  cout << "Andy: ";
  printArr(andy);
  cout << "Bob: ";
  printArr(bob);

  int tip = getMaxTip(andy, bob, X, Y);
  cout << "Maximum tip: " << tip << endl;
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 01-delivery-man.cpp -o output && ./output
