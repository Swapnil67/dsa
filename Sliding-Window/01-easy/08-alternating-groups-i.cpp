/*
 * Leetcode - 3206
 * Alternating Groups I
 * 
 * There is a circle of red and blue tiles. You are given an array of integers colors. 
 * The color of tile i is represented by colors[i]:
 * 
 * - colors[i] == 0 means that tile i is red.
 * - colors[i] == 1 means that tile i is blue.
 * 
 * Every 3 contiguous tiles in the circle with alternating colors (the middle tile has a different color from its 
 * left and right tiles) is called an alternating group.
 * 
 * Return the number of alternating groups.
 * 
 * Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.
 * 
 * Example 1    :
 * Input        : colors = [1,1,1]
 * Output       : 0
 * 
 * Example 2    :
 * Input        : colors = [0,1,0,0,1]
 * Output       : 3
 *
 * https://leetcode.com/problems/alternating-groups-i/description/
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

int numberOfAlternatingGroups(vector<int> &colors) {
	int n = colors.size();
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (colors[i] != colors[(i + 1) % n] &&
				colors[(i + 1) % n] != colors[(i + 2) % n]) {
			ans += 1;
		}
	}
	return ans;
}

int main(void) {
	// * testcase 1
	// vector<int> colors = {1, 1, 1};

	// * testcase 2
	vector<int> colors = {0, 1, 0, 0, 1};

	cout << "Colors: ";
	printArr(colors);

	int ans = numberOfAlternatingGroups(colors);
	cout << "Alternating Groups: " << ans << endl;
	return 0;
}
 
// * Run the code
// * g++ --std=c++20 08-alternating-groups-i.cpp -o output && ./output
