/*
 * Leetcode - 2115
 * Find All Possible Recipes from Given Supplies
 * 
 * You are given a list of bombs. The range of a bomb is defined as the area where its effect can be felt. 
 * This area is in the shape of a circle with the center as the location of the bomb.

 * The bombs are represented by a 0-indexed 2D integer array bombs where bombs[i] = [xi, yi, ri]. xi and yi 
 * denote the X-coordinate and Y-coordinate of the location of the ith bomb, whereas ri denotes the 
 * radius of its range.

 * You may choose to detonate a single bomb. When a bomb is detonated, it will detonate all bombs that
 * lie in its range. These bombs will further detonate the bombs that lie in their ranges.
 * 
 * Given the list of bombs, return the maximum number of bombs that can be detonated if you are allowed 
 * to detonate only one bomb.
 * 
 * Example 1  :
 * Input      : recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
 * Output     : ["bread"]

 * Example 2  :
 * Input      : recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], 
 *              supplies = ["yeast","flour","meat"]
 * Output     : ["bread","sandwich"]
 
 * Example 3  :
 * Input      : recipes = ["sandwich", "bread","burger"], 
 *              ingredients = [["bread", "meat"], ["yeast", "flour"], ["sandwich", "meat", "bread"]], 
 *              supplies = ["yeast","flour","meat"]
 * Output     : ["bread","sandwich"]
 
 * https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/
 */

// ! Google

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << " ";
    if (i != n - 1)
      cout << ", ";
  }
  cout << "]" << endl;
}

void printAdjList(unordered_map<string, vector<int>> &adj) {
  for (auto &[key, vec] : adj) {
    cout << key << " -> ";
    printArr(vec);
  }
}

typedef vector<string> vs;


// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * n = num of recipes
// * m = num of ingredients
// * s = num of supplies
// * TIME COMPLEXITY O(n^2 * m)
// * SPACE COMPLEXITY O(n + s)
vector<string> bruteForce(
    vector<string> &recipes,
    vector<string> &supplies,
    vector<vector<string>> &ingredients)
{
  // * Add all the supplies to set
  unordered_set<string> supplies_set(begin(supplies), end(supplies));

  vector<string> ans;
  
  int recipes_cnt = recipes.size();
  vector<bool> cooked(recipes_cnt, false);
  int count = recipes_cnt;
  while (count--) { // * O(n)
    for (int i = 0; i < recipes_cnt; ++i) {
      if (cooked[i])
        continue;

      string recipe = recipes[i];

      // * check if all ingredients are available in supplies
      bool can_make = true;
      for (auto &i : ingredients[i]) { // * O(m)
        if (!supplies_set.count(i)) {
          // cout << i << endl;
          can_make = false;
          break;
        }
      }

      // cout << recipe << ' ' << can_make << endl;
      // * If we can cook recipe then add it to the supplies set
      if (can_make) {
        cooked[i] = true;
        ans.push_back(recipes[i]);
        supplies_set.insert(recipe);
      }

    }
  }

  return ans;
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * Topological Sort (Kahn's Algo)
// * n = num of recipes
// * m = num of ingredients
// * s = num of supplies
// * TIME COMPLEXITY O(n * m)
// * SPACE COMPLEXITY O(n + s)
vector<string> findAllRecipes(
    vector<string> &recipes,
    vector<string> &supplies,
    vector<vector<string>> &ingredients)
{
  // * Add all the supplies to set
  unordered_set<string> supplies_set(begin(supplies), end(supplies));
  unordered_map<string, vector<int>> adj;

  // * Create an adj list of ingredients who are dependent on recipe
  int recipes_cnt = recipes.size();
  vector<int> indegree(recipes_cnt, 0);
  for (int i = 0; i < recipes_cnt; ++i) { // * O(n)
    for (auto &ing : ingredients[i]) { // * O(m)
      // * If ingredient is not found in supplies that means this recipe depends on `ing`
      if (!supplies_set.count(ing)) {
        // * ing -> recipe[i]
        indegree[i]++;
        adj[ing].push_back(i);
      }
    }
  }
  // * For Debugging
  // printAdjList(adj);
  // cout << "Indegree" << endl;
  // printArr(indegree);

  // * Kahn's Algo 
  // * Make those recipes first who have zero dependency 
  queue<int> q;
  for (int i = 0; i < recipes_cnt; ++i) {
    if (indegree[i] == 0)
      q.push(i);
  }

  vector<string> ans;
  while (!q.empty()) { // * O(n) ~ Worst case all recipes
    int u = q.front();
    q.pop();

    string recipe = recipes[u];
    ans.push_back(recipe);
    // cout << recipe << endl;

    for (auto &v: adj[recipe]) {
      indegree[v]--;
      if (indegree[v] == 0) {
        q.push(v);
      }
    }
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // vector<string> recipes = {"bread"}, supplies = {"yeast", "flour", "corn"};
  // vector<vector<string>> ingredients = {{"yeast", "flour"}};

  // * testcase 2
  // vector<string> recipes = {"bread", "sandwich"}, supplies = {"yeast", "flour", "meat"};
  // vector<vector<string>> ingredients = {{"yeast", "flour"}, {"bread", "meat"}};

  // * testcase 3
  // vector<string> recipes = {"bread", "sandwich", "burger"}, supplies = {"yeast", "flour", "meat"};
  // vector<vector<string>> ingredients = {{"yeast", "flour"}, {"bread", "meat"}, {"sandwich", "meat", "bread"}};

  // * testcase 4
  vector<string> recipes = {"sandwich,", "bread", "burger"}, supplies = {"yeast", "flour", "meat"};
  vector<vector<string>> ingredients = {{"bread", "meat"}, {"yeast", "flour"}, {"meat", "bread"}};

  cout << "Recipes: ";
  printArr(recipes);
  cout << "Supplies: ";
  printArr(supplies);
  cout << "------------ ingredients -------------" << endl;
  for (auto &vec : ingredients)
    printArr(vec);

  // vector<string> ans = bruteForce(recipes, supplies, ingredients);
  vector<string> ans = findAllRecipes(recipes, supplies, ingredients);

  cout << "Cooked Foods: ";
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 49-find-all-possible-recipes-from-given-supplies.cpp -o output && ./output

 