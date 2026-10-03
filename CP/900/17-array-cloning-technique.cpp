#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

// ! Observation
/*
* There we'll first check what is the element which is occuring the max no. of times let it be 'x'
* so greedly we can make the whole array equal to 'x' in minimum operations.

* arr = [0 1 3 3 7 0]
* Here x = 3 since its freq is maximum among all the elements
*
* So First we clone this array (Operations = 1)
* arr = [0 1 3 3 7 0]
* arr' = [0 1 3 3 7 0]

* Now we swap the 0, 1 of arr vector with 3, 3 of arr' (Operations = 2)
* arr = [3 3 3 3 7 0]
* again we clone this array (Operations = 1)

* arr = [3 3 3 3 7 0]
* arr' = [3 3 3 3 7 0]

* Now we swap the 7, 0 of arr vector with 3, 3 of arr' (Operations = 2)

* Total operations = 1 + 2 + 1 + 2 = 6 operations.

* We'll greely take max_freq ele x and keep incrementing our ops till max_freq < n 
* and when max_freq > n we'll check the remaining ele which need to be changed (i.e n - max_freq)
*/

ll solve() {
  ll n;
  cin >> n;
  
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  } 
  sort(a.begin(), a.end()); // * O(nlogn)
 
  // * Find the most frequent element
  ll max_freq = 1, count = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1])
      count++;
    else {
      max_freq = max(count, max_freq);
      count = 1;
    }
  }
  max_freq = max(count, max_freq); // * Final update
  
  // * max_freq will contain the count of ele which we want to all elements 
  // * should be equal to.
  ll ops = 0;
  while (max_freq < n) { 
    ops++; // * clone the array
    if (max_freq * 2 <= n) {
      ops += max_freq; // * swap all the copies
      max_freq = max_freq * 2; // * double the frequency
    } else{
      ops += (n - max_freq); // * swap only the remaining elements not equal to max_freq ele
      max_freq = n; // * Make max_freq to remaining n
    }
  }

  return ops;
}

// * Greedy Cloning & Swaps
// * TC = O(n)
// * SC = O(n) (Input array)
int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int ops = solve();
    cout << ops << "\n";
  }
  return 0;
}

// * Run the code
// * g++ --std=c++20 17-array-cloning-technique.cpp -o output && ./output

// * testcases
/*
6
1
1789
6
0 1 3 3 7 0
2
-1000000000 1000000000
4
4 3 2 1
5
2 5 7 6 3
7
1 1 1 1 1 1 1

*/

// * Output
/*
0
6
2
5
7
0
*/