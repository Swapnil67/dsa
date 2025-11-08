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
 * https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
*/

#include <vector>
#include <iostream>

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << " ";
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << "]" << std::endl;
}

// * Print adjacency list
template <typename T>
void printAdjList(std::vector<T> &adj) {
  int n = adj.size();
  for (int i = 0; i < n; ++i) {
    std::cout << i << " -> ";
    printArr(adj[i]);
  }
}

std::vector<std::vector<std::string>> accountsMerge(std::vector<std::vector<std::string>> &accounts) {

}

int main(void) {
  // * testcase 1
  // std::vector<std::vector<std::string>> accounts = {{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
  //                                                 {"John", "johnsmith@mail.com", "john00@mail.com"},
  //                                                 {"Mary", "mary@mail.com"},
  //                                                 {"John", "johnnybravo@mail.com"}};

  // * testcase 2
  std::vector<std::vector<std::string>> accounts = {{"Gabe", "Gabe0@m.co", "Gabe3@m.co", "Gabe1@m.co"},
                                                    {"Kevin", "Kevin3@m.co", "Kevin5@m.co", "Kevin0@m.co"},
                                                    {"Ethan", "Ethan5@m.co", "Ethan4@m.co", "Ethan0@m.co"},
                                                    {"Hanzo", "Hanzo3@m.co", "Hanzo1@m.co", "Hanzo0@m.co"},
                                                    {"Fern", "Fern5@m.co", "Fern1@m.co", "Fern0@m.co"}};

  std::cout << "accounts: " << std::endl;
  for (auto &vec : accounts)
    printArr(vec);

  // int ans = removeStones(accounts);
  // std::cout << "Ans: " << ans << std::endl;
  return 0;
}


// * Run the code
// * g++ --std=c++20 21-accounts-merge.cpp -o output && ./output

