/*
 * Leetcode - 721
 * Accounts Merge
 * 
 * Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name,
 * and the rest of the elements are emails representing emails of the account.
 * 
 * Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email
 * to both accounts. Note that even if two accounts have the same name, they may belong to different people as people 
 * could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have 
 * the same name.
 * 
 * After merging the accounts, return the accounts in the following format: the first element of each account is the name,
 * and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

 * Example 1  :
 * Input      : accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],
 *                         ["John","johnsmith@mail.com","john00@mail.com"],
 *                         ["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
 * Output     : [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],
 *              ["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
 * 
 * Example 2  :
 * Input      : [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],
 *              ["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],
 *              ["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
 * Output     : [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],
 *              ["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],
 *              ["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
 * 
 * https://neetcode.io/problems/accounts-merge/question
 * https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
*/

#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// ! Amazon, Google, Meta, Microsoft, Apple, Rippling, PhonePe

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


int find(int x, vector<int> &parent) {
  if (x == parent[x])
    return x;
  return parent[x] = find(parent[x], parent);
}

void Union(int x, int y, vector<int> &rank, vector<int> &parent) {
  int x_parent = find(x, parent);
  int y_parent = find(y, parent);

  if (x_parent == y_parent)
    return;

  if (rank[x_parent] > rank[y_parent]) {
    parent[y_parent] = parent[x_parent];
  }
  else if (rank[x_parent] < rank[y_parent]) {
    parent[x_parent] = parent[y_parent];
  } 
  else {
    parent[x_parent] = parent[y_parent];
    rank[y_parent]++;
  }
}

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
  int n = accounts.size();

  // * 1. Initialize rank and parent vectors
  vector<int> rank(n + 1, 1);
  vector<int> parent(n + 1);
  iota(begin(parent), end(parent), 0);

  // * 2. Mark parents for each mail id
  unordered_map<string, int> mail_parent_mp;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < accounts[i].size(); ++j) {
      string mail = accounts[i][j];
      if (!mail_parent_mp.count(mail)) {
        mail_parent_mp[mail] = i;
      }
      else {
        Union(i, mail_parent_mp[mail], rank, parent);
      }
    }
  }
  // * For Debugging
  for (auto &it: mail_parent_mp) {
    cout << it.first << ": " << it.second << endl;
  }
  
  // * 3. merge mail of same parents
  vector<vector<string>> merged_mails(n);
  for (auto &it: mail_parent_mp) {
    string mail = it.first;
    int ultimate_parent = find(it.second, parent);
    merged_mails[ultimate_parent].push_back(mail);
    cout << mail << " -> " << ultimate_parent << endl;
  }

  // * 4. Create answer vector
  vector<vector<string>> ans;
  for (int i = 0; i < n; ++i) {
    if (merged_mails[i].size() == 0)
      continue;

    // * create a sorted mail array for each account
    vector<string> temp;
    temp.push_back(accounts[i][0]);
    sort(begin(merged_mails[i]), end(merged_mails[i]));
    temp.insert(temp.end(), begin(merged_mails[i]), end(merged_mails[i]));
    ans.push_back(temp);
  }
  return ans;
}

int main(void) {
  // * testcase 1
  vector<vector<string>> accounts = {
      {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
      {"John", "johnsmith@mail.com", "john00@mail.com"},
      {"Mary", "mary@mail.com"},
      {"John", "johnnybravo@mail.com"}};

  // * testcase 2
  // vector<vector<string>> accounts = {
  //     {"Gabe", "Gabe0@m.co", "Gabe3@m.co", "Gabe1@m.co"},
  //     {"Kevin", "Kevin3@m.co", "Kevin5@m.co", "Kevin0@m.co"},
  //     {"Ethan", "Ethan5@m.co", "Ethan4@m.co", "Ethan0@m.co"},
  //     {"Hanzo", "Hanzo3@m.co", "Hanzo1@m.co", "Hanzo0@m.co"},
  //     {"Fern", "Fern5@m.co", "Fern1@m.co", "Fern0@m.co"}};

  cout << "accounts: " << endl;
  for (auto &vec : accounts)
  printArr(vec);
  
  vector<vector<string>> ans = accountsMerge(accounts);
  cout << "Merged accounts: " << endl;
  for (auto &vec : ans)
    printArr(vec);
    
  return 0;
}


// * Run the code
// * g++ --std=c++20 21-accounts-merge.cpp -o output && ./output

/*
 * Initial Object
 * [
 *   0 -> ["John","johnsmith@mail.com","john_newyork@mail.com"],
 *   1 -> ["John","johnsmith@mail.com","john00@mail.com"],
 *   2 -> ["Mary","mary@mail.com"],
 *   3 -> ["John","johnnybravo@mail.com"]
 * ]

 * Create a map for each email & update parent of similar mails
 * {email: index}
 * {
 *   johnsmith@mail.com: 0,
 *   john_newyork@mail.com: 0,
 *   john00@mail.com: 1,
 *   mary@mail.com: 2,
 *   johnnybravo@mail.com: 3 
 * }

 * Parent vector = [
 *  {
 *      0: 0,
 *      1: 0,
 *      2: 2,
 *      3: 3,
 *    }
 * ]

  * Create a merged mails array for each index
  * mails = [
  *   0 -> [johnsmith@mail.com, john_newyork@mail.com, john00@mail.com],
  *   2 -> [mary@mail.com],
  *   3 -> [johnnybravo@mail.com],
  * ] 
  * 
 * 
*/