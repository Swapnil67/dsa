/*
 * Raspberries
 * 
 * You are given an array of integers a_1, a_2, ..., a_n and a prime/small integer k.
 * In one operation, you can select any element from the array and increment it by 1 (i.e., a_i = a_i + 1).
 * Find the minimum number of operations required to make the product of all elements in the array divisible by k.
 * 
 * Constraints:
 * 2 <= n <= 10^5
 * 2 <= k <= 5
 * 1 <= a_i <= 10
 * 
 * Example 1    :
 * Input        : nums = [7, 3], k = 3
 * Output       : 0
 * Explanation  : The product of the elements is 7 * 3 = 21, which is already divisible by 3. 
 *                Hence, 0 operations are needed.
 * 
 * Example 2    :
 * Input        : nums = [2, 3, 5, 29], k = 4
 * Output       : 1
 * Explanation  : You can increment 3 by 1 to make it 4. The array becomes [2, 4, 5, 29]. 
 *                The product becomes divisible by 4.
 *
 * https://codeforces.com/problemset/problem/1883/C
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

#define all(v) v.begin(), v.end()

// Macros to quickly declare and read a vector
#define VEC(type, name, size) vector<type> name(static_cast<size_t>(size))
#define READ_VEC(name) for(size_t i = 0; i < (name).size(); ++i) cin >> (name)[i]

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << "\n";
}

// ! Observation
/*
* If we want to check how much we should add in 'a[i]' to make it divisible by 'k' use following formula
* operations = k - a[i] % k;
* Eg: a[i] = 1, k = 4
* operations = 4 - 1 % 4 = 3      (So we need to add 3 in a[i] then our a[i] will become divisible by k.
*
* So we'll do this for all the elments and find the min_cost to make the product of whole array divisible by k.
* Only in k = 4 we've a edge case, Since 4 is not prime we can have some numbers which are divisible by 2
* then when they get multiplied the result will also be divisible by 4.
*
* Case 1 (even_count >= 2): 
*   Here we don't need any operations since multiple of 2 even numbers will always be divisible by 4.
* Case 2 (even_count == 1): 
*   Here we need only one operation we'll make any odd even, then we'll achieve case-1.
* Case 3 (even_count == 0): 
*   Here we need two operations we'll make any two odds even, then we'll achieve case-1.
*/

// ! Remainders and Parity
// * Time Complexity (TC): O(n) = O(2*10^5)
// * Space Complexity (SC): O(n) = O(2*10^5)
int main()
{
	ll t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k; // * Read the size of the array and the divisor k
    VEC(ll, a, n);
    READ_VEC(a);
    
		ll ans = INT_MAX; // * Initialize the minimum operations to a large value
		ll even_count = 0; // * Count of even numbers in the array
		for (ll i = 0; i < n; i++) {
			if (a[i] % 2 == 0)
				even_count++; // * Increment even_count if the element is even
			if (a[i] % k == 0)
				ans = 0; // * If any element is divisible by k, no operations are needed
			ans = min(ans, (k - a[i] % k)); // * Calculate the minimum operations needed
		}

		// * Special handling for k = 4
		if (k == 4) {
			if (even_count >= 2)
				ans = min(ans, 0LL); // * If there are at least two even numbers, no operations are needed
			else if (even_count == 1)
				ans = min(ans, 1LL); // * If there is one even number, one operation is needed
			else if (even_count == 0)
				ans = min(ans, 2LL); // * If there are no even numbers, two operations are needed
		}
		cout << ans << endl;
	}
	return 0;
}
 
// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output
