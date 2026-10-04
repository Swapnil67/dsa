/*
 * Leetcode -  
 * Valid Number
 * 
 * “N” ranges [l…r] are given to you in the input 
 * 
 * You have to calculate that each point comes under how many ranges?
 * Once that is done you have to answer “Q” queries of the form [start...end] 
 * where you have to say how many integer points from [start...end] come under >=k ranges 
 * 
 * -> a[] of size 10^6 + 1 ; a[i] tells you how many times the point “i” comes under some range [l...r] 
 *
 * https://drive.google.com/file/d/1c0UJvKfE-z_tXvyBvOlZeVwiUoqCAYdQ/view
 * https://docs.google.com/document/d/14-PsuLsCtlYbaWodCTdD1K4poyLQ5BB2WyEWc4fA11c/edit?tab=t.0
*/

// ! OA
// ! Agoda

// ! Range Update Trick

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

// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)

vector<int> validNumber(vector<vector<int>> queries, int k) {
	vector<long long> p(100000+5, 0);
	// vector<int> p(15, 0); // * to debug

	int maxi = -1;
	// * First mark the ranges with 1 & -1
	for (auto query: queries) {
		int start = query[0], end = query[1];
		maxi = max(maxi, end);
		p[start] += 1;
		p[end + 1] += -1;
	}
	// * Do prefix sum on the array
	for (int i = 1; i <= maxi + 1; ++i) {
		p[i] = p[i] + p[i - 1];
	}
	// printArr(p); // * debug

	// * Now make a binary array 
	for (int i = 1; i <= maxi + 1; ++i) {
		if (p[i] >= k) p[i] = 1;
		else p[i] = 0;
	}
	// printArr(p); // * debug

	// * Not again do prefix sum on binary array
	for (int i = 1; i <= maxi + 1; ++i) {
		p[i] = p[i] + p[i - 1];
	}
	// printArr(p); // * debug

	// * Now find total for each query in O(1) time
	vector<int> ans;
	for (auto query: queries) {
		int s = query[0], e = query[1];
		ans.push_back(p[e] - p[s - 1]);
	}
	return ans;
}

int main(void) {
	int k = 2;
	vector<vector<int>> queries = {{2, 5}, {3, 8}};

	vector<int> ans = validNumber(queries, k);
	cout << "Valid Numbers: ";
	printArr(ans);
	return 0;
}

// * Run the code
// * g++ --std=c++20 38-valid-number.cpp -o output && ./output
