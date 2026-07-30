/*
 * Leetcode - 323
 * Number of Connected Components
 * 
 * Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], 
 * where each entry edges[i] = [u, v] denotes an edge between vertices u and v. Count the number of connected components in the graph. 
 * Two vertices belong to the same connected component if there is a path between them.
 * 
 *
 * Example 1    :
 * Input        : edges = [[0, 1], [2, 1], [3, 4]], V = 5
 * Output       : 3
 *
 * Example 2    :
 * Input        : edges = [[0, 1], [6, 0], [2, 4], [2, 3], [3, 4]], V = 7
 * Output       : 10
 *
 * https://www.geeksforgeeks.org/problems/number-of-provinces/1
 */

// ! Amazon, Microsoft, Google

#include <vector>
#include <numeric>
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

class DSU {
	vector<int> parent;
	vector<int> rank;

public:
	DSU(int n) {
		parent.resize(n);
		rank.resize(n, 0);
		iota(begin(parent), end(parent), 0);
	}

	int find(int x) {
		if (x == parent[x])
			return x;
		return parent[x] = find(parent[x]);
	}

	bool Union(int x, int y) {
		int x_parent = find(x);
		int y_parent = find(y);
		if (x_parent == y_parent)
			return false;

		if (rank[x_parent] > rank[y_parent]) {
			parent[y_parent] = parent[x_parent];
		}
		else {
			parent[x_parent] = parent[y_parent];
			rank[y_parent]++;
		}
		return true;
	}
};

int countConnected(int V, vector<vector<int>> &edges) {
	DSU ds(V);
	int components = V;
	for (auto &it : edges) {
		int x = it[0], y = it[1];
		components -= ds.Union(x, y);
	}
	return components;
}

int main(void) {
	// * testcase 1
	int v = 5;
	vector<vector<int>> edges = {{0, 1}, {2, 1}, {3, 4}};

	// * testcase 2
	// int v = 7;
	// vector<vector<int>> edges = {{0, 1}, {6, 0}, {2, 4}, {2, 3}, {3, 4}};

	cout << "Edges" << endl;
	for (auto &vec: edges)
		printArr(vec);

	int ans = countConnected(v, edges);
	cout << "Number of Connected Components " << ans << endl;

	return 0;
}

// * Run the code
// * g++ --std=c++20 64-no-of-connected-components-in-udg.cpp -o output && ./output
