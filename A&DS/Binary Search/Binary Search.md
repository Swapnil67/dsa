
a = [2, 5, 6, 10, 12, 18, 21]
### Basic Binary Search
$$
a[i] == x
$$

```cpp
int l = 0, r = n - 1;
while (l < r) {
	m = (l + r) / 2;
	if (a[m] < x) {
		l = m + 1;
	} else if (a[m] > x) {
		r = m - 1;
	} else {
		return m;
	}
}

// * TC = O(logn)
```

### Lower Bound
leftmost element greater than or equal to x.
$$
a[i] >= x
$$
For simplicity we'll put -INF & INF in our array, so our array becomes. following.
a = [-INF, 2, 5, 6, 10, 12, 18, 21, INF]

```cpp
int l = -1, r = n;
while (r > l + 1) { // * They should never become neighbour
	m = (l + r) / 2;
	if (a[m] >= x) {
		r = m;
	} else if (a[m] > x) {
		l = m;
	}
}

return r;

// * TC = O(logn)
```







