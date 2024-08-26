/*
 * Push Dominoes
 * There are n dominoes in a line, and we place each domino vertically upright. In the beginning, 
 * we simultaneously push some of the dominoes either to the left or to the right.
 * 
 * dominoes[i] = 'L', if the ith domino has been pushed to the left,
 * dominoes[i] = 'R', if the ith domino has been pushed to the right, and
 * dominoes[i] = '.', if the ith domino has not been pushed.
 * 
 * Example 1:
 * Input: dominoes = "RR.L"
 * Output: "RR.L"
 * 
 * Example 2:
 * Input: dominoes = ".L.R...LR..L.."
 * Output: "LL.RR.LLRRLL.."

 * https://leetcode.com/problems/push-dominoes/description/
 * https://www.naukri.com/code360/problems/dominoes-game_2657398
*/

#include<queue>
#include<iostream>

void pushDominoes(std::string &dominoes) {
  int n = dominoes.size();

  std::queue<std::pair<char, int>> que;
  for (int i = 0; i < n; ++i) {
    if (dominoes[i] != '.')
      que.push({dominoes[i], i});
  }

  while(!que.empty()) {
    std::pair<char, int> t = que.front();
    que.pop();
    int idx = t.second;
    if (t.first == 'L') {
      if (idx > 0 && dominoes[idx - 1] == '.') {
        dominoes[idx - 1] = 'L';
        que.push({'L', idx - 1});
      }
    }
    else {
      // * R
      if (idx + 1 < n && dominoes[idx + 1] == '.') {
        if (idx + 2 < n && dominoes[idx + 2] == 'L') {
          // * stuck position
          que.pop();
        }
        else {
          dominoes[idx + 1] = 'R';
          que.push({'R', idx + 1});
        }
      }
    }
  }
}

int main() {
  std::string dominoes = ".L.R...LR..L..";
  std::cout<<" ---------- Before Domino ---------- "<<std::endl;
  std::cout << dominoes << std::endl;
  pushDominoes(dominoes);
  std::cout << " ---------- After Domino ---------- " << std::endl;
  std::cout << dominoes << std::endl;
}

// * run the code
// * g++ --std=c++17 09-push-dominoes.cpp -o output && ./output